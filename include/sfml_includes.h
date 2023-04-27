/*
** EPITECH PROJECT, 2023
** sfml_includes.h
** File description:
** all sfml includes
*/

#ifndef SFML_INCLUDES_H_
    #define SFML_INCLUDES_H_

    #include <SFML/Graphics.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Types.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <math.h>
    #include "../lib/my.h"

    #include "struct.h"

    #include "entities.h"

    #include "enemy.h"

    #include "parsing.h"

    #include "dialogs.h"

    #include "map.h"

    #include "quadtree.h"

    #include "player.h"

    #include "boss.h"

    #include "game_engine.h"

    #include "chocobo.h"

    #include "ath.h"

    #include "free.h"

    #include "npc.h"

    #include "dropable.h"

    #include "inventory.h"

    #include "music.h"

    #include "pause_menu.h"

    #include <time.h>

    #define V2F(X, Y) (sfVector2f){\
    X, Y\
    }
    #define V2I(X, Y) (sfVector2i){\
    X, Y\
    }
    #define V2U(X, Y) (sfVector2u){\
    X, Y\
    }
    #define FR(left, top, width, height) (sfFloatRect){\
    left, top, width, height\
    }
    #define IR(left, top, width, height) (sfIntRect){\
    left, top, width, height\
    }

    #define TITLE "The Final MUC"

    game_t *init_game(void);
    void manage_dt(game_t *game);
    bool is_valid(FILE *file);
    sfRenderWindow *set_window(float quotient, bool fullscreen);
    void game_loop(game_t *game);
    enum GAME_STATE get_game_state(sfRenderWindow *win, sfEvent evt, enum
    GAME_STATE current);
    void state_loop(game_t *game, sfEvent evt);
    void draw_all(game_t *game);
    void update_all(game_t *game, list_t *head);
    view_t *init_views(void);
    void save_game(player_t *player, map_t *map);
    void destroy_save(void);
    void load_save(game_t *game);
    soundtrack_t *init_soundtrack(char *path);
    void play_sound(soundtrack_t *st);
    void destroy_soundtrack(soundtrack_t *st);
    void reset_dialog(npc_t *npc, game_t *game);
    bool check_save(void);
    void pause_loop(game_t *game);
    void menu_loop(game_t *game);
    void settings_loop(game_t *game);
    void game_over_loop(game_t *game);
    void help_loop(game_t *game);
    int init_from_file(FILE *file, game_t *game);
    sfVector2f init_player_pos(char *buf);

#endif /* !SFML_INCLUDES_H_ */
