/*
** EPITECH PROJECT, 2023
** dropable.c
** File description:
** all dropable functions
*/

#include "sfml_includes.h"

void free_dropable(dropable_t *item)
{
    if (item == NULL)
        return;
    free(item->infos);
    free(item->name);
    sfSprite_destroy(item->sprite);
    sfTexture_destroy(item->texture);
}

dropable_t *create_dropable(char *tex, char *name, char *inf, sfVector2f pos)
{
    dropable_t *item = malloc(sizeof(dropable_t));

    if (item == NULL)
        return NULL;
    item->infos = my_strdup(inf);
    item->name = my_strdup(name);
    item->sprite = sfSprite_create();
    item->texture = sfTexture_createFromFile(tex, NULL);
    item->display = true;
    sfSprite_setTexture(item->sprite, item->texture, sfTrue);
    sfSprite_setPosition(item->sprite, pos);
    return item;
}

void update_dropable(player_t *player, void *e, inventory_t *inv)
{
    dropable_t *item = CAST(dropable_t *, e);
    if (item->display == false)
        return;
    sfFloatRect tmp = sfSprite_getGlobalBounds(item->sprite);
    sfIntRect rect = IR((int)tmp.left, (int)tmp.top, (int)tmp.width,
        (int)tmp.height);

    if (sfIntRect_contains(&rect, (int)player->pos.x + 22,
        (int)player->pos.y + 22)) {
        add_dropable(item, inv->content);
        item->display = false;
    }
}
