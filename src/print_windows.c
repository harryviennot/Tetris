/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** print_windows
*/

#include "../include/my.h"

void kill_windows(game_t *tetris)
{
    wborder(tetris->win->game, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(tetris->win->game);
    wborder(tetris->win->next, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(tetris->win->next);
    wborder(tetris->win->info, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(tetris->win->info);
    delwin(tetris->win->game);
    delwin(tetris->win->next);
    delwin(tetris->win->info);
}

void print_shape(game_t *tetris, int i)
{
    for (int j = 0; tetris->actual_tetrimino->shape[i][j] != '\0'; j++) {
        if (tetris->actual_tetrimino->shape[i][j] == '*') {
            wmove(tetris->win->game, tetris->actual_tetrimino->posy + i + 1,
            (tetris->actual_tetrimino->posx + j) * 2 + 2);
            wattr_on(tetris->win->game,
            COLOR_PAIR(tetris->actual_tetrimino->colour), NULL);
            wprintw(tetris->win->game, "%c",
            tetris->actual_tetrimino->shape[i][j]);
            wattr_off(tetris->win->game,
            COLOR_PAIR(tetris->actual_tetrimino->colour), NULL);
        }
    }
}

void print_game_win(game_t *tetris)
{
    wclear(tetris->win->game);
    wrefresh(tetris->win->game);
    wresize(tetris->win->game, tetris->map_height + 2,
    tetris->map_width * 2 + 3);
    mvwin(tetris->win->game, (LINES - tetris->map_height) / 2,
    (COLS - tetris->map_width * 2 + 3) / 2);
    wborder(tetris->win->game, (int)'|', (int)'|', (int)'-', (int)'-',
    (int)'/', (int)'\\', (int)'\\', (int)'/');
    for (int i = 0; tetris->map[i] != NULL; i++)
        for (int j = 0; tetris->map[i][j] != '\0'; j++) {
            wmove(tetris->win->game, i + 1, j * 2 + 2);
            wattr_on(tetris->win->game,
            COLOR_PAIR(tetris->colors[i][j]), NULL);
            wprintw(tetris->win->game, "%c", tetris->map[i][j]);
            wattr_off(tetris->win->game,
            COLOR_PAIR(tetris->colors[i][j]), NULL);
        }
    for (int i = 0; tetris->actual_tetrimino->shape[i] != NULL; i++)
        print_shape(tetris, i);
    wrefresh(tetris->win->game);
}

void print_info(game_t *tetris)
{
    mvwprintw(tetris->win->info, 2, 2, "High score");
    mvwprintw(tetris->win->info, 2, 27 - count_digits(tetris->highscore),
    "%d", tetris->highscore);
    mvwprintw(tetris->win->info, 3, 2, "Score");
    mvwprintw(tetris->win->info, 3, 27 - count_digits(tetris->score), "%d",
    tetris->score);
    mvwprintw(tetris->win->info, 5, 2, "Lines");
    mvwprintw(tetris->win->info, 5, 27 - count_digits(tetris->lines), "%d",
    tetris->lines);
    mvwprintw(tetris->win->info, 6, 2, "Level");
    mvwprintw(tetris->win->info, 6, 27 - count_digits(tetris->level), "%d",
    tetris->level);
    mvwprintw(tetris->win->info, 8, 2, "Timer");
}

void print_info_win(game_t *tetris)
{
    wclear(tetris->win->info);
    wrefresh(tetris->win->info);
    wresize(tetris->win->info, 10, 30);
    mvwin(tetris->win->info, (LINES - 10) / 2,
    (COLS - tetris->map_width * 2 + 3) / 2 - 33);
    wborder(tetris->win->info, (int)'|', (int)'|', (int)'-', (int)'-',
    (int)'/', (int)'\\', (int)'\\', (int)'/');
    print_info(tetris);
    if ((clock() - tetris->win->elapsed_time) / CLOCKS_PER_SEC > 1) {
        ++tetris->timerr;
        tetris->win->elapsed_time = clock();
    }
    mvwprintw(tetris->win->info, 8, 26 - count_digits(tetris->timerr) + 1,
    "%ds", tetris->timerr);
    wrefresh(tetris->win->info);
}
