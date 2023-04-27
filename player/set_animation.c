/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** set_animation
*/

#include "sfml_includes.h"

void set_player_walk(player_t *player)
{
    if (SKP(KEYUP) && !SKP(KEYRUN)) {
        player->texture_ind = 3;
        player->nb_texture = 6;
    }
    if (SKP(KEYDOWN) && !SKP(KEYRUN)) {
        player->texture_ind = 4;
        player->nb_texture = 6;
    }
    if (SKP(KEYLEFT) && !SKP(KEYRUN)) {
        player->texture_ind = 1;
        player->nb_texture = 6;
    }
    if (SKP(KEYRIGHT) && !SKP(KEYRUN)) {
        player->texture_ind = 2;
        player->nb_texture = 6;
    }
}

void set_player_run(game_t *game, player_t *player)
{
    if (SKP(KEYLEFT) && SKP(KEYRUN)) {
        player->texture_ind = 5;
        player->nb_texture = 6;
    } if (SKP(KEYRIGHT) && SKP(KEYRUN)) {
        player->texture_ind = 6;
        player->nb_texture = 6;
    } if (SKP(KEYUP) && SKP(KEYRUN)) {
        player->texture_ind = 7;
        player->nb_texture = 6;
    } if (SKP(KEYDOWN) && SKP(KEYRUN)) {
        player->texture_ind = 8;
        player->nb_texture = 6;
    }
    player->speed = set_player_speed(game->chocobo->state);
    player->speed *= game->dt;
}

void chose_state_player(player_t *player, game_t *game)
{
    switch (player->state) {
    case PLAYER_MOVE:
        move_player(player, game->map->collisions);
        return get_new_map(player, game->map, game);
    case PLAYER_ATTACK:
        return;
    case PLAYER_IDLE:
        return;
    case PLAYER_DEAD:
        return;
    }
}

void set_player_idle(player_t *player)
{
    if (player->state == PLAYER_IDLE) {
        player->texture_ind = 0;
        player->nb_texture = 2;
    }
}

int set_player_attack(player_t *player, int width)
{
    if (player->state == PLAYER_ATTACK) {
        sfSprite_setPosition(player->sprite, V2F(player->pos.x - 22.0 * 0.75,
        player->pos.y));
        width = PLAYER_SIZE * 2;
        player->texture_ind = player->velocity.x <= 0 ? 9 : 10;
        player->nb_texture = 6;
    } else
        sfSprite_setPosition(player->sprite, V2F(player->pos.x,
        player->pos.y));
    return width;
}
