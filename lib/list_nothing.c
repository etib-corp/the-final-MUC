/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** list_nothing
*/

#include "list.h"

void *constructor_nothing(va_list *ap)
{
    return va_arg(*ap, void *);
}

void destroy_nothing(void *data)
{
    (void)data;
}
