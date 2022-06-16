/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** get_opt
*/

#include "../include/my.h"

int get_options_ext2(int c, game_t *tetris)
{
    char **args = NULL;
    switch (c) {
    case 'm':
        args = my_str_to_word_array(optarg, '\n');
        tetris->map_height = my_atoi(args[0]);
        tetris->map_width = my_atoi(args[1]);
        break;
    case 'w':
        tetris->show_next = true;
        break;
    case 'D':
        tetris->debug_mode = true;
        break;
    }
}

int get_options_ext(int c, game_t *tetris)
{
    switch (c) {
    case 't':
        tetris->key_binding->key_turn = my_atoi(optarg);
        break;
    case 'd':
        tetris->key_binding->key_drop = my_atoi(optarg);
        break;
    case 'q':
        tetris->key_binding->key_quit = my_atoi(optarg);
        break;
    case 'p':
        tetris->key_binding->key_pause = my_atoi(optarg);
        break;
    default:
        get_options_ext2(c, tetris);
        break;
    }
}

int get_options(int ac, char **av, game_t *tetris)
{
    int c;
    int long_index = 0;
    while ((c = getopt_long(ac, av, "hL:l:r:t:d:q:p:m:wD",
    long_options, &long_index)) != -1) {
        switch (c) {
        case 'L':
            tetris->level = my_atoi(optarg);
            break;
        case 'l':
            tetris->key_binding->key_left = my_atoi(optarg);
            break;
        case 'r':
            tetris->key_binding->key_right = my_atoi(optarg);
            break;
        default:
            get_options_ext(c, tetris);
            break;
        }
    }
}
