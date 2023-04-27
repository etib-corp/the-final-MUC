/*
** EPITECH PROJECT, 2022
** ok
** File description:
** ok
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] > s2[i]) {
            return 1;
        }
        if (s1[i] < s2[i]) {
            return -1;
        } else {
            i++;
        }
    }
    return 0;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n < 0)
        return 0;
    while (i < n) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return 0;
}
