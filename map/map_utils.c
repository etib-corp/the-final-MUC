/*
** EPITECH PROJECT, 2023
** map_utils.c
** File description:
** all utils functions for map
*/

#include "sfml_includes.h"

int *drop(int *level, int drop_v, int max)
{
    for (int i = 0; i < max; i++)
        level[i] += drop_v;
    return level;
}
