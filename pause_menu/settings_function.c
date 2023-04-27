/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** settings_function
*/
#include "sfml_includes.h"

void sound_plus(game_t *game)
{
    sfMusic *cur = game->music->current;
    float pitch = 0.0;

    if (cur != NULL) {
        pitch = sfMusic_getVolume(cur);
        if (pitch < 100.0)
            sfMusic_setVolume(cur, pitch + 1.0);
    }
}

void sound_minus(game_t *game)
{
    sfMusic *cur = game->music->current;
    float pitch = 0.0;

    if (cur != NULL) {
        pitch = sfMusic_getVolume(cur);
        if (pitch > 0.0)
            sfMusic_setVolume(cur, pitch - 1.0);
    }
}

void sound_off(game_t *game)
{
    sfMusic *cur = game->music->current;

    if (cur != NULL) {
        if (sfMusic_getVolume(cur) == 0.0)
            sfMusic_setVolume(cur, 50.0);
        else
            sfMusic_setVolume(cur, 0.0);
    }
}

void change_res(game_t *game)
{
    game->quotient = game->quotient == 1.0 ? 2.0 : 1.0;
    sfRenderWindow_destroy(game->win);
    game->win = set_window(game->quotient, game->fullscreen);
    if (game->quotient == 1.0)
        sfText_setString(game->settings->button[3]->text, "1920x1080");
    else
        sfText_setString(game->settings->button[3]->text, "960x540");
}

void change_mode(game_t *game)
{
    game->fullscreen = !game->fullscreen;
    sfRenderWindow_destroy(game->win);
    game->win = set_window(game->quotient, game->fullscreen);
    if (game->fullscreen)
        sfText_setString(game->settings->button[4]->text, "Fullscreen");
    else
        sfText_setString(game->settings->button[4]->text, "Windowed");
}
