/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** entity_collide
*/

#include "sfml_includes.h"

void boss_collide(player_t *player, linked_list_t *head)
{
    boss_t *boss = NULL;
    while ((head = get_next_entity_of_type(head, 9)) != NULL) {
        boss = CAST(boss_t *,list_to_entity(head)->instance);
        if (check_collision(player->weapons[player->current_weapon]->hitbox->
        rect, boss->hurtbox->rect) && player->state == PLAYER_ATTACK &&
        !boss->hit) {
            boss->life -= player->weapons[player->current_weapon]->hitbox->
            value;
            boss->time_hit = 0.0;
            boss->hit = true;
        }
        if (check_collision(player->hurtbox->rect, boss->hitbox->rect) &&
        !player->hit && player->life > 0) {
            player->life -= boss->hitbox->value;
            player->hit = true;
            player->time_hit = 0.0;
            boss->state = BOSS_ATTACK;
        }
    }
}

void entity_collide(player_t *player, linked_list_t *head,
enum CHOCOBO_STATE mount)
{
    enemy_t *enemy = NULL;
    while ((head = get_next_entity_of_type(head, 1)) != NULL) {
        enemy = CAST(enemy_t *,list_to_entity(head)->instance);
        if (check_collision(player->weapons[player->current_weapon]->hitbox->
        rect, enemy->hurtbox->rect) && player->state == PLAYER_ATTACK &&
        !enemy->hit) {
            enemy->life -= player->weapons[player->current_weapon]->hitbox->
            value;
            enemy->time_hit = 0.0;
            enemy->hit = true;
        }
        if (check_collision(player->hurtbox->rect, enemy->hitbox->rect) &&
        !player->hit && player->life > 0 && mount != CHOCO_MOUNT) {
            player->life -= enemy->hitbox->value;
            player->hit = true;
            player->time_hit = 0.0;
            enemy->state = ENEMY_ATTACK;
        }
    }
}
