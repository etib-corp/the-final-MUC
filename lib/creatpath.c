/*
** EPITECH PROJECT, 2023
** stumper2
** File description:
** creatpath
*/

#include "my.h"

char *creatpath(char *node, char *path)
{
    int index = my_strlen(path);
    char *dest;
    if (path[index -1] != '/') {
        dest = malloc(sizeof(char) * (index +my_strlen(node) + 2));
        dest = my_strcat(my_strcat(my_strcpy(dest, path), "/"), node);
        node = dest;
    } else {
        dest = malloc(sizeof(char) * (index +my_strlen(node) + 1));
        dest = my_strcat(my_strcpy(dest, path), node);
        node = dest;
    }
    return node;
}
