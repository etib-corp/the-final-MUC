/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** chocobo_move
*/

#include "sfml_includes.h"

sfVector2f get_new_pos_chocobo(chocobo_t *e, sfVector2f cur_pos)
{
    sfVector2f new_pos;
    new_pos.x = my_random(e->pos_min.x, e->pos_max.x);
    new_pos.y = my_random(e->pos_min.y, e->pos_max.y);
    e->end_pos = new_pos;
    return V2F(new_pos.x - cur_pos.x, new_pos.y - cur_pos.y);
}

int rand_move_chocobo(chocobo_t *e, float dt)
{
    sfVector2f cur_pos = sfSprite_getPosition(e->sprite);
    sfVector2f new_pos = e->end_pos;
    sfVector2f dis = V2F(new_pos.x - cur_pos.x, new_pos.y - cur_pos.y);
    if ((abs((int)dis.x) < 5 && abs((int)dis.y) < 5) || (new_pos.x == -1 &&
    new_pos.y == -1))
        return 1;
    float hyp = sqrt(dis.x * dis.x + dis.y * dis.y);
    sfVector2f ratio = V2F(dis.x / hyp, dis.y / hyp);
    sfVector2f move = V2F(ratio.x * e->speed * dt, ratio.y * e->speed * dt);
    move = normalize(move);
    set_chocobo_animation(move, e);
    sfSprite_setTexture(e->sprite, e->textures[e->texture_ind], sfTrue);
    sfSprite_move(e->sprite, move);
    return 0;
}

int chocobo_chase_player(chocobo_t *e, sfVector2f player_pos, float dt)
{
    sfVector2f cur_pos = sfSprite_getPosition(e->sprite);
    sfVector2f new_pos = player_pos;
    sfVector2f dis = V2F(new_pos.x - cur_pos.x, new_pos.y - cur_pos.y);
    float hyp = sqrt(dis.x * dis.x + dis.y * dis.y);
    if (hyp < 16)
        return 1;
    sfVector2f ratio = V2F(dis.x / hyp, dis.y / hyp);
    sfVector2f move = V2F(ratio.x * e->speed * dt, ratio.y * e->speed * dt);
    move = normalize(move);
    set_chocobo_animation(move, e);
    sfSprite_setTexture(e->sprite, e->textures[e->texture_ind], sfTrue);
    sfSprite_move(e->sprite, move);
    sfVector2f pos = sfSprite_getPosition(e->sprite);
    e->pos_min = V2F(pos.x - 50, pos.y - 50);
    e->pos_max = V2F(pos.x + 50, pos.y + 50);
    return 2;
}
