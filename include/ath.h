/*
** EPITECH PROJECT, 2023
** ath.h
** File description:
** .h of ath system
*/

#ifndef ATH_H_
    #define ATH_H_

    #include "sfml_includes.h"

    #define HEART "assets/heart.png"
    #define WEAPON_BLOCK "assets/UI/current_weapon.png"
    #define DAGGER "assets/Weapons/dagger.png"
    #define SWORD "assets/Weapons/sword.png"
    #define AXE "assets/Weapons/axe.png"

    ath_t *init_ath(void);
    void update_ath(ath_t *ath, player_t *player, game_t *game);

    void ready_ath(entity_t *e);
    void process_ath(game_t *game, void *e);
    void draw_ath(game_t *game, void *e);
    void destroy_ath(void *e);

    sfRectangleShape *create_rectangle(sfVector2f size, sfVector2f pos,
        sfColor color);
    void update_xpbar(int xp, sfRectangleShape *rect);


#endif /* !ATH_H_ */
