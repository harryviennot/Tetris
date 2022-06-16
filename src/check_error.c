/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** check_error
*/

#include "../include/my.h"

int error_annexe(tetrimino_t *tetrimino, game_t *tetris, char **propri)
{
    int size = false;
    int tmp = array_len(tetrimino->ogshape);

    if (array_len(tetrimino->ogshape) != tetrimino->height)
        tetrimino->error = true;
    for (int i = 0; tetrimino->ogshape[i] != NULL &&
        i < tetrimino->height; i++)
        if (my_strlen(tetrimino->ogshape[i]) - 1 == tetrimino->width)
            size = true;
    for (int i = 0; tetrimino->ogshape[i] != NULL &&
        i < tetrimino->height; i++)
        if (my_strlen(tetrimino->ogshape[i]) - 1 > tetrimino->width)
            size = false;
    if (size == false)
        tetrimino->error = true;
}

void check_error(tetrimino_t *tetrimino, game_t *tetris, char **propri)
{
    if (my_atoi(propri[2]) > 7)
        tetrimino->error = true;
    if (tetrimino->height > tetris->map_height)
        tetrimino->error = true;
    if (tetrimino->width > tetris->map_width)
        tetrimino->error = true;
    error_annexe(tetrimino, tetris, propri);
}

void check_error1(tetrimino_t *tetrimino, char **propri)
{
    if (array_len(propri) != 3)
            tetrimino->error = true;
    else {
        if (my_str_isnum(propri[0]) == 0)
            tetrimino->error = true;
        else
            tetrimino->width = my_atoi(propri[0]);
        if (my_str_isnum(propri[1]) == 0)
            tetrimino->error = true;
        else
            tetrimino->height = my_atoi(propri[1]);
        if (my_str_isnum(propri[2]) == 0)
            tetrimino->error = true;
        else
            tetrimino->colour = my_atoi(propri[2]);
    }
}

int get_nbvalid(game_t *tetris)
{
    int nb = 0;

    for (int i = 0; i < tetris->nb_shapes; i++)
        if (tetris->shapes[i]->error == false)
            nb++;
    return nb;
}
