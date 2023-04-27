/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** enemy
*/
#include "sfml_includes.h"

bool is_inside_cirle(sfVector2f circ, sfVector2f rec, float radius)
{
    sfVector2f circle = V2F(circ.x + radius, circ.y + radius);
    sfVector2f distance = V2F(circle.x - rec.x, circle.y - rec.y);
    float length = sqrt(distance.x * distance.x + distance.y * distance.y);
    return length <= radius;
}

enum ENEMY_STATE get_enemy_state(enemy_t *e, sfVector2f pos)
{
    if (e->life < 1)
        return ENEMY_DIE;
    if (is_inside_cirle(sfCircleShape_getPosition(e->circle),
    V2F(pos.x + 22, pos.y + 22),
    sfCircleShape_getRadius(e->circle)))
        return ENEMY_FOCUS;
    return ENEMY_SEARCH;
}

enemy_t *create_enemy_2(enemy_t *new)
{
    sfVector2f pos = V2F(my_random(new->pos_min.x, new->pos_max.x),
    my_random(new->pos_min.y, new->pos_max.y));
    sfSprite_setPosition(new->sprite, pos);
    new->hitbox = init_box(V2I(11, 20), V2I(0, 0), 1);
    new->hurtbox = init_box(V2I(20, 20), V2I(0, 0), new->life);
    new->state = ENEMY_SEARCH;
    new->end_pos = V2F(-1, -1);
    sfSprite_setPosition(new->sprite, pos);
    new->type = 1;
    new->circle = sfCircleShape_create();
    new->is_draw = true;
    new->hit = false;
    new->time_hit = 0.0;
    sfCircleShape_setRadius(new->circle, 100);
    return new;
}

enemy_t *create_enemy(char life, sfVector2f *pos)
{
    enemy_t *new = malloc(sizeof(enemy_t));
    if (!new)
        return NULL;
    new->display = false;
    new->current_texture = 0;
    new->nb_texture = 3;
    new->texture_ind = 0;
    new->life = life;
    new->speed = 5;
    new->sprite = sfSprite_create();
    if (!new->sprite)
        return NULL;
    sfSprite_setScale(new->sprite, V2F(0.5, 0.5));
    new->pos_min = pos[0];
    new->pos_max = pos[1];
    return create_enemy_2(new);
}
