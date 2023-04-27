/*
** EPITECH PROJECT, 2023
** format_str.c
** File description:
** function which format an str with \n
*/

#include "sfml_includes.h"

char *format_str(char *str, int page)
{
    char *new = NULL;
    int len = 184;
    int i = page * 180;
    int index = 0;
    int line = 0;

    new = malloc(sizeof(char) * (len + 1));
    while (index < len) {
        if (str[i] == 0)
            new[index++] = '\0';
        else
            new[index++] = str[i++];
        line++;
        if (line == 45) {
            line = 0;
            new[index++] = '\n';
        }
    } new[index] = '\0';
    return new;
}

void free_dialog(dialog_t *dialog)
{
    if (dialog == NULL)
        return;
    free(dialog->all_text);
    free(dialog->name);
    free(dialog->cur_buf);
    sfText_destroy(dialog->buffer);
    sfText_destroy(dialog->speaker);
    sfFont_destroy(dialog->font);
    sfSprite_destroy(dialog->sprite);
    sfTexture_destroy(dialog->texture);
    free(dialog);
}
