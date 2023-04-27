/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** updata_score
*/

#include "sfml_includes.h"

void update_xp(player_t *player)
{
    if (player->xp >= 10) {
        player->lvl++;
        player->xp -= 10;
        if (player->lvl == 3 || player->lvl == 5)
            player->life++;
    }
}
