/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** dialogs
*/

#ifndef DIALOGS_H_
    #define DIALOGS_H_

    #include "sfml_includes.h"

    #define FONT "assets/Adumu.ttf"
    #define TEXT_BLOC "assets/UI/text_guard.png"

    char *format_str(char *str, int page);
    sfText *create_text(char *text, sfFont const *font, sfVector2f pos);
    void draw_dialog(dialog_t *dialog, sfRenderWindow *win);
    void change_dialog(dialog_t *dialog, char *text, char *name);
    void update_dialog(dialog_t *dialog);
    dialog_t *init_dialog(char *text, char *name);
    void free_dialog(dialog_t *dialog);

#endif /* !DIALOGS_H_ */
