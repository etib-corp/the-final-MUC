/*
** EPITECH PROJECT, 2022
** oui
** File description:
** oui
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);

    if (src == NULL)
        return dest;
    char *new = malloc(sizeof(char) * (len_dest + len_src + 1));
    if (new == NULL)
        return NULL;
    while (dest[i] != '\0') {
        new[i] = dest[i];
        i++;
    }
    i = 0;
    while (src[i] != '\0') {
        new[len_dest + i] = src[i];
        i++;
    }
    new[len_dest + i] = '\0';
    return new;
}
