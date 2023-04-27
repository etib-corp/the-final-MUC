/*
** EPITECH PROJECT, 2022
** oui
** File description:
** non
*/

#include "my.h"

int my_putstr(char const *str, int fd)
{
    return write(fd, str, my_strlen(str));
}

int my_va_putstr(va_list *l, int fd)
{
    return my_putstr(va_arg(*l, char *), fd);
}
