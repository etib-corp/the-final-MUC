/*
** EPITECH PROJECT, 2023
** dialogs.C
** File description:
** all functions for dialogs
*/

#include "sfml_includes.h"

sfText *create_text(char *text, sfFont const *font, sfVector2f pos)
{
    sfText *res = sfText_create();

    if (res == NULL)
        return NULL;
    sfText_setFont(res, font);
    sfText_setString(res, text);
    sfText_setPosition(res, pos);
    sfText_scale(res, V2F(2.0, 2.0));
    sfText_setColor(res, sfBlack);
    return res;
}

dialog_t *init_dialog(char *text, char *name)
{
    dialog_t *dialog = malloc(sizeof(dialog_t));

    if (dialog == NULL)
        return NULL;
    dialog->page = 0;
    dialog->all_text = my_strdup(text);
    dialog->name = my_strdup(name);
    dialog->font = sfFont_createFromFile(FONT);
    dialog->cur_buf = format_str(dialog->all_text, dialog->page);
    dialog->buffer = create_text(dialog->cur_buf, dialog->font, V2F(400, 750));
    dialog->speaker = create_text(dialog->name, dialog->font, V2F(100, 750));
    dialog->sprite = sfSprite_create();
    dialog->texture = sfTexture_createFromFile(TEXT_BLOC, NULL);
    sfSprite_setTexture(dialog->sprite, dialog->texture, sfTrue);
    sfSprite_setPosition(dialog->sprite, V2F(50, 680));
    sfText_scale(dialog->speaker, V2F(0.5, 0.5));
    sfText_scale(dialog->buffer, V2F(0.8, 0.8));
    return dialog;
}

void update_dialog(dialog_t *dialog)
{
    if (dialog == NULL)
        return;
    if (!SKP(sfKeyT))
        return;
    if (my_strlen(dialog->cur_buf) >= 180)
        dialog->page++;
    free(dialog->cur_buf);
    dialog->cur_buf = format_str(dialog->all_text, dialog->page);
    sfText_setString(dialog->buffer, dialog->cur_buf);
}

void change_dialog(dialog_t *dialog, char *text, char *name)
{
    if (dialog == NULL) {
        dialog = init_dialog(text, name);
        return;
    }
    free(dialog->all_text);
    free(dialog->cur_buf);
    free(dialog->speaker);
    dialog->all_text = my_strdup(text);
    dialog->name = my_strdup(name);
    dialog->page = 0;
    dialog->cur_buf = format_str(dialog->all_text, dialog->page);
    sfText_setString(dialog->buffer, dialog->cur_buf);
    sfText_setString(dialog->speaker, dialog->name);
}

void draw_dialog(dialog_t *dialog, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, dialog->sprite, NULL);
    sfRenderWindow_drawText(win, dialog->speaker, NULL);
    sfRenderWindow_drawText(win, dialog->buffer, NULL);
}
