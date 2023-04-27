/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** json_bool_string
*/
#include "sfml_includes.h"


bool parser_json_string(char **str, json_value_t *json)
{
    ++(*str);
    const char *start = *str;
    char *end = my_strchr(*str, '"');
    if (end) {
        *end = '\0';
        size_t len = end - start;
        json->value.string = my_strdup(start);
        if (json->value.string == NULL)
            return false;
        *str += len + 1;
        json->type = JSON_STRING;
        return true;
    } else {
        return false;
    }
}

bool parser_json_bool(char **str, json_value_t *json)
{
    const char *start = *str;
    if (my_strncmp(start, "false", 5) == 0) {
        json->value.bol = false;
        *str += 5;
        json->type = JSON_BOOL;
        return true;
    }
    if (my_strncmp(start, "true", 4) == 0) {
        json->value.bol = true;
        *str += 4;
        json->type = JSON_BOOL;
        return true;
    }
    return false;
}

bool parser_json_float(char **str, json_value_t *json)
{
    double number = 0.0; double dec = 0.0; bool is_neg = false;
    if (**str == '-') {
        is_neg = true;
        (*str)++;
    } if (my_is_digit(**str) == false)
        return false;
    number = my_getnbr(*str);
    skip_char(str, "0123456789");
    if (**str == '.') {
        (*str)++;
        if (my_is_digit(**str) == false)
            return false;
        dec = my_getnbr(*str);
        skip_char(str, "0123456789");
    } while (dec >= 1.0)
        dec /= 10;
    number += dec;
    json->value.number = is_neg ? -number : number;
    json->type = JSON_NUMBER;
    return true;
}
