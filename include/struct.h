/*
** EPITECH PROJECT, 2023
** B-MUL-200-RUN-2-1-myrpg-leo.sautron
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "sfml_includes.h"

    enum NPC_STATES {
        TALK,
        CHOICE,
        WAIT,
    };

    enum PLAYER_STATE {
        PLAYER_MOVE,
        PLAYER_IDLE,
        PLAYER_ATTACK,
        PLAYER_DEAD,
    };

    enum CHOCOBO_STATE {
        CHOCO_MOVE,
        CHOCO_IDLE,
        CHOCO_WHISTLE,
        CHOCO_MOUNT,
    };

    enum ENEMY_STATE {
        ENEMY_SEARCH,
        ENEMY_FOCUS,
        ENEMY_ATTACK,
        ENEMY_DIE,
    };

    enum BOSS_STATE {
        BOSS_IDLE,
        BOSS_ATTACK,
        BOSS_DIE,
    };

    enum GAME_STATE {
        GAME_PLAY,
        GAME_PAUSE,
        GAME_MENU,
        GAME_EXIT,
        GAME_SETTINGS,
        GAME_HELP,
        GAME_WIN,
        GAME_OVER
    };

    enum BT_STATE {
        BT_STATIC,
        BT_HOVER,
        BT_PRESSED
    };

    typedef struct soundtrack_s {
        sfSoundBuffer *buffer;
        sfSound *sound;
    } soundtrack_t;

    typedef struct chocobo_s {
        sfSprite *sprite;
        sfTexture **textures;
        int current_texture;
        int nb_texture;
        int texture_ind;
        enum CHOCOBO_STATE state;
        int speed;
        float time_state;
        sfVector2f end_pos;
        sfVector2f pos_max;
        sfVector2f pos_min;
        soundtrack_t *whistle;
    } chocobo_t;

    typedef struct player_data_s {
        sfVector2f pos;
        char life;
        int coins;
        int level;
        int weapon;
        int xp;
        bool chocobo;
    } player_data_t;

    typedef struct box_s {
        sfIntRect *rect;
        int value;
    } box_t;

    typedef struct weapon_s {
        box_t *hitbox;
        sfVector2f pos;
    } weapon_t;

    typedef struct boss_s {
        sfSprite *sprite;
        sfTexture **textures;
        int current_texture;
        int nb_texture;
        int texture_ind;
        enum BOSS_STATE state;
        char life;
        sfVector2f pos;
        box_t *hitbox;
        box_t *hurtbox;
        float attack_time;
        sfCircleShape *zone;
        sfSprite *minion;
        sfVector2f player_pos;
        float time_hit;
        bool is_launched;
        bool hit;
    } boss_t;

    typedef struct player_s  {
        int speed;
        char life;
        char attack;
        char lvl;
        short xp;
        weapon_t **weapons;
        sfSprite *sprite;
        sfTexture **textures;
        sfIntRect *rect;
        box_t *hurtbox;
        sfVector2f velocity;
        sfVector2f pos;
        enum PLAYER_STATE state;
        int current_texture;
        int current_weapon;
        int max_weapon;
        int nb_texture;
        int texture_ind;
        bool hit;
        float time_hit;
        int coins;
        bool choco;
    } player_t;

    typedef struct enemy_s {
        bool display;
        int speed;
        char life;
        char attack;
        sfSprite *sprite;
        sfTexture **textures;
        int current_texture;
        int nb_texture;
        int texture_ind;
        box_t *hitbox;
        box_t *hurtbox;
        enum ENEMY_STATE state;
        int type;
        sfCircleShape *circle;
        bool is_draw;
        sfVector2f end_pos;
        sfVector2f pos_min;
        sfVector2f pos_max;
        bool hit;
        float time_hit;
    } enemy_t;

    typedef struct quadtree_s {
        list_t *qt_nodes;
        sfFloatRect zone;
        int elm;
        int depth;
        struct quadtree_s *one;
        struct quadtree_s *two;
        struct quadtree_s *three;
        struct quadtree_s *four;
    } quadtree_t;

    typedef struct map_layer_s {
        sfVertexArray *layer;
        char *name;
    } map_layer_t;

    typedef struct teleports_s {
        char *path_map;
        char *path_enemy;
        sfIntRect rec;
        sfVector2f pos_player;
    } teleports_t;

    typedef struct map_s {
        sfVector2f size;
        map_layer_t *layers;
        int n_layer;
        list_t *tities;
        int *collisions;
        sfRenderStates *states;
        teleports_t *teleports;
        int n_teleport;
        char *json_map;
        char *json_entity;
    } map_t;

    typedef struct view_s {
        sfView *player;
        sfView *minimap;
        sfView *cinematic;
    } view_t;

    typedef struct choice_s {
        sfSprite *bg_sprite;
        sfTexture *bg_texture;
        sfText **choices;
        sfText *cursor;
        int index;
    } choice_t;

    typedef struct dialog_s {
        char *all_text;
        char *name;
        char *cur_buf;
        sfText *buffer;
        sfText *speaker;
        sfFont *font;
        sfSprite *sprite;
        sfTexture *texture;
        int page;
    } dialog_t;

    typedef struct dropable_s {
        sfSprite *sprite;
        sfTexture *texture;
        char *infos;
        char *name;
        bool display;
    } dropable_t;

    typedef struct inventory_s {
        bool display;
        dropable_t **content;
        sfSprite *bg_sprite;
        sfTexture *bg_texture;
        sfSprite *containers_sprite;
        sfTexture *containers_texture;
        sfText *text_coins;
        sfSprite *info_sprite;
        sfTexture *info_texture;
        sfText *info_text;
        sfText *info_name;
        int coins;
        bool display_info;
    } inventory_t;

    typedef struct music_s {
        sfMusic **all;
        sfTime time;
        sfTime duration;
        sfMusic *menu;
        sfMusic *boss;
        sfMusic *current;
    } music_t;

    typedef struct splash_t {
        int current_texture;
        sfSprite *sprite;
        sfTexture *texture;
        int witdh;
        int height;
        int nb_texture;
    } splash_t;


    typedef struct game_s {
        sfRenderWindow *win;
        map_t *map;
        music_t *music;
        view_t *view;
        sfClock *clock;
        float dt;
        quadtree_t *qt;
        sfTexture *world;
        player_t *player;
        chocobo_t *chocobo;
        splash_t *game_over;
        splash_t *etib_logo;
        soundtrack_t *start;
        struct pmenu_s *pause_menu;
        struct pmenu_s *main_menu;
        struct pmenu_s *settings;
        struct pmenu_s *help;
        struct ath_s *ath;
        bool over;
        enum GAME_STATE state;
        enum GAME_STATE last_state;
        float quotient;
        bool fullscreen;
    } game_t;

    typedef struct npc_s {
        enum NPC_STATES state;
        sfSprite *sprite;
        sfTexture *textures;
        int texture_ind;
        box_t *zone;
        sfVector2f pos;
        dialog_t *dialog;
        bool s_dialog;
        void (*func) (game_t *);
    } npc_t;

    typedef struct ath_s {
        sfSprite **health;
        sfTexture *heart_texture;
        inventory_t *inventory;
        sfRectangleShape *xp_bar;
        sfText *text;
        int cur_lvl;
        char *level;
        dialog_t *dialog;
        choice_t *choice;
        sfSprite *weapon_sprite;
        sfSprite *block_sprite;
        sfTexture *block_texture;
        sfTexture **weapon_textures;
        bool is_choosing;
        npc_t *npc;
    } ath_t;


    typedef struct pbutton_s {
        sfSprite *sprite;
        sfText *text;
        enum BT_STATE state;
        void (*exec) (game_t *);
    } pbutton_t;

    typedef struct pmenu_s {
        pbutton_t **button;
        sfTexture **texture;
        sfSprite *sprite;
        sfTexture *bg_texture;
        sfText *title;
        int ind;
    } pmenu_t;

    typedef struct entity_s {
        void (*ready)(struct entity_s *);
        void (*process)(game_t *, void *);
        void (*draw)(game_t *, void *);
        void (*destroy)(void *);
        void *instance;
        int type;
        bool is_hud;
    } entity_t;

#endif /* !STRUCT_H_ */
