/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** quadtree
*/

#ifndef QUADTREE_H_
    #define QUADTREE_H_

    #include "sfml_includes.h"

    bool add(quadtree_t *qt, linked_list_t *entity);
    quadtree_t *create_quadtree(sfFloatRect rect, int depth);
    void insert_quadtree(quadtree_t *qt, list_t *entity);
    void watch_colision(linked_list_t *head, enum CHOCOBO_STATE mount);
    int collide(quadtree_t *qt, enum CHOCOBO_STATE mount);
    void free_quadtree(quadtree_t **qt);
    void entity_collide(player_t *player, linked_list_t *head,
    enum CHOCOBO_STATE mount);
    void boss_collide(player_t *player, linked_list_t *head);
    entity_t *list_to_entity(linked_list_t *node);
    bool check_collision(sfIntRect *a, sfIntRect *b);
#endif /* !QUADTREE_H_ */
