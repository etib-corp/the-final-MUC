/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** filled_quadtree
*/
#include "sfml_includes.h"


static void chose_qt(quadtree_t *qt, linked_list_t *entity);

sfVector2f get_pos(entity_t *entity)
{
    sfVector2f point = V2F(-1, -1);
    switch (entity->type) {
    case 0:
        point = CAST(player_t *, entity->instance)->pos;
        break;
    case 1:
        point = sfSprite_getPosition(CAST(enemy_t *, entity->instance)->sprite);
        break;
    case 4:
        point = CAST(npc_t *, entity->instance)->pos;
        break;
    case 9:
        sfIntRect *rect = CAST(boss_t *, entity->instance)->hitbox->rect;
        point = V2F(rect->left, rect->top);
    default:
        break;
    }
    return point;
}

static bool check_inside(sfFloatRect rect, linked_list_t *entity)
{
    entity_t *tmp = CAST(entity_t *, entity->data);
    bool collisionX = false;
    bool collisionY = false;
    if (tmp->type == 3)
        return false;
    sfVector2f point = get_pos(tmp);
    if (point.x == -1 && point.y == -1)
        return false;
    collisionX = point.x >= rect.left && point.x <= rect.left + rect.width;
    collisionY = point.y >= rect.top && point.y <= rect.top + rect.height;
    return collisionX && collisionY;
}

static quadtree_t *split(quadtree_t *qt)
{
    sfVector2f half = {0};
    half = V2F(qt->zone.width / 2, qt->zone.height / 2);
    qt->one = create_quadtree(FR(qt->zone.left, qt->zone.top, half.x, half.y),
    qt->depth + 1);
    qt->two = create_quadtree(FR(qt->zone.left + half.x, qt->zone.top, half.x,
    half.y), qt->depth + 1);
    qt->three = create_quadtree(FR(qt->zone.left, qt->zone.top + half.y,
    half.x, half.y), qt->depth + 1);
    qt->four = create_quadtree(FR(qt->zone.left + half.x, qt->zone.top +
    half.y, half.x, half.y), qt->depth + 1);
    return qt;
}

bool add(quadtree_t *qt, linked_list_t *entity)
{
    if (!check_inside(qt->zone, entity))
        return false;
    if (qt->one != NULL) {
        chose_qt(qt, entity);
        return true;
    }
    if (push_front_list(qt->qt_nodes, entity->data) == false)
        return false;
    qt->elm++;
    if (qt->elm > 4 && qt->depth < 5) {
        qt = split(qt);
        LIST_FOREACH_DECL_BASIC(qt->qt_nodes->nodes, elem) {
            chose_qt(qt, elem);
        }
        destroy_list(&qt->qt_nodes);
    }
    return true;
}

static void chose_qt(quadtree_t *qt, linked_list_t *entity)
{
    if (add(qt->four, entity))
        return;
    if (add(qt->three, entity))
        return;
    if (add(qt->two, entity))
        return;
    add(qt->one, entity);
}
