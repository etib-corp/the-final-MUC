/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** free_qt
*/
#include "sfml_includes.h"

void free_quadtree(quadtree_t **qt)
{
    if (*qt == NULL)
        return;
    destroy_list(&(*qt)->qt_nodes);
    free_quadtree(&(*qt)->one);
    free_quadtree(&(*qt)->two);
    free_quadtree(&(*qt)->three);
    free_quadtree(&(*qt)->four);
    MY_FREE(*qt, free);
}
