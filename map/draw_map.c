/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** draw_map
*/
#include "sfml_includes.h"

sfRenderStates *set_states(sfTexture *m_texture)
{
    sfRenderStates *states = malloc(sizeof(sfRenderStates));

    if (states == NULL)
        return NULL;
    states->texture = m_texture;
    states->shader = NULL;
    states->blendMode = sfBlendAlpha;
    states->transform = sfTransform_Identity;
    return states;
}

void draw_level(game_t *game, map_t *mapt, int level)
{
    sfRenderWindow_drawVertexArray(game->win, mapt->layers[level].layer,
    mapt->states);
}
