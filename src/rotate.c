/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** rotate
*/

#include "../include/my.h"

char **rotate_shape(char **shape)
{
    int i = 0;
    for (; shape[i] != NULL; i++);
    char **new_shape = malloc(sizeof(char *) * (i + 1));
    int index_x = 0;
    int index_y = i;

    for (int j = 0; j < i; j++, index_x++) {
        new_shape[j] = malloc(sizeof(char) * (i + 1));
        for (int z = 0, index_y = i - 1; z < i; z++, index_y--)
            new_shape[j][z] = shape[index_y][index_x];
        new_shape[j][i] = '\0';
    }
    new_shape[i] = NULL;
    return new_shape;
}

void rotate(game_t *tetris)
{
    char **tmp = NULL;
    int tmp_i = 0;

    do {
        tmp = rotate_shape(tetris->actual_tetrimino->shape);
        for (int i = 0; tetris->actual_tetrimino->shape[i] != NULL; i++)
            free(tetris->actual_tetrimino->shape[i]);
        free(tetris->actual_tetrimino->shape);
        tetris->actual_tetrimino->shape = tmp;
        tmp_i = tetris->actual_tetrimino->width;
        tetris->actual_tetrimino->width = tetris->actual_tetrimino->height;
        tetris->actual_tetrimino->height = tmp_i;
    }
    while (check_collision(tetris) == 1);
}
