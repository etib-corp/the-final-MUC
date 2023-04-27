/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** json_pair
*/
#include "sfml_includes.h"


json_pair_t *create_json_pair(void)
{
    json_pair_t *pair = malloc(sizeof(json_pair_t));

    if (pair == NULL)
        return NULL;
    pair->name = NULL;
    pair->value = NULL;
    return pair;
}

void free_json_pair(json_pair_t *pair)
{
    MY_FREE(pair->name, free);
    MY_FREE_VA(pair->value, free_json_value, true);
}

bool parser_json_pair(char **str, json_pair_t *pair)
{
    json_value_t *tmp = NULL; skip_char(str, " \t\n\r");
    if (**str != '"')
        return false;
    tmp = create_json_value();
    if (!parser_json_string(str, tmp)) {
        free_json_value(tmp, true);
        return false;
    } pair->name = tmp->value.string;
    free(tmp);
    skip_char(str, " \t\n\r");
    if (**str != ':') {
        MY_FREE(pair->name, free);
        return false;
    } (*str)++;
    skip_char(str, " \t\n\r"); pair->value = create_json_value();
    if (!json_parser(str, pair->value)) {
        MY_FREE(pair->name, free);
        MY_FREE_VA(pair->value, free_json_value, true);
        return false;
    } return true;
}
