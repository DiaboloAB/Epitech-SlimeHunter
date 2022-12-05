/*
** EPITECH PROJECT, 2022
** main_loop
** File description:
** main_loop
*/

#include "duckhunt.h"
#include "my_printf.h"

static void analyse_events(win_t *win, obj_t *obj)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (win->event.type == sfEvtMouseButtonPressed &&
            obj->charge.count != 0) {
            obj->charge.count -= 1;
            sfSound_play(win->audio.shot);
            attack_zombie(win, obj, &(obj->zombie));
        }
        if (win->event.key.code == sfKeyEscape ||
            win->event.type == sfEvtLostFocus)
            pause_loop(win, obj);
        if (win->event.type == sfEvtMouseButtonPressed &&
            obj->charge.count == 0) {
            sfSound_play(win->audio.empty);
        }
    }
    if (obj->charge.count > 3)
        obj->charge.count = 3;
}

int main_loop(win_t *win, obj_t *obj)
{
    sfSound_stop(win->audio.menu);
    sfSound_play(win->audio.game);
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    while (sfRenderWindow_isOpen(win->window) && obj->life.count > 0) {
        sfRenderWindow_clear(win->window, sfBlack);
        win->mouse = sfMouse_getPositionRenderWindow(win->window);
        get_deltat(win);
        analyse_events(win, obj);
        draw_obj(win, obj);
        sfRenderWindow_display(win->window);
    }
    if (win->high_score < obj->player.score && obj->life.count == 0)
        win->high_score = obj->player.score;
    sfSound_stop(win->audio.game);
    sfSound_play(win->audio.death);
    return 0;
}
