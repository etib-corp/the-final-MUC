/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** my_strchr
*/

#include "my.h"

char *my_strchr(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return str + i;
    return NULL;
}
