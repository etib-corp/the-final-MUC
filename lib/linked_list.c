/*
** EPITECH PROJECT, 2023
** ast
** File description:
** linked_list
*/
#include "list.h"

linked_list_t *new_node(va_list *ap, constructor_t constructor)
{
    linked_list_t *l = malloc(sizeof(linked_list_t));

    if (l == NULL)
        return NULL;
    l->data = constructor(ap);
    l->next = NULL;
    l->prev = NULL;
    if (l->data == NULL) {
        free(l);
        return NULL;
    }
    return l;
}

bool push_back_node(linked_list_t **l, constructor_t create, va_list *ap)
{
    linked_list_t *last = NULL;

    if (*l == NULL) {
        *l = new_node(ap, create);
        return *l != NULL;
    }
    LIST_FOREACH_NEXT(*l, last);
    last->next = new_node(ap, create);
    if (last->next == NULL)
        return false;
    last->next->prev = last;
    return true;
}

bool push_front_node(linked_list_t **l, constructor_t create, va_list *ap)
{
    linked_list_t *n = NULL;

    n = new_node(ap, create);
    if (n == NULL) {
        return false;
    }
    n->next = *l;
    *l = n;
    return true;
}

void destroy_node(linked_list_t **l, destructor_t destroy)
{
    linked_list_t *gree = NULL;

    if (*l == NULL) {
        return;
    }
    while (*l) {
        gree = (*l)->next;
        destroy((*l)->data);
        free(*l);
        *l = gree;
    }
    *l = NULL;
}
