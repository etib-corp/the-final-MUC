/*
** EPITECH PROJECT, 2023
** npc.h
** File description:
** .h of npc
*/

#ifndef NPC_H_
    #define NPC_H_

    #include "sfml_includes.h"

    #define CHOICE_TEXTURE "assets/UI/choice_guard.png"
    #define FST_CHOICE "Yes !"
    #define SEC_CHOICE "Maybe\nlater..."

    #define NPC_TEST "assets/Characters/Idle-Rogue.png"

    void free_choice(choice_t *choice);
    void draw_choice(sfRenderWindow *win, choice_t *choice);
    void update_choice(choice_t *choice, game_t *game);
    choice_t *create_choice(sfFont const *font);
    void npc_process(npc_t *e, float dt, game_t *game);
    void free_npc(npc_t *npc);

    npc_t *init_npc(sfVector2f pos, dialog_t *dialog, char *texture);

    void process_npc(game_t *game, void *e);
    void draw_npc(game_t *game, void *et);
    void destroy_npc(void *et);
    void ready_npc(entity_t *e);

    void buy_apple(game_t *game);
    void buy_chocobo(game_t *game);
    void buy_weapon(game_t *game);
    void none_function(game_t *game);

#endif /* !NPC_H_ */
