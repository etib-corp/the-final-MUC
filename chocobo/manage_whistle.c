/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** manage_whistle
*/
#include "sfml_includes.h"

void whistle(chocobo_t *chocobo)
{
    chocobo->state = CHOCO_WHISTLE;
    play_sound(chocobo->whistle);
}
