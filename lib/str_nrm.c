/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** str_nrm
*/

#include "my.h"

char *str_nrm(char *s, int n)
{
    int len = my_strlen(s) - n;
    char *new = malloc(sizeof(char) * (len + 1));
    int i = 0;
    for (i = 0; i < len; i ++)
        new[i] = s[i];
    new[i] = '\0';
    return new;
}
