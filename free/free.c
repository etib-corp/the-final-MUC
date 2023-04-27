/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** free_player
*/
#include "sfml_includes.h"

void free_view(view_t *v)
{
    MY_FREE(v->cinematic, sfView_destroy);
    MY_FREE(v->player, sfView_destroy);
    MY_FREE(v->minimap, sfView_destroy);
    MY_FREE(v, free);
}

void free_layers(map_layer_t *l)
{
    MY_FREE(l->layer, sfVertexArray_destroy);
    MY_FREE(l->name, free);
    MY_FREE(l, free);
}

void free_map(map_t *m)
{
    if (m == NULL)
        return;
    MY_FREE(m->layers, free_layers);
    MY_FREE(m->states, free);
    MY_FREE(m->json_map, free);
    MY_FREE(m->json_entity, free);
    MY_FREE(m, free);
}

void free_game(game_t *g)
{
    MY_FREE(g->win, sfRenderWindow_destroy);
    MY_FREE(g->map, free_map);
    MY_FREE(g->view, free_view);
    MY_FREE(g->clock, sfClock_destroy);
    free_quadtree(&g->qt);
    free_player(g->player);
    MY_FREE(g->world, sfTexture_destroy);
    MY_FREE(g, free);
}

void free_all(game_t *game)
{
    if (game != NULL)
        return;
    MY_FREE(game, free_game);
}
