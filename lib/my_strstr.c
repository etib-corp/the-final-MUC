/*
** EPITECH PROJECT, 2022
** oui
** File description:
** oui
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int len_to_find = my_strlen(to_find);

    if (my_strlen(to_find) == 0) {
        return str;
    }
    while (str[i] != '\0') {
        if (str[i] == to_find[0] &&
            my_strncmp(str + i, to_find, len_to_find) == 0) {
            return str + i;
        }
        i++;
    }
    return 0;
}
