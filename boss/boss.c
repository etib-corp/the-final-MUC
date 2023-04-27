/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** boss
*/
#include "sfml_includes.h"

void set_boss_die(boss_t *boss)
{
    (void)boss;
}

enum BOSS_STATE get_boss_state(boss_t *boss, sfVector2f pos)
{
    if (boss->life <= 0)
        return BOSS_DIE;
    bool inside = is_inside_cirle(sfCircleShape_getPosition(boss->zone), pos,
    sfCircleShape_getRadius(boss->zone));

    if (!inside)
        return BOSS_IDLE;
    if (inside)
        return BOSS_ATTACK;
    return BOSS_IDLE;
}

void init_boss_textures(boss_t *boss)
{
    boss->sprite = sfSprite_create();
    sfSprite_setPosition(boss->sprite, boss->pos);
    sfSprite_setScale(boss->sprite, V2F(3, 3));
    sfTexture **new = malloc(sizeof(sfTexture*) * 3);
    new[0] = sfTexture_createFromFile("assets/Enemies/Orcs/Idle-Orc-left.png",
    NULL);
    new[1] = sfTexture_createFromFile("assets/Enemies/Orcs/Idle-Orc.png",
    NULL);
    new[2] = sfTexture_createFromFile("assets/Enemies/Orcs/Death-Orc.png",
    NULL);
    boss->textures = new;
    boss->minion = sfSprite_create();
    sfSprite_setScale(boss->minion, V2F(0.5, 0.5));
    sfSprite_setPosition(boss->minion, boss->pos);
    sfSprite_setTexture(boss->minion, boss->textures[2], sfTrue);
    sfSprite_setTextureRect(boss->minion, IR(192, 0, 64, 64));
    boss->is_launched = false;
    boss->hit = false;
    boss->time_hit = 0.0;
}

boss_t *create_boss(void)
{
    boss_t *new = malloc(sizeof(boss_t));
    if (!new)
        return NULL;
    new->current_texture = 0; new->pos = V2F(960, 424);
    init_boss_textures(new);
    sfFloatRect rect = sfSprite_getGlobalBounds(new->sprite);
    new->hitbox = init_box(V2I(10, 10), V2I(960, 424), 1);
    new->hurtbox = init_box(V2I(50, 75), V2I(rect.left + 14, rect.top + 14),
    10);
    new->texture_ind = 0;
    new->nb_texture = 4;
    new->state = BOSS_IDLE;
    new->life = 10;
    new->attack_time = 20.0;
    new->player_pos = V2F(-1, -1);
    new->zone = sfCircleShape_create();
    sfCircleShape_setRadius(new->zone, 75);
    sfCircleShape_setPosition(new->zone,
    V2F(rect.left - 75 + rect.width, rect.top - 75 + rect.height));
    return new;
}
