/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** debug
*/

#include "../include/my.h"

static void print_shapes(game_t *tetris, int i)
{
    if (tetris->shapes[i]->error == true)
        my_printf("Tetriminos '%s': error\n", tetris->shapes[i]->name);
    else {
        my_printf("Tetriminos '%s': size %d*%d, color %d\n",
        tetris->shapes[i]->name, tetris->shapes[i]->height,
        tetris->shapes[i]->width, tetris->shapes[i]->colour);
        for (int j = 0; tetris->shapes[i]->ogshape[j] != NULL; j++) {
            my_printf("%s", tetris->shapes[i]->ogshape[j]);
        }
    }
}

void debug(game_t *tetris)
{
    my_printf("Key left: %c (%d)\n", (char)tetris->key_binding->key_left,
    tetris->key_binding->key_left);
    my_printf("Key right: %c (%d)\n", (char)tetris->key_binding->key_right,
    tetris->key_binding->key_right);
    my_printf("Key turn: %c (%d)\n", (char)tetris->key_binding->key_turn,
    tetris->key_binding->key_turn);
    my_printf("Key drop: %c (%d)\n", (char)tetris->key_binding->key_drop,
    tetris->key_binding->key_drop);
    my_printf("Key quit: %c (%d)\n", (char)tetris->key_binding->key_quit,
    tetris->key_binding->key_quit);
    my_printf("Key pause: %c (%d)\n", (char)tetris->key_binding->key_pause,
    tetris->key_binding->key_pause);
    tetris->show_next == true ?
    my_printf("Next: Yes\n") : my_printf("Next: No\n");
    my_printf("Level: %d\n", tetris->level);
    my_printf("Size: %d*%d\n\n", tetris->map_height, tetris->map_width);
    my_printf("Number of tetriminos: %d\n", tetris->nb_shapes);
    for (int i = 0; i < tetris->nb_shapes; i++) {
        print_shapes(tetris, i);
    }
}
