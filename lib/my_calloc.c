/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** my_calloc
*/

#include "my.h"

void *my_calloc(size_t len, size_t size)
{
    void *data = malloc(size * len);
    if (data == NULL)
        return NULL;
    memset(data, 0, len * size);
    return data;
}
