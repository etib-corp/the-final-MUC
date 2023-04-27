/*
** EPITECH PROJECT, 2023
** my_frees.c
** File description:
** len of an array
*/

#include "lib.h"

void free_char_array(void **array)
{
    for (int i = 0; array != NULL && array[i] != NULL; i++)
        free(array[i]);
    if (array != NULL)
        free(array);
}
