/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** manage_entity
*/
#include "sfml_includes.h"

void *constructor_entity(va_list *ap)
{
    entity_t *new = malloc(sizeof(entity_t));
    new->instance = NULL;
    new->type = va_arg(*ap, int);
    new->ready = va_arg(*ap, void (*)(entity_t *));
    new->process = va_arg(*ap, void (*)(game_t *, void *));
    new->draw = va_arg(*ap, void (*)(game_t *, void *));
    new->destroy = va_arg(*ap, void (*)(void *));
    new->is_hud = va_arg(*ap, int);
    return new;
}

void destroy_entity(void *data)
{
    entity_t *gree = data;
    gree->destroy(gree);
    return;
}

linked_list_t *get_entity_of_type(linked_list_t *head, int type)
{
    entity_t *tmp = NULL;
    LIST_FOREACH_DECL_BASIC(head, elem) {
        tmp = CAST(entity_t *, elem->data);
        if (tmp->type == type)
            return elem;
    }
    return NULL;
}

linked_list_t *get_next_entity_of_type(linked_list_t *head, int type)
{
    if (head == NULL)
        return NULL;
    return get_entity_of_type(head->next, type);
}

entity_t *sysdraw(list_t *head, game_t *game)
{
    entity_t *tmp = NULL;
    entity_t *hud = NULL;
    LIST_FOREACH_DECL_BASIC(head->nodes, elem) {
        tmp = CAST(entity_t *, elem->data);
        if (tmp->is_hud)
            hud = tmp;
        else
            tmp->draw(game, tmp->instance);
    }
    return hud;
}
