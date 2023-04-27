/*
** EPITECH PROJECT, 2023
** music.c
** File description:
** all functions to manage music
*/

#include "sfml_includes.h"

void free_music(music_t *music)
{
    if (music == NULL)
        return;
    sfMusic_destroy(music->boss);
    sfMusic_destroy(music->menu);
    for (int i = 0; music->all[i] != NULL; i++)
        sfMusic_destroy(music->all[i]);
    free(music);
}

void switch_music(music_t *music)
{
    music->duration = sfMusic_getDuration(music->current);
    music->time = sfTime_Zero;
    sfMusic_play(music->current);
}

void set_music_menu(music_t *music, int state)
{
    if (state == 0 && music->current != music->menu) {
        if (music->current != NULL)
            sfMusic_stop(music->current);
        music->current = music->menu;
        switch_music(music);
    }
}

void update_music(music_t *music, int state)
{
    set_music_menu(music, state);
    if (state == 2 && music->current != music->boss) {
        sfMusic_stop(music->current);
        music->current = music->boss;
        switch_music(music);
    } if ((music->current == NULL) || (state == 1 &&
        (music->current == music->boss || music->current == music->menu))) {
        if (music->current != NULL)
            sfMusic_stop(music->current);
        music->current = music->all[rand() % 5];
        switch_music(music);
    } music->time = sfMusic_getPlayingOffset(music->current);
    if ((int)sfTime_asSeconds(music->time) ==
    (int)sfTime_asSeconds(music->duration)) {
        sfMusic_stop(music->current);
        music->current = NULL;
    }
}

music_t *init_music(void)
{
    music_t *music = malloc(sizeof(music_t));

    if (music == NULL)
        return NULL;
    music->boss = sfMusic_createFromFile(BOSS_MUSIC);
    music->menu = sfMusic_createFromFile(MENU_MUSIC);
    music->all = malloc(sizeof(sfMusic *) * 6);
    music->current = NULL;
    if (music->all == NULL)
        return NULL;
    sfMusic_setLoop(music->boss, sfTrue);
    sfMusic_setLoop(music->menu, sfTrue);
    music->all[0] = sfMusic_createFromFile(FIRST_MUSIC);
    music->all[1] = sfMusic_createFromFile(SECOND_MUSIC);
    music->all[2] = sfMusic_createFromFile(THIRD_MUSIC);
    music->all[3] = sfMusic_createFromFile(FOURTH_MUSIC);
    music->all[4] = sfMusic_createFromFile(FIRTH_MUSIC);
    music->all[5] = NULL;
    return music;
}
