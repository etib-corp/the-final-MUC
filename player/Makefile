##
## EPITECH PROJECT, 2023
## B-MUL-200-RUN-2-1-myrpg-leo.sautron
## File description:
## Makefile
##

SRC	=	player.c \
		weapon.c \
		normalize.c \
		player_states.c \
		player_physics.c \
		manage_player.c \
		set_animation.c \
		updata_score.c \
		manage_speed.c \

CFLAGS = -Wall -Werror -Wextra -W -I../include

CC = gcc

OBJ = $(SRC:.c=.o)

all: $(OBJ)
	cp *.o ../obj

debug:
	cp $(SRC) ../debug
