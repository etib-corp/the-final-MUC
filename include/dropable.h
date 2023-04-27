/*
** EPITECH PROJECT, 2023
** dropable.h
** File description:
** .h of dropable item
*/

#ifndef DROPABLE_H_
    #define DROPABLE_H_

    #include "sfml_includes.h"

    #define APPLE "assets/apple.png"

    dropable_t *create_dropable(char *tex, char *nam, char *in, sfVector2f pos);
    void free_dropable(dropable_t *item);
    void update_dropable(player_t *player, void *e, inventory_t *inv);

    void destroy_dropable(void *e);
    void draw_dropable(game_t *game, void *e);
    void process_dropable(game_t *game, void *e);
    void ready_dropable(entity_t *e);

#endif /* !DROPABLE_H_ */
