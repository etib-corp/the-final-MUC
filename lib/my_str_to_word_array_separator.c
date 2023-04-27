/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-leo.sautron
** File description:
** my_str_to_word_array
*/

#include "lib.h"

static int skip(char c, char *token)
{
    for (int i = 0; token[i]; i++) {
        if (token[i] == c)
            return 1;
    }
    return 0;
}

static int nb_of_str(char *str, char *token)
{
    int i = 1;
    int c = 0;
    if (m_strlen(str) == 0)
        return 0;
    while (str[i]) {
        if (str[i + 1] == '\0' && skip(str[i], token) != 1)
            c++;
        if (skip(str[i], token) != 1 && skip(str[i - 1], token)) {
            i++;
            continue;
        }
        if (str[i] != '\0' && skip(str[i], token) &&
        skip(str[i - 1], token) != 1)
            c++;
        i++;
    }
    return c;
}

static char *replace(char *str, char *token)
{
    int i = 0;
    while (str[i] != '\0') {
        if (skip(str[i], token))
            str[i] = '\0';
        i++;
    }
    return str;
}

char **my_str_to_word_array_separator(char *str1, char *token)
{
    char *str = my_strdup(str1);
    int count = nb_of_str(str, token);
    if (count == 0 || str == NULL)
        return NULL;
    char **tab = malloc(sizeof(char *) * (count + 1));
    int x = 0;
    str = replace(str, token);
    if (tab == NULL)
        return NULL;
    for (int i = 0; count > x; i++) {
        if (str[i] == '\0')
            continue;
        tab[x] = my_strdup(str + i);
        i += m_strlen(tab[x]);
        x++;
    }
    free(str);
    tab[x] = NULL;
    return tab;
}
