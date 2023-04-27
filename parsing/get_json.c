/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** get_json
*/
#include "sfml_includes.h"


json_pair_t *json_get_objet(json_value_t *json, char *key)
{
    if (json->type != JSON_OBJECT)
        return NULL;
    for (size_t index = 0; json->value.object->size > index; index++) {
        if (my_strcmp(json->value.object->pairs[index].name, key) == 0)
            return &json->value.object->pairs[index];
    }
    return NULL;
}

json_value_t *json_get_array(json_value_t *json, size_t index)
{
    if (json->type != JSON_ARRAY)
        return NULL;
    if (json->value.array->size <= index)
        return NULL;
    return &json->value.array->value[index];
}

double json_get_float(json_value_t *json)
{
    return json->type == JSON_NUMBER ? json->value.number : -84;
}

char *json_get_string(json_value_t *json)
{
    return json->type == JSON_STRING ? json->value.string : NULL;
}
