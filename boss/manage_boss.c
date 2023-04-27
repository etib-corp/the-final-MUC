/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** manage_boss
*/
#include "sfml_includes.h"

void ready_boss(void *e)
{
    (void)e;
}

void process_boss(game_t *game, void *e)
{
    boss_t *boss = CAST(boss_t *, e);
    boss->attack_time -= game->dt;
    boss->state = get_boss_state(boss, game->player->pos);
    sfVector2f tmp = sfSprite_getPosition(boss->minion);
    boss->hitbox->rect->left = tmp.x + 15;
    boss->hitbox->rect->top = tmp.y + 25;
    boss_process(game, boss);
}

void draw_boss(game_t *game, void *e)
{
    boss_t *boss = CAST(boss_t *, e);
    if (boss->is_launched)
        sfRenderWindow_drawSprite(game->win, boss->minion, NULL);
    if (boss->hit && boss->life >= 1 && fmodf(boss->time_hit, 0.25) <= 0.05)
        return;
    sfRenderWindow_drawSprite(game->win, boss->sprite, NULL);

}

void destroy_boss(void *e)
{
    boss_t *boss = CAST(boss_t *, e);
    MY_FREE(boss->hitbox, free_box);
    MY_FREE(boss->hurtbox, free_box);
    MY_FREE(boss->sprite, sfSprite_destroy);
    for (int i = 0; i < 4; i++)
        MY_FREE(boss->textures[i], sfTexture_destroy);
    MY_FREE(boss->textures, free);
    MY_FREE(boss->zone, sfCircleShape_destroy);
    MY_FREE(boss, free);
}

void boss_process(game_t *game, boss_t *boss)
{
    set_boss_animation(boss, game->player->pos);
    manage_boss_animation(boss, game->dt);
    boss->state = get_boss_state(boss, game->player->pos);
    switch (boss->state) {
    case BOSS_IDLE:
    return set_boss_attack(boss, game->dt, game->player->pos);

    case BOSS_ATTACK:
        return set_boss_attack(boss, game->dt, game->player->pos);
    case BOSS_DIE:
        game->state = GAME_WIN;
        return set_boss_die(boss);
    }
}
