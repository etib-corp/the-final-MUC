/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include "sfml_includes.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>

    #define FPS 60

    #define KEYUP sfKeyZ
    #define KEYLEFT sfKeyQ
    #define KEYDOWN sfKeyS
    #define KEYRIGHT sfKeyD
    #define KEYRUN sfKeyLShift
    #define KEYATTACK sfKeySpace

    #define PLAYER_SPEED 400
    #define PLAYER_RUN_SPEED 800
    #define PLAYER_MOUNT_SPEED 600
    #define PLAYER_RUN_MOUNT_SPEED 1200
    #define PLAYER_ACCELERATION 500
    #define PLAYER_DECELERATION 700

    #define ASSET_PLAYER_IDLE \
    "assets/Characters/player_asset/player_idle.png"

    #define ASSET_PLAYER_WALK_LEFT \
    "assets/Characters/player_asset/player_walk_left.png"

    #define ASSET_PLAYER_WALK_RIGHT \
    "assets/Characters/player_asset/player_walk_right.png"

    #define ASSET_PLAYER_WALK_UP \
    "assets/Characters/player_asset/player_walk_up.png"

    #define ASSET_PLAYER_WALK_DOWN \
    "assets/Characters/player_asset/player_walk_down.png"

    #define ASSET_PLAYER_RUN_LEFT \
    "assets/Characters/player_asset/player_run_left.png"

    #define ASSET_PLAYER_RUN_RIGHT \
    "assets/Characters/player_asset/player_run_right.png"

    #define ASSET_PLAYER_RUN_UP \
    "assets/Characters/player_asset/player_run_up.png"

    #define ASSET_PLAYER_RUN_DOWN \
    "assets/Characters/player_asset/player_run_down.png"

    #define ASSET_PLAYER_ATTACK_LEFT \
    "assets/Characters/player_asset/player_attack.png"

    #define ASSET_PLAYER_ATTACK_RIGHT \
    "assets/Characters/player_asset/player_attack_right.png"

    #define ASSET_PLAYER_DEAD \
    "assets/Characters/player_asset/player_dead.png"

    #define SKP(KEY) sfKeyboard_isKeyPressed(KEY)

    #define NB_ANIM 12

    #define PLAYER_SIZE 44

    #define COLOR(R, G, B, A) (sfColor){\
    R, G, B, A\
    }

    #define GETTYPE(list, type) \
    LIST_FOREACH_DECL_BASIC(list, elem) { \
        if (CAST(entity_t *, elem->data)->type == type) { \
            CAST(entity_t *, elem->data) \
            break; \
        } \
    }

    bool set_player_dead(player_t *player);
    sfVector2f normalize(sfVector2f vec);
    player_t *init_player(player_data_t data);
    sfTexture **init_textures(void);
    void move_player(player_t *p, int *collision);
    enum PLAYER_STATE get_state(player_t *, enum CHOCOBO_STATE);
    void player_process(game_t *game, player_t *player);
    void move_weapon(weapon_t **weapon, sfVector2f move);
    bool attack_player(player_t *p, game_t *game);
    void set_player_walk(player_t *player);
    void set_player_run(game_t *game, player_t *player);
    void chose_state_player(player_t *player, game_t *game);
    int set_player_attack(player_t *player, int width);
    void set_player_idle(player_t *player);
    weapon_t **set_weapons(sfVector2f pos);

    void update_xp(player_t *player);
    void ready_player(entity_t *e);
    void process_player(game_t *game, void *e);
    void draw_player(game_t *game, void *e);
    void destroy_player(void *e);
    void free_player(player_t *player);
    int set_player_speed(enum CHOCOBO_STATE state);

#endif /* !PLAYER_H_ */
