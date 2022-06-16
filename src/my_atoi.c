/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** my_atoi
*/

#include "../include/my.h"

int my_atoi(char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > '9' || str[i] < '0')
            return (0);
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (nb * neg);
}
