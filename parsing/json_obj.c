/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** json_obj
*/
#include "sfml_includes.h"


json_object_t *create_json_object(void)
{
    return my_calloc(1, sizeof(json_object_t));
}

bool resize_json_object(json_object_t *object)
{
    if (object == NULL)
        return false;
    json_pair_t *new_pairs = malloc(sizeof(json_pair_t) * (object->size + 1));
    if (new_pairs == NULL)
        return NULL;
    for (size_t i = 0; object->size > i; i++)
        new_pairs[i] = object->pairs[i];
    free(object->pairs);
    object->pairs = new_pairs;
    object->size++;
    return true;
}

bool skip_obj(char **str, json_object_t *object)
{
    while (1) {
        skip_char(str, " \t\n\r");
        if (!resize_json_object(object))
            return false;
        if (!parser_json_pair(str, &object->pairs[object->size - 1]))
            return false;
        skip_char(str, " \t\n\r");
        if (**str == '}')
            break;
        if (**str != ',') {
            MY_FREE(object, free_json_object);
            return false;
        }
        (*str)++;
    }
    return true;
}

bool parser_json_object(char **str, json_value_t *json)
{
    json_object_t *object = create_json_object();
    (*str)++;
    if (object == NULL)
        return false;
    if (**str == '}') {
        json->value.object = object;
        json->type = JSON_OBJECT;
        (*str)++;
        return true;
    }
    if (skip_obj(str, object) == false)
        return false;
    json->value.object = object;
    json->type = JSON_OBJECT;
    (*str)++;
    return true;
}

void free_json_object(json_object_t *object)
{
    MY_FREE(object->pairs, free_json_pair);
    MY_FREE(object->pairs, free);
    free(object);
}
