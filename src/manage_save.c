/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** manage_save
*/
#include "sfml_includes.h"

void save_game(player_t *player, map_t *map)
{
    int fd = open(".etib", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return (void)mini_printf("Permission denied\n", 2);
    mini_printf("full\n", fd);
    mini_printf("%d:%d\n%d\n%d\n%d\n%d\n%d\n%d\n%s\n%s\n",
    fd, (int)player->pos.x, (int)player->pos.y, (int)player->life,
    player->coins, player->lvl, player->current_weapon, player->xp,
    player->choco, map->json_map, map->json_entity);
}

void destroy_save(void)
{
    int fd = open(".etib", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        return (void)mini_printf("Permission denied\n", 2);
    mini_printf("empty\n", fd);
}

bool check_save(void)
{
    FILE *file = fopen(".etib", "r");
    char *buf = NULL;
    size_t count = 0;
    bool res = true;

    if (file == NULL)
        return false;
    getline(&buf, &count, file);
    if (my_strncmp(buf, "empty", 5) == 0)
        res = false;
    MY_FREE(buf, free);
    fclose(file);
    return res;
}

void load_save(game_t *game)
{
    FILE *file = fopen(".etib", "r");
    game->chocobo = init_chocobo(V2F(10, 10), V2F(1910, 1070));
    if (file != NULL && init_from_file(file, game)) {
        fclose(file);
    } else {
        game->player = init_player((player_data_t){.pos = V2F(1496, 967), .life
        = 3, .coins = 0, .level = 0, .weapon = 0});
        game->map = init_map(FIRST_MAP, "assets/entities_spawn.json", game);
    }
}
