##
## EPITECH PROJECT, 2023
## B-MUL-200-RUN-2-1-myrpg-leo.sautron
## File description:
## Makefile
##

SRC = 	main.c \
		manage_view.c \
		manage_game.c \
		manage_window.c \
		check_file.c \
		loop.c \
		manage_save.c \
		soundtrack.c \
		state_loop.c \
		load_file.c \

CFLAGS = -Wall -Werror -Wextra -W -I../include

CC = gcc

LDFLAGS = -L ../ -lmy

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	cp *.o ../obj

debug:
	cp $(SRC) ../debug
