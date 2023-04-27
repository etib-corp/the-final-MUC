/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** enemy
*/

#ifndef ENEMY_H_
    #define ENEMY_H_

    #include "sfml_includes.h"

    #define SKELL_DEATH "assets/Enemies/Skells/Death-WarriorSkells.png"
    #define SKELL_LEFT "assets/Enemies/Skells/Run-WarriorSkells-leftt.png"
    #define SKELL_RIGHT "assets/Enemies/Skells/Run-WarriorSkells.png"

    #define MAGE_DEATH "assets/Enemies/Skells/Death-MageSkells.png"
    #define MAGE_LEFT "assets/Enemies/Skells/run-MageSkells-left.png"
    #define MAGE_RIGHT "assets/Enemies/Skells/run-MageSkells.png"

    #define ROGUE_DEATH "assets/Enemies/Skells/Death-RogueSkells.png"
    #define ROGUE_LEFT "assets/Enemies/Skells/Run-RogueSkells-letf.png"
    #define ROGUE_RIGHT "assets/Enemies/Skells/Run-RogueSkells.png"

    void enemy_process(game_t *game, enemy_t *e);
    enemy_t *create_enemy(char, sfVector2f *);
    void process_enemy(game_t *game, void *e);
    void draw_enemy(game_t *game, void *e);
    void destroy_enemy(void *e);
    sfTexture **init_skeleton_textures(void);
    void ready_enemy(entity_t *e);
    void set_enemy_animation(sfVector2f velocity, enemy_t *e);
    void animate_enemy(enemy_t *e, float dt, int w, int h);
    void rand_move(enemy_t *e, float dt);
    void chase_player(enemy_t *e, sfVector2f player_pos, float dt);
    enum ENEMY_STATE get_enemy_state(enemy_t *e, sfVector2f pos);
    void enemy_process(game_t *game, enemy_t *e);
    bool is_inside_cirle(sfVector2f circ, sfVector2f rec, float radius);
    //void attack_enemy(enemy_t *e, game_t *game);
    int my_random(int min, int max);
    sfTexture **init_skeleton_textures(void);
    sfTexture **init_rogue_textures(void);
    sfTexture **init_mage_textures(void);

#endif /* !ENEMY_H_ */
