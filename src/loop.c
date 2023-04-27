/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** loop
*/
#include "sfml_includes.h"

void game_loop(game_t *game)
{
    if (game->over) {
        game->state = GAME_OVER;
        return;
    }
    if (game->clock == NULL)
        game->clock = sfClock_create();
    if (game->clock != NULL && sfClock_getElapsedTime
    (game->clock).microseconds > 200000)
        sfClock_restart(game->clock);
    game->qt = create_quadtree(FR(0, 0, 1920, 1080), 0);
    insert_quadtree(game->qt, game->map->tities);
    collide(game->qt, game->chocobo->state);
    update_music(game->music, 1);
    manage_dt(game);
    sfRenderWindow_clear(game->win, sfBlack);
    draw_all(game);
    update_all(game, game->map->tities);
    sfRenderWindow_display(game->win);
    free_quadtree(&game->qt);
}

void win_loop(game_t *game)
{
    splash_t *win = init_splash("assets/victory.png", 995, 246, 1);
    sfSprite_setScale(win->sprite, V2F(1.93, 1.93));
    float time = 5.0;
    while (time >= 0.0) {
        animate_splash(game->dt, win);
        sfRenderWindow_drawSprite(game->win, win->sprite, NULL);
        sfRenderWindow_display(game->win);
        manage_dt(game);
        if (game->dt >= DT)
            time -= game->dt;
    }
    game->state = GAME_MENU;
}

void game_state(game_t *game)
{
    switch (game->state) {
    case GAME_SETTINGS:
        settings_loop(game);
        break;
    case GAME_WIN:
        win_loop(game);
        break;
    case GAME_OVER:
        game_over_loop(game);
        break;
    case GAME_EXIT:
        return sfRenderWindow_close(game->win);
    default:
        return;
    }

}

void state_loop(game_t *game, sfEvent evt)
{
    game->state = get_game_state(game->win, evt, game->state);
    switch (game->state) {
        case GAME_MENU:
            menu_loop(game);
            break;
        case GAME_PLAY:
            game_loop(game);
            break;
        case GAME_PAUSE:
            pause_loop(game);
            break;
        case GAME_HELP:
            help_loop(game);
            break;
        default:
            return game_state(game);
    }
}
