/*
** EPITECH PROJECT, 2023
** settings.c
** File description:
** all fucntions to settings
*/

#include "sfml_includes.h"

void return_func(game_t *game)
{
    game->state = game->last_state;
}

pbutton_t **set_settings_buttons(sfFont const *font)
{
    pbutton_t **button = malloc(sizeof(pbutton_t) * 7);

    if (button == NULL)
        return NULL;
    button[0] = create_pbutton("Sound +", sound_plus, V2F(1230, 648), font);
    button[1] = create_pbutton("Sound -", sound_minus, V2F(190, 648), font);
    button[2] = create_pbutton("Sound Off", sound_off, V2F(710, 648), font);
    button[3] = create_pbutton("1920x1080", change_res, V2F(460, 428), font);
    button[4] = create_pbutton("Fullscreen", change_mode, V2F(980, 428), font);
    button[5] = create_pbutton("Back", return_func, V2F(20, 20), font);
    button[6] = NULL;
    return button;
}

pmenu_t *init_settings(sfFont const *font)
{
    pmenu_t *menu = malloc(sizeof(pmenu_t));
    if (menu == NULL)
        return NULL;
    menu->button = set_settings_buttons(font);
    menu->texture = set_pmenu_texture();
    menu->sprite = sfSprite_create();
    menu->ind = 0;
    menu->title = NULL;
    menu->bg_texture = sfTexture_createFromFile(BG_SETTINGS, NULL);
    sfSprite_setTexture(menu->sprite, menu->bg_texture, sfTrue);
    return menu;
}
