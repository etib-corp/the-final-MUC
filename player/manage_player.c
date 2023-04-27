/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** manage_player
*/

#include "sfml_includes.h"

void ready_player(entity_t *e)
{
    (void)e;
}

void process_player(game_t *game, void *e)
{
    player_t *player = CAST(player_t *, e);
    player->rect->left = player->pos.x + 11;
    player->rect->top = player->pos.y + 6;
    player->hurtbox->rect->left = player->pos.x + 13;
    player->hurtbox->rect->top = player->pos.y + 14;
    player_process(game, player);
}

void draw_player(game_t *game, void *e)
{
    player_t *player = CAST(player_t *, e);
    if (player->hit && player->life >= 1 &&
    fmodf(player->time_hit, 0.25) <= 0.05) {
        return;
    }
    sfRenderWindow_drawSprite(game->win, player->sprite, NULL);
}

void destroy_player(void *e)
{
    player_t *gree = CAST(player_t *, e);
    MY_FREE(gree, free_player);
}

void free_player(player_t *player)
{
    if (player != NULL)
        return;
    MY_FREE(player->sprite, sfSprite_destroy);
    for (int i = 0; i < NB_ANIM; i++)
        MY_FREE(player->textures[i], sfTexture_destroy);
    MY_FREE(player->textures, free);
    MY_FREE(player, free);
}
