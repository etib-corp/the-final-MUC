/*
** EPITECH PROJECT, 2023
** manage_enemy.c
** File description:
** all functions which manage enemies
*/

#include "sfml_includes.h"

void process_enemy(game_t *game, void *e)
{
    enemy_t *enemy = CAST(enemy_t *, e);
    if (!enemy->is_draw)
        return;

    sfFloatRect rect = sfSprite_getGlobalBounds(enemy->sprite);
    enemy->hurtbox->rect->left = rect.left + 11;
    enemy->hurtbox->rect->top = rect.top + 11;
    enemy->hitbox->rect->left = rect.left + 11;
    enemy->hitbox->rect->top = rect.top + 11;
    enemy_process(game, enemy);
    sfCircleShape_setPosition(enemy->circle, V2F(rect.left - 100 + rect.width,
    rect.top - 100 + rect.height));
}

void draw_enemy(game_t *game, void *et)
{
    enemy_t *e = CAST(enemy_t *, et);
    if (!e->is_draw)
        return;
    if (e->hit && e->life >= 1 && fmodf(e->time_hit, 0.25) <= 0.05)
        return;
    sfRenderWindow_drawSprite(game->win, e->sprite, NULL);
}

void destroy_enemy(void *et)
{
    enemy_t *e = CAST(enemy_t *, et);
    MY_FREE(e->sprite, sfSprite_destroy);
    for (int i = 0; i < 5; i++)
        MY_FREE(e->textures[i], sfTexture_destroy);
    MY_FREE(e->textures, free);
    MY_FREE(e, free);
}

void enemy_dead(game_t *game, enemy_t *e)
{
    if (e->current_texture >= 5) {
        game->player->xp += 1 + rand() % 5;
        game->player->coins += 1 + rand() % 3;
        e->is_draw = false;
        sfSprite_setPosition(e->sprite, V2F(-1, -1));
    }
    set_enemy_animation(V2F(0, 0), e);
    sfSprite_setTexture(e->sprite, e->textures[e->texture_ind], sfTrue);
    return animate_enemy(e, game->dt, 64, 48);
}

void enemy_process(game_t *game, enemy_t *e)
{
    e->state = get_enemy_state(e, game->player->pos);
    switch (e->state) {
    case ENEMY_ATTACK:
        return;
    case ENEMY_SEARCH: {
        rand_move(e, game->dt);
        return animate_enemy(e, game->dt, 64, 64);
    }
    case ENEMY_FOCUS:
        chase_player(e, game->player->pos, game->dt);
        return animate_enemy(e, game->dt, 64, 64);
    case ENEMY_DIE:
        return enemy_dead(game, e);
    }
}
