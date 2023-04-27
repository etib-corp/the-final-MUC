##
## EPITECH PROJECT, 2023
## make for lib
## File description:
## make
##

NAME = libmy.a

CFLAGS = -Wall -Werror -Wextra -W

SRC = my_getnbr.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strdup.c \
	my_str_to_word_array.c \
	my_strlen.c \
	mini_printf.c \
	my_put_nbr.c \
	my_putstr.c \
	my_putchar.c \
	my_strcat.c \
	my_strstr.c \
	creatpath.c \
	my_append_array.c \
	my_strchr.c \
	my_calloc.c \
	my_is_digit.c \
	list.c \
	linked_list.c \
	list_nothing.c \
	my_itoa.c \
	str_nrm.c \

OBJ = $(SRC:.c=.o)

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	find -type f -name "#*#" -delete -o \
	-type f -name "*~" -delete -o -type f -name "*.o" -delete -o \
	-type f -name "*.gc*" -delete

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
