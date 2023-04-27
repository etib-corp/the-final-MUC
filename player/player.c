/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** player
*/
#include "sfml_includes.h"

sfTexture **init_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture*) * NB_ANIM);
    if (textures == NULL)
        return NULL;
    textures[0] = sfTexture_createFromFile(ASSET_PLAYER_IDLE, NULL);
    textures[1] = sfTexture_createFromFile(ASSET_PLAYER_WALK_LEFT, NULL);
    textures[2] = sfTexture_createFromFile(ASSET_PLAYER_WALK_RIGHT, NULL);
    textures[3] = sfTexture_createFromFile(ASSET_PLAYER_RUN_UP, NULL);
    textures[4] = sfTexture_createFromFile(ASSET_PLAYER_WALK_DOWN, NULL);
    textures[5] = sfTexture_createFromFile(ASSET_PLAYER_RUN_LEFT, NULL);
    textures[6] = sfTexture_createFromFile(ASSET_PLAYER_RUN_RIGHT, NULL);
    textures[7] = sfTexture_createFromFile(ASSET_PLAYER_RUN_UP, NULL);
    textures[8] = sfTexture_createFromFile(ASSET_PLAYER_RUN_DOWN, NULL);
    textures[9] = sfTexture_createFromFile(ASSET_PLAYER_ATTACK_LEFT, NULL);
    textures[10] = sfTexture_createFromFile(ASSET_PLAYER_ATTACK_RIGHT, NULL);
    textures[11] = sfTexture_createFromFile(ASSET_PLAYER_DEAD, NULL);
    for (int i = 0; i < NB_ANIM; i++)
        if (textures[i] == NULL)
            return NULL;
    return textures;
}

player_t *init_player(player_data_t data)
{
    player_t *player = malloc(sizeof(player_t));
    if (player == NULL)
        return NULL;
    player->hit = false; player->choco = data.chocobo;
    player->speed = PLAYER_SPEED; player->max_weapon = 0;
    player->life = data.life;
    player->lvl = data.level;
    player->coins = data.coins;
    player->textures = init_textures();
    player->sprite = sfSprite_create();
    player->xp = data.xp; player->texture_ind = 0;
    sfSprite_setScale(player->sprite, V2F(0.75, 0.75));
    player->velocity = V2F(0, 0); player->pos = data.pos;
    player->rect = &IR(player->pos.x + 11, player->pos.y + 6, 11, 25);
    sfSprite_setPosition(player->sprite, player->pos);
    player->state = PLAYER_IDLE;
    player->current_weapon = data.weapon;
    player->weapons = set_weapons(player->pos);
    player->hurtbox = init_box(V2I(7, 15), V2I(player->pos.x + 11, player->
    pos.y + 6), player->life); return player;
}
