/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** push_in_list
*/

#include "sfml_includes.h"

sfTexture **set_texture(char *tex)
{
    if (my_strcmp(tex, "init_mage_textures") == 0)
        return init_mage_textures();
    if (my_strcmp(tex, "init_skeleton_textures") == 0)
        return init_skeleton_textures();
    if (my_strcmp(tex, "init_rogue_textures") == 0)
        return init_rogue_textures();
    return NULL;
}

action set_action(char *action)
{
    if (my_strcmp("buy_apple", action) == 0)
        return buy_apple;
    if (my_strcmp("buy_chocobo", action) == 0)
        return buy_chocobo;
    if (my_strcmp("buy_weapon", action) == 0)
        return buy_weapon;
    return none_function;
}

void push_enemy(map_t *mapt, char *tex, enemy_t *e)
{
    e->textures = set_texture(tex);
    push_front_list(mapt->tities, 1, ready_enemy, process_enemy, draw_enemy,
        destroy_enemy, false);
    CAST(entity_t *, mapt->tities->nodes->data)->instance = e;
}

void push_npc(map_t *mapt, npc_t *e, char *action)
{
    e->func = set_action(action);
    push_front_list(mapt->tities, 4, ready_npc, process_npc, draw_npc,
    destroy_npc, false);
    CAST(entity_t *, mapt->tities->nodes->data)->instance = e;
}

void push_item(map_t *mapt, dropable_t *e)
{
    push_front_list(mapt->tities, 3, ready_dropable, process_dropable,
    draw_dropable, destroy_dropable, false);
    CAST(entity_t *, mapt->tities->nodes->data)->instance = e;
}
