/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** manage_view
*/

#include "sfml_includes.h"

view_t *init_views(void)
{
    view_t *views = malloc(sizeof(view_t));

    views->player = sfView_createFromRect(FR(0, 0, 444, 250));
    views->minimap = sfView_createFromRect(FR(0, 0, 1920, 1080));
    sfView_setViewport(views->minimap, FR(0.75, 0, 0.25, 0.25));
    views->cinematic = sfView_createFromRect(FR(0, 0, 1920, 1080));
    return views;
}

sfFloatRect rect_of_view(sfView *view)
{
    sfVector2f tmp1 = sfView_getCenter(view);
    sfVector2f size = sfView_getSize(view);
    size = (sfVector2f){size.x / 2.0, size.y / 2.0};
    return FR(tmp1.x - size.x, tmp1.y - size.y, size.x * 2, size.y * 2);
}
