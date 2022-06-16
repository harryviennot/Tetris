/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** row_checks
*/

#include "../include/my.h"

int check_lost(game_t *tetris)
{
    for (int i = 0; tetris->map[0][i] != '\0'; i++) {
        if (tetris->map[0][i] == '*')
            return 1;
    }
    return 0;
}

void remove_row(game_t *tetris, int row)
{
    for (int i = row; i > 0; i--) {
        for (int j = 0; tetris->map[i][j] != '\0'; j++) {
            tetris->map[i][j] = tetris->map[i - 1][j];
            tetris->colors[i][j] = tetris->colors[i - 1][j];
        }
    }
}

void check_fullrow(game_t *tetris)
{
    for (int i = 0; i < tetris->map_height; i++) {
        if (check_only_char(tetris->map[i], '*') == 1) {
            remove_row(tetris, i);
            tetris->lines += 1;
        }
    }
}
