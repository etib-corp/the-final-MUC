/*
** EPITECH PROJECT, 2023
** weapon.c
** File description:
** all functions relatives to weapons
*/

#include "sfml_includes.h"

weapon_t *create_weapon(sfVector2f pos, sfVector2i dimensions, int value)
{
    weapon_t *new = malloc(sizeof(weapon_t));

    if (new == NULL)
        return NULL;
    new->hitbox = init_box(dimensions,
        V2I((int)pos.x, (int)pos.y), value);
    new->pos = V2F(pos.x, pos.y);
    return new;
}

weapon_t **set_weapons(sfVector2f pos)
{
    weapon_t **weapons = malloc(sizeof(weapon_t) * (4));
    int i = 0;
    int range = 25;

    if (weapons == NULL)
        return NULL;
    for ( ; i < 3; i++) {
        weapons[i] = create_weapon(pos, V2I(range, range), i + 1);
        range += 8;
    } weapons[i] = NULL;
    return weapons;
}

void move_weapon(weapon_t **weapon, sfVector2f move)
{
    for (int i = 0; weapon[i] != NULL; i++) {
        move_box(weapon[i]->hitbox, move);
        weapon[i]->pos.x = move.x;
        weapon[i]->pos.y = move.y;
    }
}
