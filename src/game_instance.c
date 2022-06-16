/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** game_instance
*/

#include "../include/my.h"

void make_map(game_t *tetris)
{
    tetris->map = malloc(sizeof(char *) * (tetris->map_height + 1));

    for (int i = 0; i < tetris->map_height; i++) {
        tetris->map[i] = malloc(sizeof(char) * (tetris->map_width + 1));
        for (int j = 0; j < tetris->map_width; j++)
            tetris->map[i][j] = ' ';
        tetris->map[i][tetris->map_width] = '\0';
    }
    tetris->map[tetris->map_height] = NULL;
}

int **create_colormap(game_t *tetris)
{
    int **colormap = malloc(sizeof(int *) * (tetris->map_height + 1));

    for (int i = 0; i < tetris->map_height; i++) {
        colormap[i] = malloc(sizeof(int) * (tetris->map_width + 1));
        for (int j = 0; j < tetris->map_width; j++)
            colormap[i][j] = 0;
    }
    colormap[tetris->map_height] = NULL;
    return colormap;
}

int set_game_instance(int ac, char **av, game_t *tetris)
{
    tetris->key_binding = malloc(sizeof(keys_t));
    tetris->level = 1;
    tetris->score = 0;
    tetris->debug_mode = false;
    tetris->map_height = 20;
    tetris->map_width = 10;
    tetris->show_next = true;
    tetris->paused = false;
    tetris->lines = 0;
    tetris->key_binding->key_left = KEY_LEFT;
    tetris->key_binding->key_right = KEY_RIGHT;
    tetris->key_binding->key_turn = KEY_UP;
    tetris->key_binding->key_drop = KEY_DOWN;
    tetris->key_binding->key_pause = (int)(' ');
    tetris->key_binding->key_quit = (int)('q');
    tetris->colors = create_colormap(tetris);
    make_map(tetris);
    if (ac >= 2)
        get_options(ac, av, tetris);
}
