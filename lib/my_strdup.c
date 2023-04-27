/*
** EPITECH PROJECT, 2022
** oui
** File description:
** oui
*/

#include "my.h"

char *my_memset(char *s, int j, int size)
{
    for (int i = 0; size > i; i++)
        s[i] = j;
    return s;
}

char *my_strdup(char const *str)
{
    if (str == NULL)
        return NULL;
    int i = 0;
    i = my_strlen(str);
    char *str_cpy = malloc(sizeof(char) * (i + 1));
    if (str_cpy == NULL)
        return NULL;
    str_cpy = my_memset(str_cpy, 0, i);
    return my_strcpy(str_cpy, str);
}
