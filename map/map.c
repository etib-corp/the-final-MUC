/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** map
*/

#include "sfml_includes.h"

sfVertexArray *fill_vertexarray(sfVector2f m_size, int *level,
    sfTexture *m_texture, sfVector2f t_size)
{
    sfVertexArray *arr = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(arr, sfQuads);
    sfVertexArray_resize(arr, m_size.x * m_size.y * 4);
    for (unsigned int i = 0; i < m_size.x; i++) {
        for (unsigned int j = 0; j < m_size.y; j++) {
            int t_n = level[i + j * ((int)m_size.x)];
            int tu = t_n % (sfTexture_getSize(m_texture).x / (int)t_size.x);
            int tv = t_n / (sfTexture_getSize(m_texture).x / (int)t_size.x);
            sfVertex *quad = sfVertexArray_getVertex(arr, (i + j *
                (int)m_size.x) * 4);
            quad[0].position = V2F(i * t_size.x, j * t_size.y);
            quad[1].position = V2F((i + 1) * t_size.x, j * t_size.y);
            quad[2].position = V2F((i + 1) * t_size.x, (j + 1) * t_size.y);
            quad[3].position = V2F(i * t_size.x, (j + 1) * t_size.y);
            quad[0].texCoords = V2F(tu * t_size.x, tv * t_size.y);
            quad[1].texCoords = V2F((tu + 1) * t_size.x, tv * t_size.y);
            quad[2].texCoords = V2F((tu + 1) * t_size.x, (tv + 1) * t_size.y);
            quad[3].texCoords = V2F(tu * t_size.x, (tv + 1) * t_size.y);
        }
    } return arr;
}

sfVertexArray *load_map(int *level, sfVector2f t_size, sfTexture *m_texture,
    sfVector2f m_size)
{
    sfVertexArray *arr = NULL;

    if (m_texture == NULL)
        return NULL;
    arr = fill_vertexarray(m_size, level, m_texture, t_size);
    return arr;
}

sfVertexArray *map(sfTexture *texture, int *level, sfVector2f t_size)
{
    sfVertexArray *array = sfVertexArray_create();
    array = load_map(level, V2F(16, 16), texture, t_size);

    return array;
}

void push_important(game_t *game, map_t *map)
{
    push_front_list(map->tities, 0, ready_player, process_player,
    draw_player, destroy_player, false);
    entity_t *tmp = CAST(entity_t *, map->tities->nodes->data);
    tmp->instance = game->player;
    push_front_list(map->tities, 5, ready_ath, process_ath, draw_ath,
    destroy_ath, true);
    tmp = CAST(entity_t *, map->tities->nodes->data);
    tmp->instance = game->ath;
    push_front_list(map->tities, 8, ready_chocobo, process_chocobo,
    drawn_chocobo, destroy_chocobo, false);
    tmp = CAST(entity_t *, map->tities->nodes->data);
    tmp->instance = game->chocobo;
    if (my_strcmp(map->json_map, "assets/map_houses.json") != 0) {
        return;
    }
    boss_t *boss = create_boss();
    push_front_list(map->tities, 9, ready_boss, process_boss, draw_boss,
    destroy_boss, false);
    CAST(entity_t *, map->tities->nodes->data)->instance = boss;
}

map_t *init_map(char *path_map, char *path_entity, game_t *game)
{
    map_t *map = malloc(sizeof(map_t));
    if (map == NULL)
        return NULL;
    map->json_map = my_strdup(path_map);
    map->json_entity = my_strdup(path_entity);
    map->teleports = NULL;
    map->tities = create_list(constructor_entity, destroy_entity);
    push_important(game, map);
    if (get_entity(path_entity, map))
        return NULL;
    if (get_layers(path_map, map, game))
        return NULL;
    return map;
}
