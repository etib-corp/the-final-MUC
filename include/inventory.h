/*
** EPITECH PROJECT, 2023
** inventory.h
** File description:
** .h of inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #include "sfml_includes.h"

    #define INV_BG "assets/UI/inventory_bg.png"
    #define INV_CONTAINERS "assets/UI/containers.png"
    #define INV_INFO "assets/UI/infos_bg.png"

    inventory_t *create_inventory(sfFont const *font);
    void update_inventory(inventory_t *inv, game_t *game);
    void free_inventory(inventory_t *i);
    bool add_dropable(dropable_t *item, dropable_t **tab);
    void draw_inventory(inventory_t *inv, sfRenderWindow *win);


#endif /* !INVENTORY_H_ */
