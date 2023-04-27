##
## EPITECH PROJECT, 2023
## B-MUL-200-RUN-2-1-myrpg-leo.sautron
## File description:
## Makefile
##

SRC	=	pause_menu.c \
		main_menu.c \
		menu_utils.c \
		manage_menu.c \
		manage_pause.c \
		settings.c \
		settings_function.c \
		splash.c \
		help.c \


CFLAGS = -Wall -Werror -Wextra -W -I../include

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	cp *.o ../obj

debug:
	cp $(SRC) ../debug
