/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** animation_chocobo
*/

#include "sfml_includes.h"

void animate_chocobo(chocobo_t *e, float dt, int w, int h)
{
    if (dt >= DT)   {
        e->current_texture = (e->current_texture + 1) % e->nb_texture;
    }
    sfSprite_setTextureRect(e->sprite, IR(e->current_texture * w, 0, w, h));
}

void set_chocobo_animation(sfVector2f velocity, chocobo_t *e)
{
    if (velocity.y > 0) {
        e->texture_ind = 4;
        e->nb_texture = 3;
    } if (velocity.y < 0) {
        e->texture_ind = 3;
        e->nb_texture = 3;
    } if (velocity.x > 0) {
        e->texture_ind = 2;
        e->nb_texture = 3;
    } if (velocity.x < 0) {
        e->texture_ind = 1;
        e->nb_texture = 3;
    } if (velocity.x == 0 && velocity.y == 0) {
        e->texture_ind = 0;
        e->nb_texture = 3;
    }
}
