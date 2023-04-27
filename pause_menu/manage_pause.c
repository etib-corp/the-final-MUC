/*
** EPITECH PROJECT, 2023
** manage_pause.c
** File description:
** all functions which manage pause
*/

#include "sfml_includes.h"

void resume_func(game_t *game)
{
    game->state = GAME_PLAY;
}

void save_func(game_t *game)
{
    return save_game(game->player, game->map);
}

void menu_func(game_t *game)
{
    game->state = GAME_MENU;
}
