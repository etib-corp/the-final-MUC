/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** parsing
*/

#ifndef PARSING_H_
    #define PARSING_H_

    #include "sfml_includes.h"

    #include <sys/stat.h>
    #include <stdbool.h>

    typedef struct json_value_s {
        union {
            char *string;
            struct json_object_s *object;
            struct json_array_s *array;
            double number;
            bool bol;
        } value;
        enum {
            JSON_NULL,
            JSON_STRING,
            JSON_OBJECT,
            JSON_ARRAY,
            JSON_NUMBER,
            JSON_BOOL
        } type;
    } json_value_t;

    typedef struct json_pair_s {
        char *name;
        json_value_t *value;
    } json_pair_t;

    typedef struct json_object_s {
        json_pair_t *pairs;
        size_t size;
    } json_object_t;


    typedef struct json_array_s {
        size_t size;
        json_value_t *value;
    } json_array_t;

    json_array_t *create_json_array(void);
    bool parser_json_string(char **str, json_value_t *json);
    void skip_char(char **str, char *token);
    bool json_parser(char **str, json_value_t *json);
    void free_json_array(json_array_t *array);
    json_value_t *create_json_value(void);
    void free_json_value(json_value_t *value, bool free_value);
    char *stock_all_file(char *file);
    bool resize_json_array(json_array_t *array);
    bool parser_json_array(char **str, json_value_t *json);
    json_pair_t *create_json_pair(void);
    void free_json_pair(json_pair_t *pair);
    bool resize_json_object(json_object_t *object);
    bool parser_json_pair(char **str, json_pair_t *pair);
    void free_json_object(json_object_t *object);
    bool parser_json_object(char **str, json_value_t *json);
    bool parser_json_bool(char **str, json_value_t *json);
    bool parser_json_float(char **str, json_value_t *json);
    json_value_t *parseur(char *file);
    json_pair_t *json_get_objet(json_value_t *json, char *key);
    json_value_t *json_get_array(json_value_t *json, size_t index);
    double json_get_float(json_value_t *json);
    char *json_get_string(json_value_t *json);

#endif /* !PARSING_H_ */
