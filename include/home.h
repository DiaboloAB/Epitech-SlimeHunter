/*
** EPITECH PROJECT, 2022
** home
** File description:
** home
*/

#ifndef _HOM_H__
    #define _HOM_H__

    #include "duckhunt.h"

    typedef struct home_s {
        sfTexture *home_texture;
        sfSprite *home;
        sfTexture *play_texture;
        sfSprite *play;
        sfTexture *play2_texture;
        sfSprite *play2;
        sfTexture *cursor_texture;
        sfSprite *cursor;
        sfFont *font;
        sfText *score_text;
        sfText *high_text;
        char *str_score;
        char *str_high;
    } home_t;

    void home_loop(win_t *win, obj_t *obj, home_t *home);
    int play_button(sfVector2i mouse);
    int quit_button(sfVector2i mouse);
    int menu_button(sfVector2i mouse);
    void init_score_home(home_t *home);

#endif
