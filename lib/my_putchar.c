/*
** EPITECH PROJECT, 2022
** oui
** File description:
** non
*/

#include <stdarg.h>
#include <unistd.h>

int my_putchar(char c, int fd)
{
    return write(fd, &c, 1);
}

int my_va_putchar(va_list *l, int fd)
{
    return my_putchar(va_arg(*l, int), fd);
}
