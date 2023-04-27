/*
** EPITECH PROJECT, 2023
** ath_entity.c
** File description:
** all functions to set the ath as an entity
*/

#include "sfml_includes.h"

void ready_ath(entity_t *e)
{
    e->instance = init_ath();
}

void process_ath(game_t *game, void *e)
{
    ath_t *ath = CAST(ath_t *, e);
    update_ath(ath, game->player, game);
}

void draw_ath(game_t *game, void *e)
{
    ath_t *ath = CAST(ath_t *, e);
    for (int i = 0; i < game->player->life; i++)
        sfRenderWindow_drawSprite(game->win, ath->health[i], NULL);
    sfRenderWindow_drawSprite(game->win, ath->block_sprite, NULL);
    sfRenderWindow_drawSprite(game->win, ath->weapon_sprite, NULL);
    sfRenderWindow_drawText(game->win, ath->text, NULL);
    sfRenderWindow_drawRectangleShape(game->win, game->ath->xp_bar, NULL);
    if (ath->dialog != NULL)
        draw_dialog(ath->dialog, game->win);
    if (ath->is_choosing)
        draw_choice(game->win, ath->choice);
    draw_inventory(ath->inventory, game->win);
}

void free_ath(ath_t *ath)
{
    sfTexture_destroy(ath->heart_texture);
    for (int i = 0; ath->health[i] != NULL; i++)
        sfSprite_destroy(ath->health[i]);
    free(ath->health);
    free(ath->level);
    sfText_destroy(ath->text);
    sfSprite_destroy(ath->block_sprite);
    sfSprite_destroy(ath->weapon_sprite);
    sfTexture_destroy(ath->block_texture);
    for (int i = 0; ath->weapon_textures != NULL &&
        ath->weapon_textures[i] != NULL; i++)
        sfTexture_destroy(ath->weapon_textures[i]);
    free(ath);
}

void destroy_ath(void *e)
{
    ath_t *gree = CAST(ath_t *, e);
    MY_FREE(gree, free_ath);
}
