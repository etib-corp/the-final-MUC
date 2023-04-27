/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** my_itoa
*/
#include "my.h"

size_t my_lennbr(size_t nb)
{
    int i = 0;
    while (nb /= 10)
        i++;
    return ++i;
}

void my_swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    while (i < j) {
        my_swap(&str[i], &str[j]);
        i++;
        j--;
    }
    return str;
}

char *my_itoa(size_t nb)
{
    int index = 0;
    char *str = my_calloc(sizeof(char), (50));
    while (nb > 0) {
        str[index] = (nb % 10) + 48;
        nb /= 10;
        index++;
    }
    if (index == 0)
        str[index] = '0';
    str[index + 1] = '\0';
    str = my_revstr(str);
    return str;
}
