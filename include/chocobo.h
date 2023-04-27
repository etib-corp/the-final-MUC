/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** chocobo
*/

#ifndef CHOCOBO_H_
    #define CHOCOBO_H_

    #include "sfml_includes.h"

    void process_chocobo(game_t *game, void *e);
    void drawn_chocobo(game_t *game, void *e);
    void ready_chocobo(entity_t *e);
    chocobo_t *init_chocobo(sfVector2f pos_max, sfVector2f pos_min);
    void free_chocobo(chocobo_t *chocobo);
    void destroy_chocobo(void *e);
    void chocobo_process(game_t *game, chocobo_t *chocobo);
    int rand_move_chocobo(chocobo_t *e, float dt);
    void set_chocobo_animation(sfVector2f velocity, chocobo_t *e);
    void animate_chocobo(chocobo_t *e, float dt, int w, int h);
    sfVector2f get_new_pos_chocobo(chocobo_t *e, sfVector2f cur_pos);
    void animate_chocobo(chocobo_t *e, float dt, int w, int h);
    void set_chocobo_animation(sfVector2f velocity, chocobo_t *e);
    void whistle(chocobo_t *chocobo);
    void chocobo_idle(chocobo_t *e, float dt);
    enum CHOCOBO_STATE follow_player(chocobo_t *chocobo, sfVector2f player_pos,
    sfVector2f player_velocity, float dt);
    bool chocobo_is_mountable(sfVector2f pos, sfFloatRect re);
    void chocobo_process(game_t *game, chocobo_t *chocobo);
    int chocobo_chase_player(chocobo_t *e, sfVector2f player_pos, float dt);


#endif /* !CHOCOBO_H_ */
