/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** get_specifique
*/

#include "sfml_includes.h"

void get_properties(map_t *mapt, json_value_t *json_value, int i)
{
    json_value_t *tmp_object = json_get_array(json_value, 0);
    json_pair_t *tmp_pair = json_get_objet(tmp_object, "value");
    int x = 0;
    int y = 0;
    mapt->teleports[i].path_map = my_strdup(json_get_string(tmp_pair->value));
    tmp_object = json_get_array(json_value, 2);
    tmp_pair = json_get_objet(tmp_object, "value");
    x = (int)json_get_float(tmp_pair->value);
    tmp_object = json_get_array(json_value, 3);
    tmp_pair = json_get_objet(tmp_object, "value");
    y = (int)json_get_float(tmp_pair->value);
    mapt->teleports[i].pos_player = V2F(x, y);
    tmp_object = json_get_array(json_value, 1);
    tmp_pair = json_get_objet(tmp_object, "value");
    mapt->teleports[i].path_enemy = my_strdup(json_get_string(tmp_pair->value));
    return;
}
