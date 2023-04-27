/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** get_entity
*/

#include "sfml_includes.h"

sfVector2f get_pos_json(json_value_t *json_value)
{
    json_value_t *pos_x = json_get_array(json_value, 0);
    json_value_t *pos_y = json_get_array(json_value, 1);
    sfVector2f pos = {0};
    pos.x = (int)json_get_float(pos_x);
    pos.y = (int)json_get_float(pos_y);
    return pos;
}

void parse_enemy(json_value_t *json, map_t *map)
{
    sfVector2f *pos = malloc(sizeof(sfVector2f) * 2);
    json_pair_t *tmp = NULL;
    enemy_t *e = NULL;
    if (pos == NULL)
        return;
    pos[1] = get_pos_json(json_get_objet(json, "pos_max")->value);
    pos[0] = get_pos_json(json_get_objet(json, "pos_min")->value);
    tmp = json_get_objet(json, "life");
    int life = (int)json_get_float(tmp->value);
    e = create_enemy(life, pos);
    tmp = json_get_objet(json, "texture");
    char *tex = json_get_string(tmp->value);
    push_enemy(map, tex, e);
    free(pos);
}

void parse_npc(json_value_t *json, map_t *map)
{
    json_pair_t *tmp_pair = json_get_objet(json, "name");
    char *value = json_get_string(tmp_pair->value);
    tmp_pair = json_get_objet(json, "dialog");
    char *text = json_get_string(tmp_pair->value);
    dialog_t *d = init_dialog(text, value);
    tmp_pair = json_get_objet(json, "texture");
    value = json_get_string(tmp_pair->value);
    tmp_pair = json_get_objet(json, "pos");
    sfVector2f pos = get_pos_json(tmp_pair->value);
    tmp_pair = json_get_objet(json, "action");
    char *action = json_get_string(tmp_pair->value);
    npc_t *e = init_npc(pos, d, value);
    push_npc(map, e, action);
}

void parse_item(json_value_t *json, map_t *map)
{
    json_pair_t *tmp_pair = json_get_objet(json, "name");
    char *name = json_get_string(tmp_pair->value);
    tmp_pair = json_get_objet(json, "info");
    char *info = json_get_string(tmp_pair->value);
    tmp_pair = json_get_objet(json, "texture");
    char *texture = json_get_string(tmp_pair->value);
    sfVector2f pos = get_pos_json(json_get_objet(json, "pos")->value);
    dropable_t *e = create_dropable(texture, name, info, pos);
    push_item(map, e);
}

int get_entity(char *path_entity, map_t *map)
{
    json_value_t *json = parseur(path_entity);
    if (json == NULL)
        return 1;
    json_pair_t *pair_enemy = json_get_objet(json, "enemy");
    json_value_t *tmp_value = NULL;
    for (int i = 0; pair_enemy != NULL &&
    (tmp_value = json_get_array(pair_enemy->value, i)) != NULL; i++)
        parse_enemy(tmp_value, map);
    pair_enemy = json_get_objet(json, "npc");
    for (int i = 0;  pair_enemy != NULL &&
    (tmp_value = json_get_array(pair_enemy->value, i))
    != NULL; i++)
        parse_npc(tmp_value, map);
    pair_enemy = json_get_objet(json, "item");
    for (int i = 0; pair_enemy != NULL &&
    (tmp_value = json_get_array(pair_enemy->value, i)) != NULL; i++)
        parse_item(tmp_value, map);
    MY_FREE_VA(json, free_json_value, true);
    return 0;
}
