/*
** EPITECH PROJECT, 2023
** menu_parser.c
** File description:
** all functions to parse the menu conf file
*/
#include "sfml_includes.h"

char *stock_all_file(char *file)
{
    char *buff = NULL;
    int fd = open(file, O_RDONLY);
    struct stat st = {0};
    if (fd == -1)
        return NULL;
    if (stat(file, &st) == -1)
        return NULL;
    buff = malloc(sizeof(char) * (st.st_size + 1));
    if (buff == NULL)
        return NULL;
    read(fd, buff, st.st_size);
    buff[st.st_size] = '\0';
    close(fd);
    return buff;
}

void skip_char(char **str, char *token)
{
    while (skip(**str, token))
        (*str)++;
}

bool json_parser(char **str, json_value_t *json)
{
    skip_char(str, " \t\n\r");
    switch (**str) {
    case '\0':
        return true;
    case '"':
        return parser_json_string(str, json);
    case '[':
        return parser_json_array(str, json);
    case '{':
        return parser_json_object(str, json);
    case 'f':
    case 't':
        return parser_json_bool(str, json);
    default:
        return parser_json_float(str, json);
    }
    return false;
}

json_value_t *parseur(char *file)
{
    char *buff = stock_all_file(file);
    char *ptr = buff;
    json_value_t *json = NULL;

    if (buff == NULL)
        return NULL;
    json = create_json_value();
    if (!json_parser(&buff, json)) {
        MY_FREE(ptr, free);
        MY_FREE_VA(json, free_json_value, true);
        return NULL;
    }
    skip_char(&buff, " \t\n\r");
    if (*buff != '\0') {
        MY_FREE(ptr, free);
        MY_FREE_VA(json, free_json_value, true);
        return NULL;
    }
    MY_FREE(ptr, free);
    return json;
}
