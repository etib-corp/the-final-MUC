/*
** EPITECH PROJECT, 2023
** inventory.c
** File description:
** inventory
*/

#include "sfml_includes.h"

void free_inventory(inventory_t *i)
{
    if (i == NULL)
        return;
    for (int j = 0; i->content != NULL && i->content[j] != NULL; j++)
        free_dropable(i->content[j]);
    if (i->content != NULL)
        free(i->content);
    sfSprite_destroy(i->bg_sprite);
    sfSprite_destroy(i->containers_sprite);
    sfTexture_destroy(i->bg_texture);
    sfTexture_destroy(i->containers_texture);
    sfText_destroy(i->text_coins);
}

dropable_t **empty_inventory(void)
{
    dropable_t **tab = malloc(sizeof(dropable_t) * 21);

    for (int i = 0; i < 20; i++) {
        tab[i] = malloc(sizeof(dropable_t));
        tab[i]->infos = NULL;
        tab[i]->name = NULL;
        tab[i]->sprite = NULL;
        tab[i]->texture = NULL;
    } tab[20] = NULL;
    return tab;
}

void draw_inventory(inventory_t *inv, sfRenderWindow *win)
{
    if (inv->display == false) {
        return;
    }
    sfRenderWindow_drawSprite(win, inv->bg_sprite, NULL);
    sfRenderWindow_drawSprite(win, inv->containers_sprite, NULL);
    sfRenderWindow_drawText(win, inv->text_coins, NULL);
    for (int i = 0; inv->content[i] != NULL &&
        inv->content[i]->sprite != NULL; i++)
        sfRenderWindow_drawSprite(win, inv->content[i]->sprite, NULL);
    if (inv->display_info) {
        sfRenderWindow_drawSprite(win, inv->info_sprite, NULL);
        sfRenderWindow_drawText(win, inv->info_name, NULL);
        sfRenderWindow_drawText(win, inv->info_text, NULL);
    }
}

void set_inventory_info(inventory_t *i, sfFont const *font)
{
    i->info_sprite = sfSprite_create();
    i->info_texture = sfTexture_createFromFile(INV_INFO, NULL);
    sfSprite_setPosition(i->info_sprite, V2F(1500, 450));
    sfSprite_setTexture(i->info_sprite, i->info_texture, sfTrue);
    i->info_text = create_text("", font, V2F(1550, 600));
    i->info_name = create_text("", font, V2F(1550, 500));
    sfText_scale(i->info_text, V2F(0.5, 0.5));
}

inventory_t *create_inventory(sfFont const *font)
{
    inventory_t *i = malloc(sizeof(inventory_t));
    if (i == NULL)
        return NULL;
    i->bg_sprite = sfSprite_create();
    sfSprite_setPosition(i->bg_sprite, V2F(460, 40));
    i->bg_texture = sfTexture_createFromFile(INV_BG, NULL);
    sfSprite_setTexture(i->bg_sprite, i->bg_texture, sfTrue);
    i->containers_sprite = sfSprite_create();
    sfSprite_setPosition(i->containers_sprite, V2F(660, 240));
    i->containers_texture = sfTexture_createFromFile(INV_CONTAINERS, NULL);
    sfSprite_setTexture(i->containers_sprite, i->containers_texture, sfTrue);
    i->text_coins = create_text("COINS = 0", font, V2F(660, 800));
    i->content = empty_inventory();
    set_inventory_info(i, font);
    i->coins = 0;
    i->display_info = false;
    i->display = false;
    return i;
}
