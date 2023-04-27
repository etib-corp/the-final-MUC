/*
** EPITECH PROJECT, 2023
** pause_menu.c
** File description:
** all functions which manage pause menu
*/

#include "sfml_includes.h"

pbutton_t **set_pause_buttons(sfFont const *font)
{
    pbutton_t **button = malloc(sizeof(pbutton_t) * 6);

    if (button == NULL)
        return NULL;
    button[0] = create_pbutton("Resume", resume_func, V2F(710, 116), font);
    button[1] = create_pbutton("Save", save_func, V2F(710, 332), font);
    button[2] = create_pbutton("Settings", settings_func, V2F(710, 548), font);
    button[3] = create_pbutton("Menu", menu_func, V2F(710, 764), font);
    button[4] = create_pbutton("Help", help_func, V2F(1400, 20), font);
    button[5] = NULL;
    return button;
}

sfTexture **set_pmenu_texture(void)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * 4);

    if (texture == NULL)
        return NULL;
    texture[0] = sfTexture_createFromFile(PBUTTON_IDLE, NULL);
    texture[1] = sfTexture_createFromFile(PBUTTON_HOVER, NULL);
    texture[2] = sfTexture_createFromFile(PBUTTON_CLICKED, NULL);
    texture[3] = NULL;
    return texture;
}

pmenu_t *init_pause_menu(sfFont const *font)
{
    pmenu_t *menu = malloc(sizeof(pmenu_t));
    if (menu == NULL)
        return NULL;
    menu->button = set_pause_buttons(font);
    menu->texture = set_pmenu_texture();
    menu->sprite = sfSprite_create();
    menu->title = NULL;
    menu->bg_texture = sfTexture_createFromFile(BG_TRANSPARENT, NULL);
    sfSprite_setTexture(menu->sprite, menu->bg_texture, sfTrue);
    return menu;
}
