/*
** EPITECH PROJECT, 2023
** update_inventory.c
** File description:
** all functioncs which update the inventory
*/

#include "sfml_includes.h"

void set_in_inv(sfSprite *sprite, int index)
{
    int x = index % 5;
    int y = index % 4;

    sfSprite_setPosition(sprite, V2F(700 + (x * 114), 275 + (y * 85)));
}

bool add_dropable(dropable_t *item, dropable_t **tab)
{
    int index = 0;

    while (tab[index] != NULL && tab[index]->name != NULL)
        index++;
    if (tab[index] == NULL)
        return false;
    tab[index]->infos = my_strdup(item->infos);
    tab[index]->name = my_strdup(item->name);
    tab[index]->sprite = sfSprite_copy(item->sprite);
    tab[index]->texture = sfTexture_copy(item->texture);
    sfSprite_setTexture(tab[index]->sprite, tab[index]->texture,sfTrue);
    sfSprite_scale(tab[index]->sprite, V2F(4.0, 4.0));
    set_in_inv(tab[index]->sprite, index);
    return true;
}

void update_info(inventory_t *inv, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win);
    sfFloatRect tmp;
    sfIntRect rect;

    for (int i = 0; inv->content[i] != NULL &&
        inv->content[i]->sprite != NULL; i++) {
        tmp = sfSprite_getGlobalBounds(inv->content[i]->sprite);
        rect = IR((int)tmp.left, (int)tmp.top, (int)tmp.width, (int)tmp.height);
        if (sfIntRect_contains(&rect, mouse.x, mouse.y)) {
            sfText_setString(inv->info_name, inv->content[i]->name);
            sfText_setString(inv->info_text, inv->content[i]->infos);
            inv->display_info = true;
            return;
        }
    } inv->display_info = false;
    sfText_setString(inv->info_name, "");
    sfText_setString(inv->info_text, "");
}

void heal_player(game_t *game, inventory_t *inv)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->win);
    sfIntRect tmp = {0}; player_t *pyr = game->player;
    sfFloatRect frect = {0};
    for (int i = 0; inv->content[i] != NULL; i++) {
        if (inv->content[i]->sprite != NULL) {
            frect = sfSprite_getGlobalBounds(inv->content[i]->sprite);
            tmp = IR((int)frect.left, (int)frect.top, (int)frect.width,
                (int)frect.height);
        } if (sfIntRect_contains(&tmp, mouse.x, mouse.y) &&
            my_strcmp(inv->content[i]->name, "Apple") == 0) {
                free_dropable(inv->content[i]);
                pyr->life += pyr->life < 4 ? 1 : 0;
                inv->content[i]->display = false;
                inv->content[i]->infos = NULL;
                inv->content[i]->name = NULL;
                inv->content[i]->sprite = NULL;
                inv->content[i]->texture = NULL;
                return;
            }
    }
}

void update_inventory(inventory_t *inv, game_t *game)
{
    int passed = 0;
    if (game->player->coins != inv->coins) {
        inv->coins = game->player->coins;
        sfText_setString(inv->text_coins,
        my_strcat(my_strdup("COINS = "), my_itoa(inv->coins)));
    } if (game->dt < DT)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft) && inv->display)
        heal_player(game, inv);
    if (inv->display == false && SKP(sfKeyE)) {
        inv->display = true;
        passed++;
    } if (inv->display && (SKP(sfKeyE) || SKP(sfKeyEscape)) && passed == 0)
        inv->display = false;
    if (inv->display)
        update_info(inv, game);
}
