/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** free_game
*/

#include "../include/my.h"

void free_tetrimino(tetrimino_t *tetrimino)
{
    for (int i = 0; tetrimino->shape[i] != NULL; i++)
        free(tetrimino->shape[i]);
    free(tetrimino->shape);
    free(tetrimino);
}

void free_actual(game_t *tetris)
{
    free_tetrimino(tetris->actual_tetrimino);
}

void free_map(char **map, int **colors)
{
    for (int i = 0; map[i] != NULL; i++) {
        if (colors != NULL)
            free(colors[i]);
        free(map[i]);
    }
    if (colors != NULL)
        free(colors);
    free(map);
}

void terminate_game(game_t *tetris)
{
    make_pause(tetris, "Game Over");
    free_map(tetris->map, tetris->colors);
    free_actual(tetris);
    free_tetrimino(tetris->next_tetrimino);
    free(tetris->key_binding);
    for (int i = 0; i < tetris->nb_shapes; i++) {
        free_tetrimino(tetris->shapes[i]);
        free(tetris->shapes[i]->name);
    }
    free(tetris->shapes);
    kill_windows(tetris);
    free(tetris->win);
    free(tetris);
    endwin();
    exit(0);
}

void free_new_game(game_t *tetris)
{
    reset_map(tetris);
    free_actual(tetris);
    tetris->actual_tetrimino = tetris->next_tetrimino;
    tetris->next_tetrimino = get_random(tetris);
    tetris->score = 0;
    tetris->lines = 0;
    tetris->level = 1;
    tetris->time = clock();
    tetris->timerr = 0;
    tetris->prev_lines = 0;
}
