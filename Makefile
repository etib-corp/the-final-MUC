##
## EPITECH PROJECT, 2023
## B-MUL-200-RUN-2-1-myrpg-leo.sautron
## File description:
## Makefile
##

NAME = my_rpg

CC = gcc

SRC = obj/*

DEBUG_SRC = debug/*

CFLAGS = -Wall -Werror -Wextra -W -I./include

LDFLAGS = -L . -lmy

LFLAGS = -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window -lm

all: run_makefile
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(LDFLAGS) $(LFLAGS)

debug: run_debug
	$(CC) -o $(NAME) $(DEBUG_SRC) $(CFLAGS) $(LDFLAGS) $(LFLAGS) -g -g3 -ggdb

run_makefile:
	mkdir -p obj
	make -C lib
	make -C ath
	make -C box
	make -C music
	make -C dialogs
	make -C entities
	make -C inventory
	make -C pause_menu
	make -C dropable
	make -C map
	make -C parsing
	make -C game_engine
	make -C player
	make -C free
	make -C chocobo
	make -C quadtree
	make -C enemy
	make -C boss
	make -C src


run_debug:
	mkdir -p debug
	make -C lib
	make debug -C ath
	make debug -C box
	make debug -C dialogs
	make debug -C map
	make debug -C music
	make debug -C inventory
	make debug -C dropable
	make debug -C pause_menu
	make debug -C parsing
	make debug -C entities
	make debug -C game_engine
	make debug -C player
	make debug -C free
	make debug -C chocobo
	make debug -C quadtree
	make debug -C enemy
	make debug -C boss
	make debug -C src

clean:
	find -type f -name "#*#" -delete -o \
	-type f -name "*~" -delete -o -type f -name "*.o" -delete -o \
	-type f -name "*.gc*" -delete
	rm -fr vgcore.*

fclean: clean
	make fclean -C lib/
	rm -f $(NAME)
	rm -fr obj/
	rm -fr debug/

re: fclean all
