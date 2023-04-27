/*
** EPITECH PROJECT, 2023
** all functions which manage the window
** File description:
** manage_window
*/

#include "sfml_includes.h"

sfRenderWindow *set_window(float quotient, bool fullscreen)
{
    sfVideoMode mode = {CAST(int, 1920.0 / quotient),
    CAST(int, 1080.0 / quotient), 32};
    sfRenderWindow *win = NULL;

    if (fullscreen)
        win = sfRenderWindow_create(mode, TITLE, sfClose | sfFullscreen, NULL);
    else
        win = sfRenderWindow_create(mode, TITLE, sfClose, NULL);

    if (win == NULL)
        return NULL;
    sfRenderWindow_setFramerateLimit(win, 60);
    return win;
}

void manage_dt(game_t *game)
{
    if (game->dt >= DT)
        game->dt -= DT;
    game->dt += sfTime_asSeconds(sfClock_restart(game->clock));
}
