/*
** EPITECH PROJECT, 2023
** manage_game.c
** File description:
** all functions to manage the game struct
*/

#include "sfml_includes.h"

void init_all_states(game_t *game)
{
    game->state = GAME_MENU;
    game->main_menu = init_main_menu(sfText_getFont(game->ath->text));
    game->pause_menu = init_pause_menu(sfText_getFont(game->ath->text));
    game->settings = init_settings(sfText_getFont(game->ath->text));
    game->game_over = init_splash(DIED, 480, 270, 34);
    game->help = init_help_menu(sfText_getFont(game->ath->text));
    game->etib_logo = init_splash("assets/logo.png", 500, 500, 12);
    game->start = init_soundtrack("assets/start.ogg");
    sfSprite_setScale(game->etib_logo->sprite, V2F(3.84, 2.16));
    sfSprite_setScale(game->game_over->sprite, V2F(4, 4));
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    if (game == NULL)
        return NULL;
    game->quotient = 1.0;
    game->fullscreen = true;
    game->world = sfTexture_createFromFile(WORLD, NULL);
    game->view = init_views();
    game->clock = sfClock_create();
    game->music = init_music();
    game->dt = 0.0; game->qt = NULL;
    game->over = false;
    game->ath = init_ath();
    init_all_states(game);
    game->map = NULL;
    game->player = NULL;
    game->chocobo = NULL;
    game->win = set_window(game->quotient, game->fullscreen);
    if (!game->win || game->world == NULL)
        return NULL;
    return game;
}
