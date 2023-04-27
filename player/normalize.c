/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** normalize
*/
#include "sfml_includes.h"


sfVector2f normalize(sfVector2f vec)
{
    double magnitude = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    if (magnitude == 0.0)
        return V2F(1.0, 1.0);
    vec.x /= magnitude;
    vec.y /= magnitude;
    return vec;
}
