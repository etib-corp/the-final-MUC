/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** manage_chocobo
*/

#include "sfml_includes.h"

void ready_chocobo(entity_t *e)
{
    (void)e;
}

void process_chocobo(game_t *game, void *e)
{
    chocobo_t *chocobo = CAST(chocobo_t *, e);
    if (my_strcmp(game->map->json_map, "assets/map_houses.json") == 0 ||
    !game->player->choco)
        return;
    if (SKP(sfKeyF))
        whistle(chocobo);
    if (SKP(sfKeyM) && chocobo_is_mountable(game->player->pos,
    sfSprite_getGlobalBounds(chocobo->sprite)))
        chocobo->state = CHOCO_MOUNT;
    chocobo_process(game, chocobo);
}

void drawn_chocobo(game_t *game, void *e)
{
    chocobo_t *chocobo = CAST(chocobo_t *, e);
    if (my_strcmp(game->map->json_map, "assets/map_houses.json") == 0 ||
    !game->player->choco)
        return;
    sfRenderWindow_drawSprite(game->win, chocobo->sprite, NULL);
}

void destroy_chocobo(void *e)
{
    chocobo_t *chocobo = CAST(chocobo_t *, e);
    MY_FREE(chocobo, free_chocobo);
}
