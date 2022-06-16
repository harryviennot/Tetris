/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-tetris-harry.viennot
** File description:
** get_tetriminos
*/

#include "../include/my.h"

void get_ogshape(tetrimino_t *tetrimino)
{
    int i = 0;
    int j = 0;
    int k = 0;
    tetrimino->ogshape = malloc(sizeof(char *) * (tetrimino->height + 1));

    for (i = 0; i < tetrimino->height; i++) {
        tetrimino->ogshape[i] = malloc(sizeof(char) * (tetrimino->width + 2));
        for (j = 0; j < tetrimino->width; j++) {
            tetrimino->ogshape[i][j] = tetrimino->shape[i][j];
            if (tetrimino->shape[i][j] == '*')
                k = j;
        }
        tetrimino->ogshape[i][k + 1] = '\n';
        tetrimino->ogshape[i][k + 2] = '\0';
    }
    tetrimino->ogshape[tetrimino->height] = NULL;
}

void get_shape_ext(char **data, tetrimino_t *tetrimino, int size, int var[])
{
    for (int j = 0, l = 0; j < size; j++, l++) {
        if (var[2] == 0 && data[var[1]][l] == '\0')
            var[2] = 1;
        if (var[2] == 0 && data[var[1]][l] == '*')
            tetrimino->shape[var[0]][j] = '*';
        else
            tetrimino->shape[var[0]][j] = ' ';
    }
}

void get_shape(char **data, tetrimino_t *tetrimino)
{
    int k = 1;
    int l = 0;
    tetrimino->posx = 0;
    tetrimino->posy = 0;
    int size = tetrimino->height < tetrimino->width ?
    size = tetrimino->width : tetrimino->height;
    int end = 0;
    tetrimino->shape = malloc(sizeof(char *) * (size + 1));
    for (int i = 0; i < size; i++, k++, end = 0) {
        tetrimino->shape[i] = malloc(sizeof(char) * (size + 1));
        int var[] = {i, k, end};
        get_shape_ext(data, tetrimino, size, var);
        tetrimino->shape[i][size] = '\0';
    }
    tetrimino->shape[size] = NULL;
}

tetrimino_t *create_tetrimino(char *filepath, char *file, game_t *tetris)
{
    int i = 0;
    int j = 0;
    tetrimino_t *tetrimino = malloc(sizeof(tetrimino_t));
    char **data = my_str_to_word_array(text_in_a_string(filepath), '\n');
    char **propri = my_str_to_word_array(data[i], ' ');
    tetrimino->name = get_name(file);
    tetrimino->error = false;
    check_error1(tetrimino, propri);
    if (tetrimino->error == false) {
        get_shape(data, tetrimino);
        get_ogshape(tetrimino);
        check_error(tetrimino, tetris, propri);
    }
    if (tetrimino->error == true)
        return tetrimino;
    if (tetris->max_size < tetrimino->width)
        tetris->max_size = tetrimino->width;
    if (tetris->max_size < tetrimino->height)
        tetris->max_size = tetrimino->height;
    return tetrimino;
}

void get_tetriminos(game_t *tetris)
{
    int i = 0;
    char *filepath = "./tetriminos";
    tetris->nb_shapes = count_files(filepath);
    char *file;
    DIR *d;
    struct dirent *dir;
    d = opendir(filepath);
    if (d == NULL)
        return;
    tetris->max_size = 0;
    tetris->shapes = malloc(sizeof(tetrimino_t *) * tetris->nb_shapes);
    while ((dir = readdir(d)) != NULL) {
        file = dir->d_name;
        if (file[0] == '.')
            continue;
        tetris->shapes[i++] = create_tetrimino(concatenate(filepath,
        file), file, tetris);
    }
    closedir(d);
}
