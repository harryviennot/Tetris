/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** collision
*/

#include "../include/my.h"

int collision_annexe(game_t *tetris, int i, int j)
{
    if (tetris->actual_tetrimino->shape[i][j] == '*') {
        if (tetris->actual_tetrimino->posy + i < 0)
            return 1;
        if (tetris->actual_tetrimino->posx + j < 0)
            return 1;
        if (tetris->actual_tetrimino->posx + j >= tetris->map_width)
            return 1;
        if (tetris->actual_tetrimino->posy + i >= tetris->map_height)
            return 1;
        if (tetris->map[tetris->actual_tetrimino->posy + i]
            [tetris->actual_tetrimino->posx + j] != ' ')
            return 1;
    }
    return 0;
}

int check_collision(game_t *tetris)
{
    int val = 0;

    for (int i = 0; tetris->actual_tetrimino->shape[i] != NULL; i++) {
        for (int j = 0; tetris->actual_tetrimino->shape[i][j] != '\0'; j++) {
            val += collision_annexe(tetris, i, j);
        }
    }
    return val > 0 ? 1 : 0;
}

int check_if_left(game_t *tetris)
{
    tetris->actual_tetrimino->posx--;
    if (check_collision(tetris) == 1) {
        tetris->actual_tetrimino->posx++;
        return 0;
    }
    return 1;
}

int check_if_right(game_t *tetris)
{
    tetris->actual_tetrimino->posx++;
    if (check_collision(tetris) == 1) {
        tetris->actual_tetrimino->posx--;
        return 0;
    }
    return 1;
}
