/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** init_chocobo
*/

#include "sfml_includes.h"

sfTexture **init_textures_chocobo(void)
{
    sfTexture **new_tex = malloc(sizeof(sfTexture *) * (NB_ANI_CHOCOBO + 1));
    if (new_tex == NULL)
        return NULL;
    new_tex[0] = sfTexture_createFromFile(IDLE_CHOCOBO, NULL);
    new_tex[1] = sfTexture_createFromFile(LEFT_CHOCOBO, NULL);
    new_tex[2] = sfTexture_createFromFile(RIGHT_CHOCOBO, NULL);
    new_tex[3] = sfTexture_createFromFile(UP_CHOCOBO, NULL);
    new_tex[4] = sfTexture_createFromFile(DOWN_CHOCOBO, NULL);
    new_tex[5] = NULL;
    return new_tex;
}

chocobo_t *init_chocobo(sfVector2f pos_max, sfVector2f pos_min)
{
    chocobo_t *new = malloc(sizeof(chocobo_t));
    if (new == NULL)
        return NULL;
    new->sprite = sfSprite_create();
    new->current_texture = 0;
    new->speed = PLAYER_MOUNT_SPEED;
    new->time_state = 0;
    new->nb_texture = 3;
    new->texture_ind = 0;
    new->current_texture = 0;
    new->pos_max = pos_max;
    new->pos_min = pos_min;
    new->state = CHOCO_MOVE;
    new->whistle = init_soundtrack("assets/music_and_sound/whistle.ogg");
    new->end_pos = V2F(my_random(pos_min.x, pos_max.x),
    my_random(pos_min.y, pos_max.y));
    new->textures = init_textures_chocobo();
    if (new->textures == NULL)
        return NULL;
    return new;
}

void free_chocobo(chocobo_t *chocobo)
{
    MY_FREE(chocobo->whistle, destroy_soundtrack);
    sfSprite_destroy(chocobo->sprite);
    for (int i = 0; i < NB_ANI_CHOCOBO; i++) {
        sfTexture_destroy(chocobo->textures[i]);
    }
    MY_FREE(chocobo, free);
}
