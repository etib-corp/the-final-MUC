/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** player_move
*/
#include "sfml_includes.h"

bool check_collisions(sfVector2f pos, int *collision)
{
    int a = (CAST(int, pos.x + 22) / 16) + 100 * (CAST(int, pos.y + 22) / 16);
    return (collision[a] != 0);
}

void move_player(player_t *p, int *collsion)
{
    float dt = 1.0 / (float)FPS;
    p->velocity.x = (SKP(KEYRIGHT) - SKP(KEYLEFT));
    p->velocity.y = (SKP(KEYDOWN) - SKP(KEYUP));
    p->velocity = normalize(p->velocity);
    p->velocity.x *= p->speed * dt;
    p->velocity.y *= p->speed * dt;
    p->pos = V2F(p->pos.x + p->velocity.x, p->pos.y + p->velocity.y);
    if (check_collisions(p->pos, collsion))
        p->pos = V2F(p->pos.x - p->velocity.x, p->pos.y - p->velocity.y);
    sfSprite_move(p->sprite, p->velocity);
    move_weapon(p->weapons, p->pos);
}

bool attack_player(player_t *p, game_t *game)
{
    int width = PLAYER_SIZE * 2;
    p->nb_texture = 6;
    if (p->velocity.x <= 0) {
        p->weapons[p->current_weapon]->hitbox->rect->left = p->pos.x -
        p->weapons[p->current_weapon]->hitbox->rect->width + 10;
        p->weapons[p->current_weapon]->hitbox->rect->top = p->pos.y;
    } else {
        p->weapons[p->current_weapon]->hitbox->rect->left = p->pos.x +
        p->weapons[p->current_weapon]->hitbox->rect->width + 10;
        p->weapons[p->current_weapon]->hitbox->rect->top = p->pos.y;
    } if (game->dt >= DT) {
        p->current_texture = (p->current_texture + 1) %
        p->nb_texture;
    } sfSprite_setTextureRect(p->sprite, (sfIntRect){p->current_texture * width
    , 0, width, PLAYER_SIZE});
    if (p->current_texture == 5) {
        p->state = PLAYER_IDLE;
        p->current_texture = 0;
        return false;
    } return true;
}
