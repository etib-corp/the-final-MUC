##
## EPITECH PROJECT, 2023
## B-MUL-200-RUN-2-1-myrpg-leo.sautron
## File description:
## Makefile
##

SRC = json_array.c\
	json_value.c\
	json_bool_string_float.c\
	json_value.c\
	json_pair.c\
	parser_json.c\
	json_obj.c\
	get_json.c\

CFLAGS = -Wall -Werror -Wextra -W -I../include

CC = gcc

LDFLAGS = -L ../ -lmy

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	cp *.o ../obj

debug:
	cp $(SRC) ../debug
