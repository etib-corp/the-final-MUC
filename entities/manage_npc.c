/*
** EPITECH PROJECT, 2023
** manage_npc.c
** File description:
** all functions to manage npc
*/

#include "sfml_includes.h"

void process_npc(game_t *game, void *e)
{
    npc_t *npc = CAST(npc_t *, e);
    if (sfIntRect_contains(npc->zone->rect, (int)game->player->pos.x,
    (int)game->player->pos.y) && (npc->state == WAIT || npc->state == TALK)
    && npc->s_dialog) {
        npc->state = TALK;
        if (game->ath->is_choosing)
            npc->state = CHOICE;
    } else {
        if (game->ath->dialog == npc->dialog)
            game->ath->dialog = NULL;
        npc->state = WAIT;
    }
    reset_dialog(npc, game);
    npc_process(npc, game->dt, game);
}

void draw_npc(game_t *game, void *et)
{
    npc_t *npc = CAST(npc_t *, et);
    sfRenderWindow_drawSprite(game->win, npc->sprite, NULL);
}

void destroy_npc(void *et)
{
    npc_t *e = CAST(npc_t *, et);
    free_npc(e);
}

void ready_npc(entity_t *e)
{
    (void)e;
}
