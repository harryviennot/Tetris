/*
** EPITECH PROJECT, 2022
** B-PSU-200-TLS-2-1-mysokoban-harry.viennot
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <sys/sysmacros.h>
    #include <ncurses.h>
    #include <string.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include <ctype.h>
    #include <getopt.h>
    #include <time.h>

    typedef struct {
        WINDOW *game;
        WINDOW *info;
        WINDOW *next;
        float elapsed_time;
    } window_t;

    typedef struct {
        int height;
        int width;
        int posx;
        int posy;
        int colour;
        char **shape;
        char **ogshape;
        char *name;
        int error;
    } tetrimino_t;

    typedef struct {
        int key_turn;
        int key_drop;
        int key_left;
        int key_right;
        int key_pause;
        int key_quit;
    } keys_t;

    typedef struct {
        char **map;
        int **colors;
        int nb_shapes;
        int debug_mode;
        int show_next;
        int highscore;
        int score;
        int paused;
        int map_width;
        int map_height;
        int level;
        int lines;
        int prev_lines;
        int max_size;
        float time;
        int timerr;
        window_t *win;
        tetrimino_t **shapes;
        tetrimino_t *next_tetrimino;
        tetrimino_t *actual_tetrimino;
        keys_t *key_binding;
    } game_t;

    static struct option long_options[] =
    {
        {"level", required_argument, NULL, 'L'},
        {"key-left", required_argument, NULL, 'l'},
        {"key-right", required_argument, NULL, 'r'},
        {"key-drop", required_argument, NULL, 'd'},
        {"key-turn", required_argument, NULL, 't'},
        {"key-quit", required_argument, NULL, 'q'},
        {"key-pause", required_argument, NULL, 'p'},
        {"map-size", required_argument, NULL, 'm'},
        {"without-next", no_argument, NULL, 'w'},
        {"debug", no_argument, NULL, 'd'},
        {NULL, 0, NULL, 0}
    };

    char *text_in_a_string(char *filepath);
    void get_tetriminos(game_t *tetris);
    char **my_str_to_word_array(char *str, char separator);
    int set_game_instance(int ac, char **av, game_t *tetris);
    char **rotate_shape(char **shape);
    void print_map(game_t *tetris);
    void init_tetris(game_t *tetris);
    int my_strlen(char const *str);
    char *my_strdup(char *str);
    void play_tetris(game_t *tetris);
    int print_windows(game_t *tetris);
    void start_game(game_t *tetris);
    int check_collision(game_t *tetris);
    void rotate(game_t *tetris);
    void debug(game_t *tetris);
    int count_digits(int nb);
    int check_only_char(char const *str, char chr);
    void start_new_game(game_t *tetris);
    void terminate_game(game_t *tetris);
    void put_tetrismap(game_t *tetris);
    int check_if_left(game_t *tetris);
    int check_if_right(game_t *tetris);
    void check_fullrow(game_t *tetris);
    int check_lost(game_t *tetris);
    void free_new_game(game_t *tetris);
    void check_if_lastrow(game_t *tetris);
    void free_actual(game_t *tetris);
    tetrimino_t *get_random(game_t *tetris);
    void make_pause(game_t *tetris, char *str);
    void reset_map(game_t *tetris);
    void print_game_win(game_t *tetris);
    void print_info_win(game_t *tetris);
    int get_options(int ac, char **av, game_t *tetris);
    int array_len(char **array);
    int my_str_isnum(char *str);
    char *concatenate(char *strg1, char *strg2);
    int count_files(char *filepath);
    char *get_name(char *file);
    void check_error(tetrimino_t *tetrimino, game_t *tetris, char **propri);
    int my_atoi(char *str);
    void my_printf(char *string, ...);
    void my_put_nbr(int nb);
    void kill_windows(game_t *tetris);
    void my_putchar(char c);
    void check_error1(tetrimino_t *tetrimino, char **propri);

#endif
