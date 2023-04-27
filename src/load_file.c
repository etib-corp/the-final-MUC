/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** load_file
*/

#include "sfml_includes.h"

sfVector2f init_player_pos(char *buf)
{
    sfVector2f new = V2F(0, 0);
    new.x = my_getnbr(buf);
    new.y = my_getnbr(buf + my_lennbr(CAST(size_t, new.x)) + 1);
    return new;
}

void add_player_and_map(game_t *game, char *buf, FILE *file,
player_data_t data)
{
    size_t count = 0;
    game->player = init_player(data);
    getline(&buf, &count, file);
    char *map = str_nrm(buf, 1);
    getline(&buf, &count, file);
    game->map = init_map(map, str_nrm(buf, 1), game);
}

int init_from_file(FILE *file, game_t *game)
{
    char *buf = NULL; size_t count = 0; player_data_t data = {0};
    if (!is_valid(file))
        return 0;
    getline(&buf, &count, file);
    data.pos = init_player_pos(buf);
    getline(&buf, &count, file);
    data.life = my_getnbr(buf);
    getline(&buf, &count, file);
    data.coins = my_getnbr(buf);
    getline(&buf, &count, file);
    data.level = my_getnbr(buf);
    getline(&buf, &count, file);
    data.weapon = my_getnbr(buf);
    getline(&buf, &count, file);
    data.xp = my_getnbr(buf);
    getline(&buf, &count, file);
    data.chocobo = my_getnbr(buf);
    add_player_and_map(game, buf, file, data);
    free(buf);
    return 1;
}
