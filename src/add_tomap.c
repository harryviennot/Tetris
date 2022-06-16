/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** add_tomap
*/

#include "../include/my.h"

void put_inmap(game_t *tetris, int i)
{
    for (int j = 0; tetris->actual_tetrimino->shape[i][j] != 0; j++) {
        if (tetris->actual_tetrimino->shape[i][j] == '*') {
            tetris->map[i + tetris->actual_tetrimino->posy][j +
            tetris->actual_tetrimino->posx] = '*';
            tetris->colors[i + tetris->actual_tetrimino->posy][j +
            tetris->actual_tetrimino->posx] = tetris->actual_tetrimino->colour;
        }
    }
}

void put_tetrismap(game_t *tetris)
{
    if (check_collision(tetris)) {
        tetris->actual_tetrimino->posy--;
        for (int i = 0; tetris->actual_tetrimino->shape[i] != NULL; i++)
            put_inmap(tetris, i);
        free_actual(tetris);
        tetris->actual_tetrimino = tetris->next_tetrimino;
        tetris->next_tetrimino = get_random(tetris);
    }
}

void check_rowann(game_t *tetris, int i, int j)
{
    if (tetris->actual_tetrimino->shape[i][j] == '*' &&
        i == tetris->map_height - 1) {
        for (int i = 0; tetris->actual_tetrimino->shape[i] != NULL; i++)
            put_inmap(tetris, i);
        free_actual(tetris);
        tetris->actual_tetrimino = tetris->next_tetrimino;
        tetris->next_tetrimino = get_random(tetris);
    }
}

void check_if_lastrow(game_t *tetris)
{
    for (int i = 0; tetris->actual_tetrimino->shape[i] != NULL; i++) {
        for (int j = 0; tetris->actual_tetrimino->shape[i][j] != 0; j++) {
            check_rowann(tetris, i, j);
        }
    }
}

void reset_map(game_t *tetris)
{
    for (int i = 0; i < tetris->map_height; i++) {
        for (int j = 0; j < tetris->map_width; j++) {
            tetris->map[i][j] = ' ';
            tetris->colors[i][j] = 0;
        }
    }
}
