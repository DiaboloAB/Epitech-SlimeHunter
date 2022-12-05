##
## EPITECH PROJECT, 2022
## window render
## File description:
## window render
##

NAME	=	my_hunter

SRC	=	src/main.c \
		src/hunter.c \
		src/main_loop.c \
		src/init_obj.c \
		src/draw_obj.c \
		src/init_obj_2.c \
		src/draw_obj_2.c \
		src/tools.c \
		src/zombie.c \
		src/enemies.c \
		src/zombie_attack.c \
		src/init_text.c \
		src/free_all.c \
		src/audio.c \
		src/home.c \
		src/new_game.c \
		src/pause.c \
		src/init_pause.c \
		src/buttons.c \
		src/score_manage.c \
		src/difficulty_manage.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude/

LIBS	=	-lcsfml-graphics -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME): $(OBJ)
	make -C lib/printf
	gcc -o $(NAME) $(OBJ) $(LIBS) -Llib -lmy -lm -g

clean:
	make clean -C lib/printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/printf
	rm -f $(NAME)

re:	fclean all
