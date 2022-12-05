/*
** EPITECH PROJECT, 2022
** difficulty
** File description:
** difficulty
*/

#include "duckhunt.h"

void difficulty(zombie_t *zombie, win_t *win)
{
    if (win->enemies.lvl >= 10) {
        if (my_random(0, 100) < 20) {
            zombie->speed = win->enemies.speed / 2;
            zombie->size = 4;
        }
    }
    if (win->enemies.lvl >= 5) {
        if (my_random(0, 100) < 20) {
            zombie->speed = win->enemies.speed * 2;
            zombie->sprite = win->enemies.zsprite2;
        }
    }
}

int big_slime(zombie_t **chain, zombie_t *zombie, win_t *win)
{
    sfVector2f pos = zombie->pos;
    if (zombie->size > 2) {
        pos.x += 30;
        pos.y += 15;
        add_zombie_bush(chain, win, pos, 1);
        pos.x -= 60;
        add_zombie_bush(chain, win, pos, 1);
        pos.x += 30;
        pos.y -= 40;
        add_zombie_bush(chain, win, pos, 1);
    }
    return 1;
}

void lvl_up(win_t *win)
{
    win->enemies.speed += 1;
    if (win->enemies.lvl % 6 == 0)
        win->enemies.nb += 1;
    if (win->enemies.lvl % 4 == 0)
        win->enemies.zcd -= 0.01;
    if (win->enemies.lvl % 7 == 0)
        win->enemies.zrate += 1;
}
