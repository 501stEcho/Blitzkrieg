##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## runner
##
CC = gcc

flags = -g -g3 -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window

src = src/window.c \
      src/initialize.c \
      src/initialize2.c \
      src/commentary.c \
      src/menu_selecter.c \
      src/mouse_selecter.c \
      src/mouse_selecter2.c \
      src/deinitialize.c \
      src/deinitialize2.c \
      src/time.c \
      src/time2.c \
      src/background.c \
      src/display.c \
      src/rect.c \
      src/rect2.c \
      src/rect3.c \
      src/rect4.c \
      src/rect5.c \
      src/sprite_create.c \
      src/sprite_create2.c \
      src/sprite_create3.c \
      src/sprite_create4.c \
      src/barry_fct.c \
      src/barry_fct2.c \
      src/mapreader.c \
      src/tools.c \
      src/tools2.c \
      src/tools3.c \
      src/tools4.c \
      src/tools5.c \
      src/tools6.c \
      src/tools7.c \
      src/bomb_fct.c \
      src/bomb_fct2.c \
      src/coin_fct.c \
      src/coin_fct2.c \
      src/score.c \
      src/score2.c \
      src/highscore.c \
      src/text.c \
      src/button_fct.c \
      src/button_fct2.c \
      src/plane_fct.c \
      src/preinitialize.c \
      src/miscellaneous.c \
      src/infinite_map.c

NAME = my_runner

OBJ = ${src:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

compile:        ${OBJ}
	gcc -o ${NAME} ${OBJ} ${flags}

all:	compile

clean:
	rm -rf ${OBJ}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all
