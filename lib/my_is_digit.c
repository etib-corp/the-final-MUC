/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** my_is_digit
*/

#include "my.h"

bool my_is_digit(char c)
{
    if (c < '0' || c > '9')
        return false;
    return true;
}
