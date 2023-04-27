/*
** EPITECH PROJECT, 2023
** box.c
** File description:
** all functions to manage boxes
*/

#include "sfml_includes.h"

sfIntRect *create_rect(sfVector2i dimensions, sfVector2i pos)
{
    sfIntRect *rect = malloc(sizeof(sfIntRect));

    rect->width = dimensions.x;
    rect->height = dimensions.y;
    rect->left = pos.x;
    rect->top = pos.y;
    return rect;
}

box_t *init_box(sfVector2i dimensions, sfVector2i pos, int value)
{
    box_t *box = malloc(sizeof(box_t));

    if (box == NULL)
        return NULL;
    box->rect = create_rect(dimensions, pos);
    box->value = value;
    return box;
}

void move_box(box_t *box, sfVector2f move)
{
    box->rect->left += (int)move.x;
    box->rect->top += (int)move.y;
}

void free_box(box_t *box)
{
    if (box == NULL)
        return;
    free(box->rect);
    free(box);
}
