/*
** EPITECH PROJECT, 2023
** xp_bar.c
** File description:
** all functions to manage xp bar
*/

#include "sfml_includes.h"

sfRectangleShape *create_rectangle(sfVector2f size, sfVector2f pos,
    sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    if (rect == NULL)
        return NULL;
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}

void update_xpbar(int xp, sfRectangleShape *rect)
{
    sfVector2f size = sfRectangleShape_getSize(rect);

    sfRectangleShape_setSize(rect, V2F(10 * (xp + 1), size.y));
}
