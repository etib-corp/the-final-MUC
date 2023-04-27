/*
** EPITECH PROJECT, 2023
** pause_menu.h
** File description:
** .h of pause menu
*/

#ifndef PAUSE_MENU_H_
    #define PAUSE_MENU_H_

    #include "sfml_includes.h"

    #define PBUTTON_IDLE "assets/UI/pbutton_idle.png"
    #define PBUTTON_HOVER "assets/UI/pbutton_hover.png"
    #define PBUTTON_CLICKED "assets/UI/pbutton_clicked.png"
    #define BG_TRANSPARENT "assets/UI/background_transparent.png"
    #define BG_MENU "assets/UI/main_menu.png"
    #define BG_SETTINGS "assets/UI/settings.png"

    #define NB_ANIM_MENU 6

    #define NB_ANIM_OVER 0
    #define BG_GAME_OVER "path"
    #define WITDH_BG_GAME_OVER 42
    #define HEIGHT_BG_GAME_OVER 42

    #define DIED "assets/you_died.png"
    #define HELP "assets/UI/help.png"

    void update_pmenu(pmenu_t *menu, game_t *game);
    void draw_pmenu(pmenu_t *menu, sfRenderWindow *win);

    pbutton_t *create_pbutton(char *text, void (*func)(game_t *),
        sfVector2f pos, sfFont const *font);
    void draw_pmenu(pmenu_t *menu, sfRenderWindow *win);
    void update_pmenu(pmenu_t *menu, game_t *game);
    sfTexture **set_pmenu_texture(void);
    void animate_menu(pmenu_t *menu, float dt, int quotient);

    pmenu_t *init_pause_menu(sfFont const *font);
    pmenu_t *init_settings(sfFont const *font);
    pmenu_t *init_main_menu(sfFont const *font);
    pmenu_t *init_help_menu(sfFont const *font);

    void play_func(game_t *game);
    void exit_func(game_t *game);
    void settings_func(game_t *game);
    void help_func(game_t *game);

    void resume_func(game_t *game);
    void save_func(game_t *game);
    void menu_func(game_t *game);
    void start_func(game_t *game);

    void return_func(game_t *game);

    void animate_start_splash(splash_t *logo, int frame, int frame_max,
    game_t *game);
    bool animate_splash(float dt, splash_t *go);
    splash_t *init_splash(char *path, int witdh, int height, int nb_anin);

    void sound_plus(game_t *game);
    void sound_minus(game_t *game);
    void sound_off(game_t *game);
    void change_res(game_t *game);
    void change_mode(game_t *game);


#endif /* !PAUSE_MENU_H_ */
