/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main
*/

#include "../include/my.h"

int array_len(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return i;
}

int my_str_isnum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

void my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

void start_new_game(game_t *tetris)
{
    init_tetris(tetris);
    start_game(tetris);
    play_tetris(tetris);
}

int main(int ac, char **av)
{
    srand(time(NULL));
    game_t *tetris = malloc(sizeof(game_t));
    set_game_instance(ac, av, tetris);
    get_tetriminos(tetris);
    tetris->highscore = 0;
    if (tetris->debug_mode == true) {
        debug(tetris);
        exit(0);
    }
    if (get_nbvalid(tetris) == 0)
        return (84);
    start_new_game(tetris);
    return 0;
}
