/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** player_physics
*/
#include "sfml_includes.h"


enum PLAYER_STATE get_state(player_t *player, enum CHOCOBO_STATE stats)
{
    if (player->life < 1)
        return PLAYER_DEAD;
    if (SKP(KEYATTACK) && stats != CHOCO_MOUNT)
        return PLAYER_ATTACK;
    if (SKP(KEYUP) || SKP(KEYDOWN) || SKP(KEYLEFT) || SKP(KEYRIGHT))
        return PLAYER_MOVE;
    return PLAYER_IDLE;
}

void change_animation(game_t *game, player_t *player, int width)
{
    sfSprite_setTexture(player->sprite, player->textures[player->texture_ind],
    sfTrue);
    if (game->dt >= DT) {
        player->time_hit += game->dt;
        player->current_texture = (player->current_texture + 1) %
        player->nb_texture;
    }
    if (player->time_hit > 2.0)
        player->hit = false;
    sfSprite_setTextureRect(player->sprite, (sfIntRect){player->
    current_texture * width, 0, width, PLAYER_SIZE});
}

void set_view_center(game_t *game, player_t *player)
{
    sfVector2f center = V2F(0, 0);
    if (player->state == PLAYER_ATTACK) {
        center.x = (player->pos.x + sfSprite_getGlobalBounds
        (player->sprite).width / 2) - 22 * 0.75;
        center.y = player->pos.y + sfSprite_getGlobalBounds
        (player->sprite).height / 2;
    } else {
        center.x = player->pos.x + sfSprite_getGlobalBounds
        (player->sprite).width / 2;
        center.y = player->pos.y + sfSprite_getGlobalBounds
        (player->sprite).height / 2;
    }
    sfView_setCenter(game->view->player, center);
}

void update_weapon(player_t *player)
{
    if (SKP(sfKeyNum1))
        player->current_weapon = 0;
    if (SKP(sfKeyNum2) && player->max_weapon >= 1)
        player->current_weapon = 1;
    if (SKP(sfKeyNum3) && player->max_weapon >= 2)
        player->current_weapon = 2;
}

void player_process(game_t *game, player_t *player)
{
    int width = PLAYER_SIZE;
    if (player->state == PLAYER_ATTACK)
        if (attack_player(player, game))
            return;
    if (player->state != PLAYER_IDLE &&
    (player->state = get_state(player, game->chocobo->state)) == PLAYER_IDLE)
        player->current_texture = 0;
    player->state = get_state(player, game->chocobo->state);
    update_xp(player);
    set_player_idle(player);
    set_player_walk(player);
    set_player_run(game, player);
    game->over = set_player_dead(player);
    width = set_player_attack(player, width);
    change_animation(game, player, width);
    chose_state_player(player, game);
    set_view_center(game, player);
    update_weapon(player);
}
