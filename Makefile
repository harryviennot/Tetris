##
## EPITECH PROJECT, 2021
## my_printf
## File description:
## Makefile
##

NAME	=	tetris

SRC	= 	src/tetris.c \
		src/game_instance.c \
		src/get_tetriminos.c \
		src/my_str_to_word_array.c \
		src/rotate.c \
		src/text_in_a_string.c \
		src/main.c \
		src/my_strdup.c \
		src/game.c \
		src/debug.c \
		src/add_tomap.c \
		src/collision.c \
		src/free_game.c \
		src/row_checks.c \
		src/get_opt.c \
		src/print_windows.c \
		src/init_ncurses.c \
		src/check_error.c \
		src/tetriminos.c \
		src/my_atoi.c \
		src/my_printf.c \

CFLAGS	=		-I ./include/ -g3

OBJ	=	$(SRC:.c=.o)

$(NAME):
		@$(MAKE) -s $(OBJ)
		gcc -lncurses -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
