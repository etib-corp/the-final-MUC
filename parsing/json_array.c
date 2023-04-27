/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** json_array
*/
#include "sfml_includes.h"


json_array_t *create_json_array(void)
{
    json_array_t *array = malloc(sizeof(json_array_t));

    if (array == NULL)
        return NULL;
    array->size = 0;
    array->value = NULL;
    return array;
}

bool resize_json_array(json_array_t *array)
{
    if (array == NULL)
        return false;
    json_value_t *new_value = malloc(sizeof(json_value_t) * (array->size + 1));
    if (new_value == NULL)
        return NULL;
    for (size_t i = 0; array->size > i; i++) {
        new_value[i] = array->value[i];
    }
    free(array->value);
    array->value = new_value;
    array->size++;
    return true;
}

bool skip_array(char **str, json_array_t *array)
{
    while (1) {
        skip_char(str, " \t\n\r");
        if (!resize_json_array(array))
            return false;
        if (!json_parser(str, &array->value[array->size - 1]))
            return false;
        skip_char(str, " \t\n\r");
        if (**str == ']')
            break;
        if (**str != ',') {
            MY_FREE(array, free_json_array);
            return false;
        }
        (*str)++;
    } return true;
}

bool parser_json_array(char **str, json_value_t *json)
{
    (*str)++;
    json_array_t *array = create_json_array();
    if (array == NULL)
        return false;
    if (**str == ']') {
        json->value.array = array;
        json->type = JSON_ARRAY;
        (*str)++;
        return true;
    }
    if (skip_array(str, array) == false)
        return false;
    (*str)++;
    json->value.array = array;
    json->type = JSON_ARRAY;
    return true;
}

void free_json_array(json_array_t *array)
{
    if (array == NULL)
        return;
    for (size_t i = 0; array->size > i; i++)
        free_json_value(&array->value[i], false);
    free(array->value);
    free(array);
}
