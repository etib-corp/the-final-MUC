/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** create_npc
*/

#include "sfml_includes.h"

npc_t *init_npc(sfVector2f pos, dialog_t *dialog, char *texture)
{
    npc_t *new = malloc(sizeof(npc_t));

    if (new == NULL)
        return NULL;
    new->dialog = dialog;
    new->pos = pos;
    new->state = WAIT;
    new->func = NULL;
    new->textures = sfTexture_createFromFile(texture, NULL);
    if (new->textures == NULL)
        return NULL;
    new->zone = init_box(V2I(100, 100), V2I((int)pos.x - 50, (int)pos.y - 50),
        0);
    new->sprite = sfSprite_create();
    sfSprite_setPosition(new->sprite, pos);
    sfSprite_setTexture(new->sprite, new->textures, sfTrue);
    new->texture_ind = 0;
    new->s_dialog = false;
    return new;
}

void free_npc(npc_t *npc)
{
    if (npc == NULL)
        return;
    sfSprite_destroy(npc->sprite);
    sfTexture_destroy(npc->textures);
    free_box(npc->zone);
    free_dialog(npc->dialog);
}

void animate_npc(npc_t *npc, float dt)
{
    if (npc->texture_ind == 3) {
        npc->texture_ind = 0;
    }
    if (dt > DT) {
        sfSprite_setTextureRect(npc->sprite,
        IR(npc->texture_ind * 32, 0, 16, 32));
        npc->texture_ind++;
    }
}

void npc_process(npc_t *e, float dt, game_t *game)
{
    if (SKP(sfKeyEnter) && dt > DT && e->state != TALK)
        e->s_dialog = !e->s_dialog;
    switch (e->state) {
    case TALK:
        game->ath->dialog = e->dialog;
        game->ath->npc = e;
        break;
    case CHOICE:
        game->ath->is_choosing = true;
        break;
    default:
        break;
    }
    animate_npc(e, dt);
}
