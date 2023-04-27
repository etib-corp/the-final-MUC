/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "sfml_includes.h"

    #define WORLD "assets/World/world.png"
    #define FIRST_MAP "assets/map_spawn.json"

    typedef void(*action)(game_t *);

    void get_new_map(player_t *player, map_t *mapt, game_t *game);
    map_t *init_map(char *path_map, char *path_entity, game_t *game);
    int *drop(int *level, int drop_v, int max);
    sfRenderStates *set_states(sfTexture *m_texture);
    int get_entity(char *path_entity, map_t *map);
    sfVertexArray *map(sfTexture *texture, int *level, sfVector2f t_size);
    void draw_level(game_t *game, map_t *map, int level);
    void get_properties(map_t *mapt, json_value_t *json_value, int i);
    void push_enemy(map_t *mapt, char *tex, enemy_t *e);
    void push_npc(map_t *mapt, npc_t *e, char *action);
    void push_item(map_t *mapt, dropable_t *e);

#endif /* !MAP_H_ */
