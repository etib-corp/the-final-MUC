/*
** EPITECH PROJECT, 2023
** create_entity.c
** File description:
** all functions to create an entity
*/

#include "sfml_includes.h"

sfIntRect *set_rect(int top, int left, int width, int height)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->top = top;
    rect->left = left;
    rect->width = width;
    rect->height = height;
    return rect;
}
