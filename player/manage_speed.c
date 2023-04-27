/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** manage_speed
*/
#include "sfml_includes.h"

int set_player_speed(enum CHOCOBO_STATE state)
{
    if (state != CHOCO_MOUNT && SKP(KEYRUN))
        return PLAYER_RUN_SPEED;
    if (state == CHOCO_MOUNT && SKP(KEYRUN))
        return PLAYER_RUN_MOUNT_SPEED;
    if (state == CHOCO_MOUNT)
        return PLAYER_MOUNT_SPEED;
    else
        return PLAYER_SPEED;
}

bool set_player_dead(player_t *player)
{
    if (player->state == PLAYER_DEAD) {
        player->nb_texture = 6;
        player->texture_ind = 11;
        if (player->current_texture >= 5)
            return true;
    }
    return false;
}
