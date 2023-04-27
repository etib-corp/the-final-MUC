/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** get_layers
*/
#include "sfml_includes.h"

void get_collision(map_t *mapt, json_value_t *json_value)
{
    json_value_t *tmp_value = NULL;
    json_pair_t *tmp_pair = NULL;
    int *layer_data = malloc(sizeof(int) * mapt->size.x * mapt->size.y);
    tmp_pair = json_get_objet(json_value, "data");
    for (int j = 0; (tmp_value = json_get_array(tmp_pair->value, j)) !=
    NULL; j++)
        layer_data[j] = (int)json_get_float(tmp_value);
    mapt->collisions = layer_data;
}

void get_teleports(map_t *mapt, json_value_t *json_value)
{
    json_pair_t *tmp_pair = json_get_objet(json_value, "objects");
    mapt->n_teleport = tmp_pair->value->value.array->size;
    mapt->teleports = malloc(sizeof(teleports_t) * mapt->n_teleport);
    json_value_t *tmp_value = NULL;
    json_pair_t *tmp = tmp_pair;
    for (int i = 0; mapt->n_teleport > i; i++) {
        tmp_value = json_get_array(tmp->value, i);
        tmp_pair = json_get_objet(tmp_value, "height");
        mapt->teleports[i].rec.height = (int)json_get_float(tmp_pair->value);
        tmp_pair = json_get_objet(tmp_value, "width");
        mapt->teleports[i].rec.width = (int)json_get_float(tmp_pair->value);
        tmp_pair = json_get_objet(tmp_value, "x");
        mapt->teleports[i].rec.left = (int)json_get_float(tmp_pair->value);
        tmp_pair = json_get_objet(tmp_value, "y");
        mapt->teleports[i].rec.top = (int)json_get_float(tmp_pair->value);
        tmp_pair = json_get_objet(tmp_value, "properties");
        get_properties(mapt, tmp_pair->value, i);
    }
}

void get_map(map_t *mapt, game_t *game, json_value_t *json_value, int i)
{
    json_value_t *tmp_value = NULL;
    json_pair_t *tmp_pair = NULL;
    int *layer_data = malloc(sizeof(int) * mapt->size.x * mapt->size.y);
    tmp_pair = json_get_objet(json_value, "data");
    for (int j = 0; (tmp_value = json_get_array(tmp_pair->value, j)) !=
    NULL; j++)
        layer_data[j] = (int)json_get_float(tmp_value);
    drop(layer_data, -1, mapt->size.x * mapt->size.y);
    mapt->layers[i].layer = map(game->world, layer_data, mapt->size);
    MY_FREE(layer_data, free);
}

void get_layers2(map_t *mapt, game_t *game, json_pair_t *json_pair)
{
    json_value_t *json_value = NULL;
    json_pair_t *tmp_pair = NULL;
    char *name = NULL;
    for (int i = 0; i < mapt->n_layer; i++) {
        json_value = json_get_array(json_pair->value, i);
        tmp_pair = json_get_objet(json_value, "name");
        name = json_get_string(tmp_pair->value);
        if (my_strcmp(name, "teleports") == 0) {
            get_teleports(mapt, json_value);
            continue;
        }
        if (my_strcmp(name, "collisions") == 0) {
            get_collision(mapt, json_value);
        }
        mapt->layers[i].name = my_strdup(name);
        get_map(mapt, game, json_value, i);
    }
}

int get_layers(char *path, map_t *mapt, game_t * game)
{
    json_value_t *json = parseur(path);
    if (json == NULL)
        return 1;
    json_pair_t *json_width = json_get_objet(json, "width");
    json_pair_t *json_height = json_get_objet(json, "height");
    json_pair_t *json_pair = json_get_objet(json, "layers");
    mapt->size = V2F(json_get_float(json_width->value), json_get_float(
    json_height->value));
    mapt->n_layer = json_pair->value->value.array->size;
    mapt->layers = malloc(sizeof(map_layer_t) * mapt->n_layer);
    get_layers2(mapt, game, json_pair);
    MY_FREE_VA(json, free_json_value, true);
    return 0;
}
