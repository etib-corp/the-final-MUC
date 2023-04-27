/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** create_quadtree
*/
#include "sfml_includes.h"

quadtree_t *create_quadtree(sfFloatRect rect, int depth)
{
    quadtree_t *quadtree = malloc(sizeof(quadtree_t));

    if (quadtree == NULL)
        return NULL;
    quadtree->qt_nodes = create_list(constructor_nothing, destroy_nothing);
    quadtree->one = NULL;
    quadtree->two = NULL;
    quadtree->three = NULL;
    quadtree->four = NULL;
    quadtree->elm = 0;
    quadtree->zone = rect;
    quadtree->depth = depth;
    return quadtree;
}

void insert_quadtree(quadtree_t *qt, list_t *entity)
{
    LIST_FOREACH_DECL_BASIC(entity->nodes, elem)
        add(qt, elem);
}
