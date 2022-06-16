/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** game
*/

#include "../include/my.h"

void print_next(game_t *tetris, int i, int j)
{
    if (tetris->next_tetrimino->shape[i][j] == '*') {
        wmove(tetris->win->next, (tetris->max_size -
        tetris->next_tetrimino->height) / 2 + i + 1, (tetris->max_size /
        2 - tetris->next_tetrimino->width / 2 + j) * 2 + 1);
        wattr_on(tetris->win->next,
        COLOR_PAIR(tetris->next_tetrimino->colour), NULL);
        wprintw(tetris->win->next, "%c",
        tetris->next_tetrimino->shape[i][j]);
        wattr_off(tetris->win->next,
        COLOR_PAIR(tetris->next_tetrimino->colour), NULL);
    }
}

void print_next_win(game_t *tetris)
{
    wclear(tetris->win->next);
    wrefresh(tetris->win->next);
    wresize(tetris->win->next, tetris->max_size + 2, tetris->max_size * 2 + 2);
    mvwin(tetris->win->next, (LINES - tetris->map_height) / 2,
    (COLS - tetris->map_width * 2 + 3) / 2 + tetris->map_width * 2 + 6);
    wborder(tetris->win->next, (int)'|', (int)'|', (int)'-', (int)'-',
    (int)'/', (int)'\\', (int)'\\', (int)'/');
    for (int i = 0; tetris->next_tetrimino->shape[i] != NULL; i++) {
        for (int j = 0; tetris->next_tetrimino->shape[i][j] != '\0'; j++)
            print_next(tetris, i, j);
    }
    wrefresh(tetris->win->next);
}

void calculate_score(game_t *tetris)
{
    int index = tetris->lines - tetris->prev_lines;
    if (tetris->lines == 10) {
        tetris->level++;
        tetris->lines = 0;
    }
    if (index < 0)
        index = 0;
    else if (index > 4)
        index = 4;
    int scores[] = {0, 40, 100, 300, 1200};
    tetris->score += scores[index];
    tetris->prev_lines = tetris->lines;
    if (tetris->score > tetris->highscore)
        tetris->highscore = tetris->score;
}

int print_windows(game_t *tetris)
{
    clear();
    calculate_score(tetris);
    if (COLS < 60 + tetris->max_size * 2 + 10 ||
    LINES < tetris->map_height + 3) {
        mvprintw(LINES / 2, COLS / 2 - 8, "Window too small");
        refresh();
    } else {
        print_game_win(tetris);
        print_info_win(tetris);
        if (tetris->show_next = true)
            print_next_win(tetris);
    }
    int c = wgetch(tetris->win->game);
    return c;
}
