/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** soundtrack
*/
#include "sfml_includes.h"

soundtrack_t *init_soundtrack(char *path)
{
    soundtrack_t *new = malloc(sizeof(soundtrack_t));
    new->sound = sfSound_create();
    new->buffer = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(new->sound, new->buffer);
    return new;
}

void play_sound(soundtrack_t *st)
{
    sfSound_play(st->sound);
}

void destroy_soundtrack(soundtrack_t *st)
{
    MY_FREE(st->buffer, sfSoundBuffer_destroy);
    MY_FREE(st->sound, sfSound_destroy);
    MY_FREE(st, free);
}
