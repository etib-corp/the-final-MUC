/*
** EPITECH PROJECT, 2023
** menu_utils.c
** File description:
** all utils for menu
*/

#include "sfml_includes.h"

pbutton_t *create_pbutton(char *text, void (*func)(game_t *),
    sfVector2f pos, sfFont const *font)
{
    pbutton_t *button = malloc(sizeof(pbutton_t));

    if (button == NULL)
        return NULL;
    button->sprite = sfSprite_create();
    sfSprite_setPosition(button->sprite, pos);
    button->state = BT_STATIC;
    button->text = create_text(my_strdup(text), font, V2F(pos.x + 50,
        pos.y + 100));
    button->exec = func;
    return button;
}

void update_pbutton(pbutton_t *button, sfRenderWindow *win, float quotient)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfBool click = sfMouse_isButtonPressed(sfMouseLeft);
    sfFloatRect tmp = sfSprite_getLocalBounds(button->sprite);
    sfVector2f pos = sfSprite_getPosition(button->sprite);
    sfIntRect rect = IR((int)pos.x / quotient, (int)pos.y / quotient,
    (int)tmp.width / quotient, (int)tmp.height / quotient);

    if (sfIntRect_contains(&rect, mouse.x, mouse.y)) {
        button->state = BT_HOVER;
        if (click && my_strcmp(sfText_getString(button->text), "Continue")
        == 0 && check_save())
            button->state = BT_PRESSED;
        if (click && my_strcmp(sfText_getString(button->text), "Continue") != 0
        )
            button->state = BT_PRESSED;
        return;
    } button->state = BT_STATIC;
}

void draw_pbutton(pbutton_t *button, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, button->sprite, NULL);
    sfRenderWindow_drawText(win, button->text, NULL);
}

void draw_pmenu(pmenu_t *menu, sfRenderWindow *win)
{
    sfRenderWindow_drawSprite(win, menu->sprite, NULL);
    if (menu->title != NULL)
        sfRenderWindow_drawText(win, menu->title, NULL);
    for (int i = 0; menu->button[i] != NULL; i++) {
        if (my_strcmp(sfText_getString(menu->button[i]->text), "Continue") != 0)
            draw_pbutton(menu->button[i], win);
        if (my_strcmp(sfText_getString(menu->button[i]->text), "Continue") == 0
            && check_save())
            draw_pbutton(menu->button[i], win);
    }
}

void update_pmenu(pmenu_t *menu, game_t *game)
{
    for (int i = 0; menu->button[i] != NULL; i++) {
        update_pbutton(menu->button[i], game->win, game->quotient);
        sfSprite_setTexture(menu->button[i]->sprite,
            menu->texture[menu->button[i]->state], sfTrue);
        if (menu->button[i]->state == BT_PRESSED)
            menu->button[i]->exec(game);
    }
}
