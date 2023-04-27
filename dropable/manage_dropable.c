/*
** EPITECH PROJECT, 2023
** manage_dropable.c
** File description:
** manage_dropable
*/

#include "sfml_includes.h"

void ready_dropable(entity_t *e)
{
    (void)e;
}

void process_dropable(game_t *game, void *e)
{
    update_dropable(game->player, e, game->ath->inventory);
}

void draw_dropable(game_t *game, void *e)
{
    dropable_t *item = CAST(dropable_t *, e);
    if (item->display)
        sfRenderWindow_drawSprite(game->win, item->sprite, NULL);
}

void destroy_dropable(void *e)
{
    dropable_t *gree = CAST(dropable_t *, e);
    MY_FREE(gree, free_dropable);
}
