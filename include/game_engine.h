/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** game_engine
*/

#ifndef GAME_ENGINE_H_
    #define GAME_ENGINE_H_

    #define DT 0.125

    #include "sfml_includes.h"

    linked_list_t *get_entity_of_type(linked_list_t *head, int type);
    linked_list_t *get_next_entity_of_type(linked_list_t *head, int type);
    entity_t *sysdraw(list_t *head, game_t *game);
    void *constructor_entity(va_list *ap);
    void destroy_entity(void *data);
    int get_layers(char *path, map_t *map, game_t *game);
    box_t *init_box(sfVector2i dimensions, sfVector2i pos, int value);
    void move_box(box_t *box, sfVector2f move);
    void free_box(box_t *box);


#endif /* !GAME_ENGINE_H_ */
