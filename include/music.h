/*
** EPITECH PROJECT, 2023
** music.h
** File description:
** .h of music management
*/

#ifndef MUSIC_H_
    #define MUSIC_H_

    #define BOSS_MUSIC "assets/music_and_sound/battle_music.ogg"
    #define MENU_MUSIC "assets/music_and_sound/music_menu.ogg"
    #define FIRST_MUSIC "assets/music_and_sound/music_one.ogg"
    #define SECOND_MUSIC "assets/music_and_sound/music_two.ogg"
    #define THIRD_MUSIC "assets/music_and_sound/music_three.ogg"
    #define FOURTH_MUSIC "assets/music_and_sound/music_four.ogg"
    #define FIRTH_MUSIC "assets/music_and_sound/music_five.ogg"

    music_t *init_music(void);
    void update_music(music_t *music, int state);
    void free_music(music_t *music);

#endif /* !MUSIC_H_ */
