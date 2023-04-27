/*
** EPITECH PROJECT, 2023
** main_menu.c
** File description:
** all functions for main menu
*/

#include "sfml_includes.h"

pbutton_t **set_main_buttons(sfFont const *font)
{
    pbutton_t **button = malloc(sizeof(pbutton_t) * 6);

    if (button == NULL)
        return NULL;
    button[0] = create_pbutton("Continue", play_func, V2F(710, 450), font);
    button[1] = create_pbutton("Start", start_func, V2F(20, 648), font);
    button[2] = create_pbutton("Settings", settings_func, V2F(20, 864), font);
    button[3] = create_pbutton("Help", help_func, V2F(1400, 648), font);
    button[4] = create_pbutton("Exit", exit_func, V2F(1400, 864), font);
    button[5] = NULL;
    return button;
}

void animate_menu(pmenu_t *menu, float dt, int quotient)
{
    (void)quotient;
    if (dt > DT)
        menu->ind = (menu->ind + 1) % NB_ANIM_MENU;
    sfSprite_setTextureRect(menu->sprite, IR(1920 * menu->ind, 0,
    1920, 1080));
}

pmenu_t *init_main_menu(sfFont const *font)
{
    pmenu_t *menu = malloc(sizeof(pmenu_t));
    if (menu == NULL)
        return NULL;
    menu->button = set_main_buttons(font);
    menu->texture = set_pmenu_texture();
    menu->sprite = sfSprite_create();
    menu->title = create_text("The Final MUC", font, V2F(730, 350));
    menu->ind = 0;
    menu->bg_texture = sfTexture_createFromFile(BG_MENU, NULL);
    sfSprite_setTexture(menu->sprite, menu->bg_texture, sfTrue);
    return menu;
}
