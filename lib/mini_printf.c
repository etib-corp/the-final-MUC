/*
** EPITECH PROJECT, 2022
** mini-printf
** File description:
** %d, %i, %c, %s
*/

#include "my.h"

static int check_flag(char a, va_list *list, int fd)
{
    flags_t flag[] = {
        {'d', my_printdigits}, {'i', my_printdigits}, {'s', my_va_putstr},
        {'c', my_va_putchar}, {'\0', NULL}
    };
    int i = 0;

    while (flag[i].func != NULL) {
        if (flag[i].c == a)
            return flag[i].func(list, fd);
        else
            i++;
    }
    my_putchar('%', fd);
    if (a != '%')
        my_putchar(a, fd);
    return 2;
}

int mini_printf(char const *format, int fd, ...)
{
    va_list ap;
    int i = 0;
    int count = 0;
    va_start(ap, fd);
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] != '\0') {
            count = count + check_flag(format[i + 1], &ap, fd);
            i = i + 2;
        } else {
            my_putchar(format[i], fd);
            count++;
            i++;
        }
    }
    va_end(ap);
    return count;
}
