/*
** EPITECH PROJECT, 2023
** enemy_animations.c
** File description:
** all functions to animate an enemy
*/

#include "sfml_includes.h"

void set_enemy_animation(sfVector2f velocity, enemy_t *e)
{
    if (velocity.y > 0) {
        e->texture_ind = 1;
        e->nb_texture = 6;
    } if (velocity.y < 0) {
        e->texture_ind = 2;
        e->nb_texture = 6;
    } if (velocity.x > 0) {
        e->texture_ind = 2;
        e->nb_texture = 6;
    } if (velocity.x < 0) {
        e->texture_ind = 1;
        e->nb_texture = 6;
    } if (velocity.x == 0 && velocity.y == 0) {
        e->texture_ind = 0;
        e->nb_texture = 6;
    }
}

void animate_enemy(enemy_t *e, float dt, int w, int h)
{
    if (dt >= DT)   {
        e->current_texture = (e->current_texture + 1) % e->nb_texture;
        e->time_hit += dt;
    }
    if (e->time_hit > 1.0)
        e->hit = false;
    sfSprite_setTextureRect(e->sprite, IR(e->current_texture * w, 0, w, h));
}
