/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** main
*/
#include "../include/sfml_includes.h"

void draw_all(game_t *game)
{
    entity_t *hud = NULL;

    draw_level(game, game->map, 0);
    draw_level(game, game->map, 1);
    hud = sysdraw(game->map->tities, game);
    draw_level(game, game->map, 2);
    sfRenderWindow_setView(game->win, game->view->cinematic);
    hud->draw(game, hud->instance);
    sfRenderWindow_setView(game->win, game->view->player);
}

void reset_dialog(npc_t *npc, game_t *game)
{
    if (npc->state == TALK)
        game->ath->dialog = npc->dialog;
    if (npc->state == CHOICE)
        game->ath->is_choosing = true;
    if (npc->state == WAIT) {
        npc->dialog->cur_buf = format_str(npc->dialog->all_text, 0);
        npc->dialog->page = 0;
        sfText_setString(npc->dialog->buffer, npc->dialog->cur_buf);
        game->ath->is_choosing = false;
    }
}

void update_all(game_t *game, list_t *head)
{
    entity_t *tmp = NULL;

    LIST_FOREACH_DECL_BASIC(head->nodes, elem) {
        tmp = CAST(entity_t *, elem->data);
        tmp->process(game, tmp->instance);
    }
}

enum GAME_STATE get_game_state(sfRenderWindow *win, sfEvent evt,
enum GAME_STATE current)
{
    while (sfRenderWindow_pollEvent(win, &evt)) {
        if ((SKP(sfKeyEscape) || SKP(sfKeyP)) && current != GAME_MENU)
            return GAME_PAUSE;
        if (evt.type == sfEvtClosed)
            return GAME_EXIT;
    }
    return current;
}

int main(void)
{
    srand(time(NULL));
    sfEvent evt;
    game_t *game = init_game();
    if (game == NULL)
        return 84;
    play_sound(game->start);
    animate_start_splash(game->etib_logo, 0, 60, game);
    while (sfRenderWindow_isOpen(game->win))
        state_loop(game, evt);
    free_all(game);
    return 0;
}
