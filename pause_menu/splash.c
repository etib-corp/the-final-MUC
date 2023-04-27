/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** game_over
*/

#include "sfml_includes.h"

void animate_start_splash(splash_t *logo, int frame, int frame_max,
game_t *game)
{
    sfRenderWindow_clear(game->win, sfBlack);
    sfRenderWindow_setView(game->win, game->view->cinematic);
    manage_dt(game);
    if (frame >= frame_max)
        return;
    int current_frame = frame;
    if (game->dt >= DT)
        frame++;
    if (current_frame >= logo->nb_texture)
        current_frame = logo->nb_texture - 1;
    sfSprite_setTextureRect(logo->sprite, IR(logo->witdh *
    current_frame, 0, logo->witdh, logo->height));
    sfRenderWindow_drawSprite(game->win, logo->sprite, NULL);
    sfRenderWindow_display(game->win);
    return animate_start_splash(logo, frame, frame_max, game);
}

bool animate_splash(float dt, splash_t *go)
{
    if (dt >= DT) {
        go->current_texture = (go->current_texture + 1) % go->nb_texture;
    }
    if (go->current_texture >= go->nb_texture -1)
        return true;
    sfSprite_setTextureRect(go->sprite, IR( go->witdh * go->current_texture,
    0, go->witdh, go->height));
    return false;
}

splash_t *init_splash(char *path, int witdh, int height, int nb_anin)
{
    splash_t *new = malloc(sizeof(splash_t));

    if (new == NULL)
        return NULL;
    new->current_texture = 0;
    new->nb_texture = nb_anin;
    new->witdh = witdh;
    new->height = height;
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    return new;
}

void free_splash(splash_t *splash)
{
    MY_FREE(splash->sprite, sfSprite_destroy);
    MY_FREE(splash->texture, sfTexture_destroy);
}
