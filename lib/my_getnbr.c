/*
** EPITECH PROJECT, 2022
** my_getnbr.c
** File description:
** my_getnbr
*/
#include <stdio.h>
int my_getnbr(char const *str)
{
    int occ = 0;
    int i = 0;
    int g = 0;
    while ((str[i] > 47 && str[i] < 58) || (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-')
            g = g + 1;
        if (str[i] > 47 && str[i] < 58) {
            occ = occ * 10 + (str[i] - 48);
        }
        i = i + 1;
    }
    if (g % 2 != 0 && g != 0)
        occ = occ * -1;
    return (occ);
}
