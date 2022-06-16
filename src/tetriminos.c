/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** tetriminos
*/

#include "../include/my.h"

int count_files(char *filepath)
{
    int i = 0;
    DIR *d;
    struct dirent *dir;

    d = opendir(filepath);
    if (d == NULL)
        return 0;
    while ((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] == '.')
            continue;
        i++;
    }
    closedir(d);
    return i;
}

char *get_name(char *file)
{
    char *name = NULL;
    int i;

    for (i = 0; file[i] != '.'; i++);
    name = malloc(sizeof(char) * (i + 1));
    for (i = 0; file[i] != '.'; i++)
        name[i] = file[i];
    name[i] = '\0';
    return name;
}

char *concatenate(char *strg1, char *strg2)
{
    int i = 0;
    int lenstr = my_strlen(strg1);
    int lenstr2 = my_strlen(strg2);
    char *concatenated = malloc(sizeof(char) * (lenstr + lenstr2 + 2));

    for (int j = 0; j < lenstr; j++, i++)
        concatenated[i] = strg1[j];
    concatenated[i++] = '/';
    for (int j = 0; j < lenstr2; j++, i++)
        concatenated[i] = strg2[j];
    concatenated[i] = '\0';
    return concatenated;
}
