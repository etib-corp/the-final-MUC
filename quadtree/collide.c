/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** collide
*/
#include "sfml_includes.h"

entity_t *list_to_entity(linked_list_t *node)
{
    if (node == NULL)
        return NULL;
    return CAST(entity_t *, node->data);
}

bool check_collision(sfIntRect *a, sfIntRect *b)
{
    return sfIntRect_intersects(a, b, NULL);
}

void watch_colision(linked_list_t *head, enum CHOCOBO_STATE mount)
{
    if (head == NULL || head->next == NULL)
        return;
    entity_t *entity = list_to_entity(get_entity_of_type(head, 0));
    if (entity == NULL)
        return;
    player_t * player = CAST(player_t *, entity->instance);
    entity_collide(player, head, mount);
    boss_collide(player, head);
}

int collide(quadtree_t *qt, enum CHOCOBO_STATE mount)
{
    if (qt->one == NULL) {
        LIST_FOREACH_DECL_BASIC(qt->qt_nodes->nodes, elem) {
            watch_colision(elem, mount);
        }
        return 1;
    }
    collide(qt->one, mount);
    collide(qt->two, mount);
    collide(qt->three, mount);
    collide(qt->four, mount);
    return 0;
}
