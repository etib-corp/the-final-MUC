/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** change_map
*/

#include "sfml_includes.h"

void teleport_chocobo(char *file, chocobo_t *chocobo, sfVector2f player_pos)
{
    if (my_strcmp(file, "assets/map_houses.json") == 0 &&
    chocobo->state == CHOCO_MOUNT) {
        chocobo->state = CHOCO_IDLE;
        return;
    }
    sfSprite_setPosition(chocobo->sprite, player_pos);
}

void get_new_map(player_t *player, map_t *mapt, game_t *game)
{
    map_t *tmp = game->map;
    for (int i = 0; mapt->n_teleport > i; i++) {
        if (sfIntRect_contains(&mapt->teleports[i].rec,
        player->pos.x + 22, player->pos.y + 22)) {
            game->player->pos = tmp->teleports[i].pos_player;
            teleport_chocobo(tmp->teleports[i].path_map, game->chocobo,
            player->pos);
            game->map = init_map(tmp->teleports[i].path_map,
            mapt->teleports[i].path_enemy, game);
            game->map->states = set_states(game->world);
            free_map(tmp);
        }
    }
}
