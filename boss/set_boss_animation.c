/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** set_boss_animation
*/
#include "sfml_includes.h"

void set_boss_animation(boss_t *boss, sfVector2f player_pos)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(boss->sprite);
    float diffx = (boss->pos.x + rect.width / 2) - player_pos.x;
    float diffy = (boss->pos.y + rect.height / 2) - player_pos.y;
    if (diffx < 0 && fabsf(diffx) > fabsf(diffy)) {
        boss->texture_ind = 1;
        boss->nb_texture = 4;
    } if (diffx >= 0 && fabsf(diffx) > fabsf(diffy)) {
        boss->texture_ind = 0;
        boss->nb_texture = 4;
    } if (boss->life <= 0) {
        boss->texture_ind = 2;
        boss->nb_texture = 6;
    }
    sfSprite_setTexture(boss->sprite, boss->textures[boss->texture_ind],
    sfTrue);
}

void manage_boss_animation(boss_t *boss, float dt)
{
    if (dt >= DT) {
        boss->attack_time -= dt;
        boss->time_hit += dt;
        boss->current_texture = (boss->current_texture + 1) % boss->nb_texture;
    }
    if (boss->time_hit > 1.0)
        boss->hit = false;
    if (boss->texture_ind != 2)
        sfSprite_setTextureRect(boss->sprite,IR(32 * boss->current_texture, 0,
        32, 32));
    else
        sfSprite_setTextureRect(boss->sprite,IR(64 * boss->current_texture, 0,
        64, 64));
}

void set_boss_idle(boss_t *boss)
{
    boss->attack_time = 3.0;
}

int launch_minion(sfSprite *minion, sfVector2f player_pos, float dt)
{
    sfVector2f cur_pos = sfSprite_getPosition(minion);
    sfVector2f new_pos = player_pos;
    sfVector2f dis = V2F(new_pos.x - cur_pos.x, new_pos.y - cur_pos.y);
    float hyp = sqrt(dis.x * dis.x + dis.y * dis.y);
    if (hyp < 2)
        return 1;
    sfVector2f ratio = V2F(dis.x / hyp, dis.y / hyp);
    sfVector2f move = V2F(ratio.x * 2 * dt, ratio.y * 2 * dt);
    move = normalize(move);
    sfSprite_move(minion, move);
    return 0;
}

void set_boss_attack(boss_t *boss, float dt, sfVector2f player_pos)
{
    if (boss->player_pos.x == -1.0 && boss->player_pos.y == -1.0)
        boss->player_pos = player_pos;
    if (boss->attack_time <= 0.0 && !boss->is_launched) {
        boss->is_launched = true;
        boss->attack_time = 30.0;
    }
    if (boss->is_launched) {
        if (launch_minion(boss->minion, boss->player_pos, dt))
            boss->attack_time = 0.0;
        if (boss->attack_time <= 0.0) {
            boss->attack_time = 5.0;
            boss->state = BOSS_IDLE;
            boss->is_launched = false;
            boss->player_pos = V2F(-1, -1);
            sfSprite_setPosition(boss->minion, boss->pos);
        }
    }

}
