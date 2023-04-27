/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** check_file
*/
#include "sfml_includes.h"

bool is_valid(FILE *file)
{
    char *buf = NULL;
    size_t count = 0;
    getline(&buf, &count, file);
    if (my_strncmp(buf, "empty", 5) == 0)
        return false;
    if (my_strncmp(buf, "full", 4) == 0)
        return true;
    write(2, "Invalid file syntax, save can't be loaded\n", 42);
    return false;
}
