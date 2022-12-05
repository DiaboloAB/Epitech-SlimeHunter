/*
** EPITECH PROJECT, 2022
** new game
** File description:
** new game
*/

#include "duckhunt.h"

static void delete_zombie(zombie_t **zombie)
{
    zombie_t *prev = NULL;
    zombie_t *temp = *zombie;

    for (; temp != NULL;) {
        prev = temp;
        temp = temp->next;
        free(prev);
    }
}

static void delete_spawner(spawner_t **spawner)
{
    spawner_t *prev = NULL;
    spawner_t *temp = *spawner;

    for (; temp != NULL;) {
        prev = temp;
        temp = temp->next;
        free(prev);
    }
}

void reset_enemies(win_t *win)
{
    win->enemies.zrate = 70;
    win->enemies.zcd = 2;
    win->enemies.nb = 3;
    win->enemies.lvl = 1;
    win->enemies.lvlup = 8;
    win->enemies.kill = 0;
    win->enemies.speed = 100;
}

void new_game(win_t *win, obj_t *obj)
{
    win->deltaT = 0;
    sfClock_restart(win->time);
    delete_zombie(&(obj->zombie));
    delete_spawner(&(obj->spawner));
    obj->zombie = NULL;
    obj->spawner = NULL;
    obj->life.count = 3;
    obj->charge.count = 3;
    obj->player.score = 0;
    obj->player.combo = 0;
    reset_enemies(win);
}
