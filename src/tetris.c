/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** tetris
*/

#include "../include/my.h"

tetrimino_t *get_random(game_t *tetris)
{
    tetrimino_t *next = malloc(sizeof(tetrimino_t));
    int random = rand() % tetris->nb_shapes;
    int i = 0;

    while (tetris->shapes[random]->error == 1)
        random = rand() % tetris->nb_shapes;
    next->colour = tetris->shapes[random]->colour;
    next->height = tetris->shapes[random]->height;
    next->name = tetris->shapes[random]->name;
    next->posx = tetris->map_width / 2 - tetris->shapes[random]->width / 2;
    next->posy = tetris->shapes[random]->posy;
    next->width = tetris->shapes[random]->width;
    next->shape = malloc(sizeof(char *) * (next->height + 2));
    for (; tetris->shapes[random]->shape[i] != NULL; i++)
        next->shape[i] = my_strdup(tetris->shapes[random]->shape[i]);
    next->shape[i] = NULL;
    return next;
}

void init_tetris(game_t *tetris)
{
    tetris->actual_tetrimino = get_random(tetris);
    tetris->next_tetrimino = get_random(tetris);
}

void make_pause(game_t *tetris, char *str)
{
    int c;
    clock_t prints = clock();

    while (1) {
        c = wgetch(tetris->win->game);
        clear();
        mvprintw(LINES / 2, COLS / 2 - my_strlen(str) / 2, str);
        refresh();
        if (c != ERR)
            break;
    }
    clear();
}

void receive_input(game_t *tetris, clock_t *prints)
{
    int c = print_windows(tetris);
    if (c == tetris->key_binding->key_quit)
        terminate_game(tetris);
    if (c == tetris->key_binding->key_drop) {
        tetris->actual_tetrimino->posy++;
        put_tetrismap(tetris);
    }
    if (c == tetris->key_binding->key_left)
        check_if_left(tetris);
    if (c == tetris->key_binding->key_right)
        check_if_right(tetris);
    if (c == tetris->key_binding->key_turn)
        rotate(tetris);
    if (c == tetris->key_binding->key_pause)
        make_pause(tetris, "PAUSE - Press any key to continue");
    *prints = clock();
}

void play_tetris(game_t *tetris)
{
    tetris->time = clock();
    clock_t prints = clock();
    int c = 0;

    while (1) {
        check_fullrow(tetris);
        if (check_lost(tetris) == 1)
            free_new_game(tetris);
        if ((double)(clock() - prints) / CLOCKS_PER_SEC > 0.05)
            receive_input(tetris, &prints);
        if ((double)(clock() - tetris->time) / CLOCKS_PER_SEC > 1 -
            (tetris->level * 0.1)) {
            check_if_lastrow(tetris);
            tetris->actual_tetrimino->posy++;
            put_tetrismap(tetris);
            tetris->time = clock();
        }
    }
}
