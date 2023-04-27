/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** boss
*/

#ifndef BOSS_H_
    #define BOSS_H_

    #include "sfml_includes.h"

    void boss_process(game_t *t, boss_t *boss);
    boss_t *create_boss(void);
    void destroy_boss(void *e);
    void draw_boss(game_t *game, void *e);
    enum BOSS_STATE get_boss_state(boss_t *boss, sfVector2f pos);
    void init_boss_textures(boss_t *boss);
    void manage_boss_animation(boss_t *boss, float dt);
    void process_boss(game_t *game, void *e);
    void ready_boss(void *e);
    void set_boss_animation(boss_t *boss, sfVector2f player_pos);
    void set_boss_attack(boss_t *boss, float dt, sfVector2f player_pos);
    void set_boss_die(boss_t *boss);
    void set_boss_idle(boss_t *boss);
    void set_boss_die(boss_t *boss);

#endif /* !BOSS_H_ */
