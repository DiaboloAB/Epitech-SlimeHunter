/*
** EPITECH PROJECT, 2022
** pause
** File description:
** pause
*/

#include "home.h"

static void check_button(win_t *win , obj_t *obj, int *pause, int *button)
{
    if (button[0] == 1)
        sfRenderWindow_close(win->window);
    if (button[1] == 1) {
        *pause = 0;
        button[1] == 0;
    }
    if (button[2] == 1){
        obj->life.count = 0;
        button[3] == 0;
        *pause = 0;
    }
}

static void analyse_pause_events(win_t *win, obj_t *obj, int *pause,
    int *button)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtMouseButtonPressed &&
            quit_button(win->mouse))
            button[0] = 1;
        if (win->event.type == sfEvtMouseButtonPressed &&
            play_button(win->mouse))
            button[1] = 1;
        if (win->event.type == sfEvtMouseButtonPressed &&
            menu_button(win->mouse))
            button[2] = 1;
        if (win->event.type == sfEvtMouseButtonReleased)
            check_button(win, obj, pause, button);
    }
}

static void draw_mouse(win_t *win, obj_t *obj)
{
    if (play_button(win->mouse) || quit_button(win->mouse) ||
        menu_button(win->mouse)) {
        sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
        sfSprite_setPosition(obj->crossh.sprite,
            (sfVector2f){win->mouse.x - 16, win->mouse.y - 16});
        sfRenderWindow_drawSprite(win->window, obj->crossh.sprite, NULL);
    } else
        sfRenderWindow_setMouseCursorVisible(win->window, sfTrue);
}

static void draw_pause(win_t *win, obj_t *obj)
{
    sfRenderWindow_drawSprite(win->window, obj->grass.sprite, NULL);
    sfRenderWindow_drawSprite(win->window, obj->grass2.sprite, NULL);
    sfRenderWindow_drawSprite(win->window, win->pause.pause, NULL);
    if (quit_button(win->mouse))
        sfRenderWindow_drawSprite(win->window, win->pause.quit, NULL);
    if (play_button(win->mouse))
        sfRenderWindow_drawSprite(win->window, win->pause.resume, NULL);
    if (menu_button(win->mouse))
        sfRenderWindow_drawSprite(win->window, win->pause.menu, NULL);
}

void pause_loop(win_t *win, obj_t *obj)
{
    int pause = 1;
    int button[3] = {0, 0, 0};
    sfRenderWindow_setMouseCursorVisible(win->window, sfTrue);
    while (sfRenderWindow_isOpen(win->window) && pause) {
        sfRenderWindow_clear(win->window, sfBlack);
        win->mouse = sfMouse_getPositionRenderWindow(win->window);
        analyse_pause_events(win, obj, &pause, button);
        draw_pause(win, obj);
        draw_mouse(win, obj);
        if (button[0] == 1)
            sfRenderWindow_drawSprite(win->window, win->pause.quit2, NULL);
        if (button[1] == 1)
            sfRenderWindow_drawSprite(win->window, win->pause.resume2, NULL);
        if (button[2] == 1)
            sfRenderWindow_drawSprite(win->window, win->pause.menu2, NULL);
        sfRenderWindow_display(win->window);
    }
    sfClock_restart(win->time);
    win->deltaT = 0;
}
