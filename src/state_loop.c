/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** state_loop
*/

#include "sfml_includes.h"

void pause_loop(game_t *game)
{
    sfRenderWindow_clear(game->win, sfBlack);
    draw_all(game);
    manage_dt(game);
    update_pmenu(game->pause_menu, game);
    sfRenderWindow_setView(game->win, game->view->cinematic);
    draw_pmenu(game->pause_menu, game->win);
    sfRenderWindow_setView(game->win, game->view->player);
    sfRenderWindow_display(game->win);
}

void menu_loop(game_t *game)
{
    sfRenderWindow_clear(game->win, sfBlack);
    sfRenderWindow_setView(game->win, game->view->cinematic);
    update_music(game->music, 0);
    manage_dt(game);
    animate_menu(game->main_menu, game->dt, game->quotient);
    update_pmenu(game->main_menu, game);
    draw_pmenu(game->main_menu, game->win);
    sfRenderWindow_display(game->win);
}

void settings_loop(game_t *game)
{
    sfRenderWindow_clear(game->win, sfBlack);
    sfRenderWindow_setView(game->win, game->view->cinematic);
    update_music(game->music, 1);
    manage_dt(game);
    update_pmenu(game->settings, game);
    draw_pmenu(game->settings, game->win);
    sfRenderWindow_display(game->win);
}

void game_over_loop(game_t *game)
{
    sfRenderWindow_clear(game->win, sfBlack);
    sfRenderWindow_setView(game->win, game->view->cinematic);
    manage_dt(game);
    if (animate_splash(game->dt, game->game_over))
        game->state = GAME_MENU;
    sfRenderWindow_drawSprite(game->win, game->game_over->sprite, NULL);
    sfRenderWindow_display(game->win);
}

void help_loop(game_t *game)
{
    sfRenderWindow_clear(game->win, sfBlack);
    sfRenderWindow_setView(game->win, game->view->cinematic);
    update_music(game->music, 1);
    manage_dt(game);
    update_pmenu(game->help, game);
    draw_pmenu(game->help, game->win);
    sfRenderWindow_display(game->win);
}
