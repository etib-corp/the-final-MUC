/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** process_chocobo
*/

#include "sfml_includes.h"

void chocobo_idle(chocobo_t *e, float dt)
{
    e->time_state += dt;
    if (e->time_state > 12) {
        e->time_state = 0;
        e->end_pos = V2F(my_random(e->pos_min.x, e->pos_max.x),
        my_random(e->pos_min.y, e->pos_max.y));
        e->state = CHOCO_MOVE;
        return;
    }
    set_chocobo_animation(V2F(0, 0), e);
    sfSprite_setTexture(e->sprite, e->textures[e->texture_ind], sfTrue);
}

enum CHOCOBO_STATE follow_player(chocobo_t *chocobo, sfVector2f player_pos,
sfVector2f player_velocity, float dt)
{
    sfSprite_setPosition(chocobo->sprite, player_pos);
    set_chocobo_animation(player_velocity, chocobo);
    sfSprite_setTexture(chocobo->sprite,
    chocobo->textures[chocobo->texture_ind], sfTrue);
    if (chocobo->texture_ind == 1 || chocobo->texture_ind == 2)
        animate_chocobo(chocobo, dt, 32, 32);
    else
        animate_chocobo(chocobo, dt, 16, 32);
    return CHOCO_MOUNT;
}

bool chocobo_is_mountable(sfVector2f pos, sfFloatRect re)
{
    return sfFloatRect_intersects(&re, &FR(pos.x - 50, pos.y - 50, 100, 100)
    , NULL);
}

void chocobo_process(game_t *game, chocobo_t *chocobo)
{
    switch (chocobo->state) {
    case CHOCO_IDLE:
        chocobo_idle(chocobo, game->dt);
        break;
    case CHOCO_MOVE:
        chocobo->state = rand_move_chocobo(chocobo, game->dt);
        break;
    case CHOCO_WHISTLE:
        chocobo->state = chocobo_chase_player(chocobo, game->player->pos,
        game->dt);
        break;
    case CHOCO_MOUNT:
        game->player->speed = 600;
        chocobo->state = follow_player(chocobo, game->player->pos,
        game->player->velocity, game->dt);
        break;
    } if (chocobo->texture_ind == 1 || chocobo->texture_ind == 2)
        animate_chocobo(chocobo, game->dt, 32, 32);
    else
        animate_chocobo(chocobo, game->dt, 16, 32);
}
