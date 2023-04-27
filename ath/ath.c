/*
** EPITECH PROJECT, 2023
** ath.c
** File description:
** all functions relatives to ath
*/

#include "sfml_includes.h"

sfSprite **create_sprite_tab(sfTexture *texture, int nbr, float scale)
{
    sfSprite **tab = malloc(sizeof(sfSprite *) * (nbr + 1));

    for (int i = 0; i < nbr; i++) {
        tab[i] = sfSprite_create();
        sfSprite_setTexture(tab[i], texture, sfTrue);
        sfSprite_scale(tab[i], V2F(scale, scale));
        sfSprite_setPosition(tab[i], V2F(0 + (i * 80), 0));
    } tab[nbr] = NULL;
    return tab;
}

sfText *set_text(char *to_set)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT);

    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setString(text, to_set);
    sfText_setPosition(text, V2F(200, 980));
    return text;
}

sfTexture **set_weapons_textures(void)
{
    sfTexture **textures = malloc(sizeof(sfTexture *) * 4);

    if (textures == NULL)
        return NULL;
    textures[0] = sfTexture_createFromFile(DAGGER, NULL);
    textures[1] = sfTexture_createFromFile(SWORD, NULL);
    textures[2] = sfTexture_createFromFile(AXE, NULL);
    textures[3] = NULL;
    return textures;
}

ath_t *init_ath(void)
{
    ath_t *ath = malloc(sizeof(ath_t));
    ath->heart_texture = sfTexture_createFromFile(HEART, NULL);
    ath->health = create_sprite_tab(ath->heart_texture, 5, 0.3);
    ath->cur_lvl = 0; ath->dialog = NULL;
    ath->level = my_strcat(my_strdup("LEVEL : "), my_itoa(0));
    ath->text = set_text(ath->level);
    ath->choice = create_choice(sfText_getFont(ath->text));
    ath->is_choosing = false;
    ath->inventory = create_inventory(sfText_getFont(ath->text));
    ath->block_sprite = sfSprite_create();
    ath->weapon_sprite = sfSprite_create();
    ath->block_texture = sfTexture_createFromFile(WEAPON_BLOCK, NULL);
    sfSprite_setTexture(ath->block_sprite, ath->block_texture, sfTrue);
    sfSprite_setPosition(ath->block_sprite, V2F(0, 880));
    sfSprite_setPosition(ath->weapon_sprite, V2F(0, 880));
    sfSprite_scale(ath->weapon_sprite, V2F(12, 12));
    ath->weapon_textures = set_weapons_textures();
    ath->npc = NULL;
    ath->xp_bar = create_rectangle(V2F(20, 20), V2F(200, 960), sfBlue);
    return ath;
}

void update_ath(ath_t *ath, player_t *player, game_t *game)
{
    if (ath->cur_lvl != player->lvl) {
        ath->cur_lvl = player->lvl;
        if (ath->level == NULL)
            free(ath->level);
        ath->level = my_strcat(my_strdup("LEVEL : "), my_itoa(player->lvl));
        sfText_setString(ath->text, ath->level);
    } for (int i = 0; ath->health[i] != NULL; i++)
        sfSprite_setPosition(ath->health[i], V2F(0 + (i * 80), 0));
    sfSprite_setTexture(ath->weapon_sprite,
        ath->weapon_textures[player->current_weapon], sfTrue);
    update_choice(ath->choice, game);
    if (game->dt > DT)
        update_dialog(ath->dialog);
    if (ath->dialog != NULL && my_strlen(ath->dialog->cur_buf) < 180)
        ath->is_choosing = true;
    update_inventory(ath->inventory, game);
    update_xpbar(player->xp, ath->xp_bar);
}
