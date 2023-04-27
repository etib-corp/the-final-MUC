/*
** EPITECH PROJECT, 2023
** npc_funtions.c
** File description:
** all functions for npc
*/

#include "sfml_includes.h"

void buy_apple(game_t *game)
{
    dropable_t *apple = NULL;

    if (game->player->coins < 3)
        return;
    apple = create_dropable(APPLE, "Apple", "A fruit which give you 1 HP.",
        V2F(0, 0));
    if (add_dropable(apple, game->ath->inventory->content))
        game->player->coins -= 3;
    else
        free_dropable(apple);
}

void buy_chocobo(game_t *game)
{
    if (game->player->choco || game->player->coins < 10)
        return;
    game->player->coins -= 10;
    game->player->choco = true;
}

void buy_weapon(game_t *game)
{
    int price = 0;

    if (game->player->max_weapon == 0)
        price = 5;
    if (game->player->max_weapon == 1)
        price = 10;
    if (game->player->coins >= price) {
        game->player->coins -= price;
        game->player->max_weapon++;
    }
}

void none_function(game_t *game)
{
    (void)game;
    return;
}
