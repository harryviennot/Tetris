/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** my_strdup
*/

#include "../include/my.h"

int check_only_char(char const *str, char chr)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] != chr)
            return 0;
        i++;
    }
    return 1;
}

int count_digits(int nb)
{
    int i = 0;

    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb = nb / 10;
        i++;
    }
    return i;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strdup(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (; str[i] != '\0'; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return new_str;
}
