/*
** EPITECH PROJECT, 2022
** zombie.c
** File description:
** zombie
*/

#include "duckhunt.h"

static sfVector2f zspawn(int *node_side)
{
    sfVector2f spawn = {0};
    int side = my_random(1, 4);
    if (side == 1)
        spawn = (sfVector2f){my_random(0, X), -my_random(20, 40)};
    if (side == 3)
        spawn = (sfVector2f){my_random(X + 20, X + 40), my_random(0, Y)};
    if (side == 2)
        spawn = (sfVector2f){my_random(0, X), my_random(Y + 20, Y + 40)};
    if (side == 4)
        spawn = (sfVector2f){-my_random(20, 40), my_random(0, Y)};
    *node_side = side - 1;
    return spawn;
}

int add_zombie(zombie_t **zombie, win_t *win)
{
    zombie_t *node = malloc(sizeof(zombie_t));
    node->side = 0;
    node->pos = zspawn(&(node->side));
    node->sprite = win->enemies.zsprite;
    node->time = sfClock_create();
    node->frame = 0;
    node->nbframe = 4;
    node->cd = 0.2;
    node->speed = win->enemies.speed;
    node->size = 2;
    difficulty(node, win);
    node->next = *zombie;
    *zombie = node;
    return 0;
}

static void move_zombie(win_t *win, zombie_t *zombie)
{
    sfVector2f dir = (sfVector2f){X2 - zombie->pos.x,
        Y2 - zombie->pos.y};
    float coef = 1 / sqrt(my_power(dir.x,2) + my_power(dir.y,2));
    dir.x *= coef;
    dir.y *= coef;
    zombie->pos.x += dir.x * zombie->speed * win->deltaT;
    zombie->pos.y += dir.y * zombie->speed * win->deltaT;
}

void manage_zombie(win_t *win, obj_t *obj, zombie_t **zombie)
{
    zombie_t *temp = *zombie;

    if (TIMER(win->enemies.ztime) >= win->enemies.zcd) {
        spawn_new_zombie(win, obj, zombie);
        sfClock_restart(win->enemies.ztime);
    }
    for (; temp != NULL; temp = temp->next) {
        if (TIMER(temp->time) > temp->cd / (temp->speed / 100)) {
            temp->frame = cap_nb(temp->frame + 1, temp->nbframe);
            sfClock_restart(temp->time);
        }
        move_zombie(win, temp);
        sfSprite_setScale(temp->sprite, (sfVector2f){temp->size, temp->size});
        sfSprite_setTextureRect(temp->sprite,
            (sfIntRect){32 * temp->side, 32 * temp->frame, 32, 32});
        sfSprite_setPosition(temp->sprite,
            (sfVector2f){temp->pos.x, temp->pos.y});
        sfRenderWindow_drawSprite(win->window, temp->sprite, NULL);
    }
}

void zcheck(win_t *win, obj_t *obj, zombie_t **zombie)
{
    zombie_t *prev = NULL;
    zombie_t *temp = *zombie;
    int test = 0;
    int nb = 0;

    for (; temp != NULL; temp = temp->next, nb++) {
        if (check_target(temp, win) != 0 && obj->charge.count > 0)
            test = 1;
    }
    zombie_attack(zombie, obj, win);
    obj->crossh.rex = test;
}
