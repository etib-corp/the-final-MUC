##
## EPITECH PROJECT, 2023
## B-MUL-200-RUN-2-1-myrpg-leo.sautron
## File description:
## Makefile
##

SRC =	init_chocobo.c \
		manage_chocobo.c \
		manage_whistle.c \
		process_chocobo.c \
		animation_chocobo.c \
		chocobo_move.c \

CFLAGS = -Wall -Werror -Wextra -W  -I../include

CC = gcc

LDFLAGS = -L ../ -lmy

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	cp *.o ../obj

debug:
	cp $(SRC) ../debug
