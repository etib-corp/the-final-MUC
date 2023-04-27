/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** free
*/

#ifndef FREE_H_
    #define FREE_H_

    #include "sfml_includes.h"

    void free_all(game_t *game);
    void free_quadtree(quadtree_t **qt);
    void free_map(map_t *m);

#endif /* !FREE_H_ */
