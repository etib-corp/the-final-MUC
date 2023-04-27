##
## EPITECH PROJECT, 2023
## B-MUL-200-RUN-2-1-myrpg-leo.sautron
## File description:
## Makefile
##

SRC =   choices.c \
		create_npc.c \
		manage_npc.c \
		create_entity.c \
		npc_functions.c \

CFLAGS = -Wall -Werror -Wextra -W -I../include

CC = gcc

LDFLAGS = -L ../ -lmy

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	cp *.o ../obj

debug:
	cp $(SRC) ../debug
