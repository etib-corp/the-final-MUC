/*
** EPITECH PROJECT, 2023
** help.c
** File description:
** all functions for the help menu
*/

#include "sfml_includes.h"

pmenu_t *init_help_menu(sfFont const *font)
{
    pmenu_t *menu = malloc(sizeof(pmenu_t));
    if (menu == NULL)
        return NULL;
    menu->texture = set_pmenu_texture();
    menu->sprite = sfSprite_create();
    menu->ind = 0;
    menu->title = NULL;
    menu->bg_texture = sfTexture_createFromFile(HELP, NULL);
    sfSprite_setTexture(menu->sprite, menu->bg_texture, sfTrue);
    menu->button = malloc(sizeof(pbutton_t) * 2);
    if (menu->button == NULL)
        return NULL;
    menu->button[0] = create_pbutton("Back", return_func, V2F(20, 20), font);
    menu->button[1] = NULL;
    return menu;
}
