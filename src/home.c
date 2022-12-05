/*
** EPITECH PROJECT, 2022
** home
** File description:
** home
*/

#include "home.h"

static void analyse_home_events(win_t *win, obj_t *obj,
    home_t *home, int *pressed)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtMouseButtonPressed &&
            play_button(win->mouse))
            *pressed = 1;
        if (win->event.type == sfEvtMouseButtonPressed &&
            quit_button(win->mouse))
            pressed[1] = 1;
        if (win->event.type == sfEvtMouseButtonReleased && *pressed == 1) {
            *pressed = 0;
            new_game(win, obj);
            main_loop(win, obj);
        }
        if (win->event.type == sfEvtMouseButtonReleased && pressed[1] == 1)
            sfRenderWindow_close(win->window);
    }
}

static void draw_score_home(win_t *win, obj_t *obj, home_t *home)
{
    my_atoa(obj->player.score, home->str_score);
    my_atoa(win->high_score, home->str_high);
    if (obj->player.score == 0)
        sfText_setString(home->score_text, "null");
    else
        sfText_setString(home->score_text, home->str_score + 1);
    sfText_setString(home->high_text, home->str_high + 1);
    sfRenderWindow_drawText(win->window, home->high_text, NULL);
    sfRenderWindow_drawText(win->window, home->score_text, NULL);
}

static void draw_mouse(win_t *win, home_t *home)
{
    if (play_button(win->mouse) || quit_button(win->mouse)) {
        sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
        sfSprite_setPosition(home->cursor,
            (sfVector2f){win->mouse.x - 16, win->mouse.y - 16});
        sfRenderWindow_drawSprite(win->window, home->cursor, NULL);
    } else
        sfRenderWindow_setMouseCursorVisible(win->window, sfTrue);
}

static void draw_home(win_t *win, obj_t *obj, home_t *home)
{
    sfRenderWindow_drawSprite(win->window, obj->grass.sprite, NULL);
    sfRenderWindow_drawSprite(win->window, obj->grass2.sprite, NULL);
    sfRenderWindow_drawSprite(win->window, home->home, NULL);
    if (quit_button(win->mouse))
        sfRenderWindow_drawSprite(win->window, win->pause.quit, NULL);
    if (play_button(win->mouse))
        sfRenderWindow_drawSprite(win->window, home->play, NULL);
    draw_score_home(win, obj, home);
}

void home_loop(win_t *win, obj_t *obj, home_t *home)
{
    int pressed[3] = {0, 0, 0};

    sfSound_play(win->audio.menu);
    sfRenderWindow_setMouseCursorVisible(win->window, sfTrue);
    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_clear(win->window, sfBlack);
        win->mouse = sfMouse_getPositionRenderWindow(win->window);
        analyse_home_events(win, obj, home, pressed);
        draw_home(win, obj, home);
        draw_mouse(win, home);
        if (pressed[0] == 1)
            sfRenderWindow_drawSprite(win->window, home->play2, NULL);
        if (pressed[1] == 1)
            sfRenderWindow_drawSprite(win->window, win->pause.quit2, NULL);
        sfRenderWindow_display(win->window);
    }
    sfSound_stop(win->audio.menu);
}
