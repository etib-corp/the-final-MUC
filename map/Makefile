##
## EPITECH PROJECT, 2023
## B-MUL-200-RUN-2-1-myrpg-leo.sautron
## File description:
## Makefile
##

SRC = 	map.c \
		draw_map.c \
		map_utils.c \
		get_layers.c \
		change_map.c \
		get_specifique.c \
		push_in_list.c \
		get_entity.c \

CFLAGS = -Wall -Werror -Wextra -W -I../include

CC = gcc

LDFLAGS = -L ../ -lmy

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	cp *.o ../obj

debug:
	cp $(SRC) ../debug
