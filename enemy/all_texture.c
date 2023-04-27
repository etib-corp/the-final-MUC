/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** all_texture
*/

#include "sfml_includes.h"


sfTexture **init_skeleton_textures(void)
{
    sfTexture **new = malloc(sizeof(sfTexture *) * (3));
    if (!new)
        return NULL;
    new[0] = sfTexture_createFromFile(SKELL_DEATH, NULL);
    new[1] = sfTexture_createFromFile(SKELL_LEFT, NULL);
    new[2] = sfTexture_createFromFile(SKELL_RIGHT, NULL);
    return new;
}

sfTexture **init_rogue_textures(void)
{
    sfTexture **new = malloc(sizeof(sfTexture *) * (3));
    if (!new)
        return NULL;
    new[0] = sfTexture_createFromFile(ROGUE_DEATH, NULL);
    new[1] = sfTexture_createFromFile(ROGUE_LEFT, NULL);
    new[2] = sfTexture_createFromFile(ROGUE_RIGHT, NULL);
    return new;
}

sfTexture **init_mage_textures(void)
{
    sfTexture **new = malloc(sizeof(sfTexture *) * (3));
    if (!new)
        return NULL;
    new[0] = sfTexture_createFromFile(MAGE_DEATH, NULL);
    new[1] = sfTexture_createFromFile(MAGE_LEFT, NULL);
    new[2] = sfTexture_createFromFile(MAGE_RIGHT, NULL);
    return new;
}
