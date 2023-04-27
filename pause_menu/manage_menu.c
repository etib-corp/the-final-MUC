/*
** EPITECH PROJECT, 2023
** manage_menu.c
** File description:
** all functions which manage state
*/

#include "sfml_includes.h"

void start_func(game_t *game)
{
    game->chocobo = init_chocobo(V2F(10, 10), V2F(1910, 1070));
    MY_FREE(game->player, destroy_player);
    game->over = false;
    game->player = init_player((player_data_t){.pos = V2F(1496, 967), .life
    = 3, .coins = 0, .level = 0, .weapon = 0});
    game->map = init_map(FIRST_MAP, "assets/entities_spawn.json", game);
    if (game->map == NULL)
        return;
    game->map->states = set_states(game->world);
    game->state = GAME_PLAY;
    destroy_save();
}

void play_func(game_t *game)
{
    game->over = false;
    load_save(game);
    if (game->map == NULL)
        return;
    game->map->states = set_states(game->world);
    game->state = GAME_PLAY;
}

void exit_func(game_t *game)
{
    if (game->map != NULL)
        free_map(game->map);
    game->state = GAME_EXIT;
}

void settings_func(game_t *game)
{
    game->last_state = game->state;
    game->state = GAME_SETTINGS;
}

void help_func(game_t *game)
{
    game->last_state = game->state;
    game->state = GAME_HELP;
}
