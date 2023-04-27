/*
** EPITECH PROJECT, 2023
** enemy_move.c
** File description:
** all functions necessary to move the enemies
*/

#include "sfml_includes.h"

int my_random(int min, int max)
{
    return min + ((max - min + 1) * (rand() / (double) (RAND_MAX)));
}

sfVector2f get_new_pos(enemy_t *e, sfVector2f cur_pos)
{
    sfVector2f new_pos;
    new_pos.x = my_random(e->pos_min.x, e->pos_max.x);
    new_pos.y = my_random(e->pos_min.y, e->pos_max.y);
    e->end_pos = new_pos;
    return V2F(new_pos.x - cur_pos.x, new_pos.y - cur_pos.y);
}

void chase_player(enemy_t *e, sfVector2f player_pos, float dt)
{
    sfVector2f cur_pos = sfSprite_getPosition(e->sprite);
    sfVector2f new_pos = player_pos;
    sfVector2f dis = V2F(new_pos.x - cur_pos.x, new_pos.y - cur_pos.y);
    float hyp = sqrt(dis.x * dis.x + dis.y * dis.y);
    if (hyp < 5)
        return;
    sfVector2f ratio = V2F(dis.x / hyp, dis.y / hyp);
    sfVector2f move = V2F(ratio.x * e->speed, ratio.y * e->speed);
    move = normalize(move);
    move = V2F(move.x * e->speed * dt, move.y * e->speed * dt);
    set_enemy_animation(move, e);
    sfSprite_setTexture(e->sprite, e->textures[e->texture_ind], sfTrue);
    sfSprite_move(e->sprite, move);
    e->state = get_enemy_state(e, player_pos);
}

void rand_move(enemy_t *e, float dt)
{
    sfVector2f cur_pos = sfSprite_getPosition(e->sprite);
    sfVector2f new_pos = e->end_pos;
    sfVector2f dis = V2F(new_pos.x - cur_pos.x, new_pos.y - cur_pos.y);
    if ((abs((int)dis.x) < 5 && abs((int)dis.y) < 5) || (new_pos.x == -1 &&
    new_pos.y == -1))
        dis = get_new_pos(e, cur_pos);
    float hyp = sqrt(dis.x * dis.x + dis.y * dis.y);
    sfVector2f ratio = V2F(dis.x / hyp, dis.y / hyp);
    sfVector2f move = V2F(ratio.x * e->speed, ratio.y * e->speed);
    move = normalize(move);
    move = V2F(move.x * e->speed * dt, move.y * e->speed * dt);
    set_enemy_animation(move, e);
    sfSprite_setTexture(e->sprite, e->textures[e->texture_ind], sfTrue);
    sfSprite_move(e->sprite, move);
}

void ready_enemy(entity_t *e)
{
    (void)e;
}
