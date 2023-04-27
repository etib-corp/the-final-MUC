##
## EPITECH PROJECT, 2023
## B-MUL-200-RUN-2-1-myrpg-leo.sautron
## File description:
## Makefile
##

SRC =	manage_entity.c \

CFLAGS = -Wall -Werror -Wextra -W -I../include

LDFLAGS = -L ../ -lmy

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	cp *.o ../obj

debug:
	cp $(SRC) ../debug
