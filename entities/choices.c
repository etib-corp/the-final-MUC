/*
** EPITECH PROJECT, 2023
** choices.c
** File description:
** all functions for the choices
*/

#include "sfml_includes.h"

choice_t *create_choice(sfFont const *font)
{
    choice_t *choice = malloc(sizeof(choice_t));

    if (choice == NULL)
        return NULL;
    choice->bg_sprite = sfSprite_create();
    choice->bg_texture = sfTexture_createFromFile(CHOICE_TEXTURE, NULL);
    sfSprite_setTexture(choice->bg_sprite, choice->bg_texture, sfTrue);
    sfSprite_setPosition(choice->bg_sprite, V2F(1590, 350));
    sfSprite_scale(choice->bg_sprite, V2F(1.5, 1.5));
    choice->choices = malloc(sizeof(sfText *) * 3);
    choice->choices[0] = create_text(FST_CHOICE, font, V2F(1670, 400));
    sfText_scale(choice->choices[0], V2F(0.7, 0.7));
    choice->choices[1] = create_text(SEC_CHOICE, font, V2F(1670, 500));
    sfText_scale(choice->choices[1], V2F(0.7, 0.7));
    choice->choices[2] = NULL;
    choice->cursor = create_text(">", font, V2F(1640, 400));
    sfText_scale(choice->cursor, V2F(0.7, 0.7));
    choice->index = 0;
    return choice;
}

void update_choice(choice_t *choice, game_t *game)
{
    if (SKP(sfKeyUp))
        choice->index = 0;
    if (SKP(sfKeyDown))
        choice->index = 1;
    sfText_setPosition(choice->cursor, V2F(sfText_getPosition(choice->cursor).x,
    sfText_getPosition(choice->choices[choice->index]).y));
    if (SKP(sfKeyEnter) && game->dt > DT && game->ath->npc != NULL) {
        if (choice->index == 0)
            game->ath->npc->func(game);
        game->ath->dialog = NULL;
        game->ath->npc->state = WAIT;
        game->ath->npc->s_dialog = false;
        game->ath->npc = NULL;
        game->ath->is_choosing = false;
    }
}

void draw_choice(sfRenderWindow *win, choice_t *choice)
{
    if (choice == NULL)
        return;
    sfRenderWindow_drawSprite(win, choice->bg_sprite, NULL);
    sfRenderWindow_drawText(win, choice->cursor, NULL);
    sfRenderWindow_drawText(win, choice->choices[0], NULL);
    sfRenderWindow_drawText(win, choice->choices[1], NULL);
}

void free_choice(choice_t *choice)
{
    if (choice == NULL)
        return;
    sfText_destroy(choice->cursor);
    sfText_destroy(choice->choices[0]);
    sfText_destroy(choice->choices[1]);
    free(choice->choices);
    sfSprite_destroy(choice->bg_sprite);
    sfTexture_destroy(choice->bg_texture);
    free(choice);
}
