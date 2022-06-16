/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-mysokoban-harry.viennot
** File description:
** text_in_a_string
*/

#include "../include/my.h"

char *text_in_a_string(char *filepath)
{
    int var = open(filepath, O_RDONLY);
    if (var <= 0)
        return NULL;
    struct stat st;
    int size = 0;
    char *string = NULL;

    stat(filepath, &st);
    size = st.st_size;
    string = malloc(sizeof(char) * (size + 1));
    read(var, string, size);
    close(var);
    string[size] = '\0';
    return string;
}
