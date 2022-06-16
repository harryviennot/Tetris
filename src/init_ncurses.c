/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** init_ncurses
*/

#include "../include/my.h"

void init_all_colors(void)
{
    if (has_colors() == TRUE) {
        start_color();
        init_pair(1, COLOR_RED, COLOR_BLACK);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_BLACK);
        init_pair(4, COLOR_BLUE, COLOR_BLACK);
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6, COLOR_CYAN, COLOR_BLACK);
        init_pair(7, COLOR_WHITE, COLOR_BLACK);
    }
}

void start_game(game_t *tetris)
{
    tetris->win = malloc(sizeof(window_t));
    int height = tetris->map_height;
    int width = tetris->map_width;
    int c = 0;
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    init_all_colors();
    tetris->win->info = newwin(10, 30, 8, 0);
    tetris->win->game = newwin(tetris->map_height + 2,
    tetris->map_width * 2 + 3, 0, 35);
    if (tetris->show_next = true)
        tetris->win->next = newwin(tetris->max_size + 2,
        tetris->max_size * 2 + 2, 0, 60);
    refresh();
    nodelay(tetris->win->game, true);
    keypad(tetris->win->game, true);
    tetris->win->elapsed_time = clock();
    tetris->timerr = 0;
}
