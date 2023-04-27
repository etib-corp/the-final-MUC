/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** json_value
*/
#include "sfml_includes.h"


json_value_t *create_json_value(void)
{
    return my_calloc(1, sizeof(json_value_t));
}

void free_json_value(json_value_t *value, bool free_value)
{
    switch (value->type) {
        case JSON_BOOL:
        case JSON_NUMBER:
        case JSON_NULL:
            break;
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_ARRAY:
            free_json_array(value->value.array);
            break;
        case JSON_OBJECT:
            free_json_object(value->value.object);
            break;
    } if (free_value)
        free(value);
}
