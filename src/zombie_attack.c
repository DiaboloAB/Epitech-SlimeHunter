/*
** EPITECH PROJECT, 2022
** zombie_attack
** File description:
** zombie_attack
*/

#include "duckhunt.h"

int attack(sfVector2f pos)
{
    if (pos.x > 425 && pos.x < 525 &&
        pos.y > 350 && pos.y < 450) {
        return 1;
    }
    return 0;
}

void zombie_attack(zombie_t **begin, obj_t *obj, win_t *win)
{
    zombie_t *node = *begin;
    zombie_t *previous = NULL;
    int count = 0;

    for (; node != NULL; node = node->next) {
        if (attack(node->pos) != 0 && count != 0) {
            sfSound_play(win->audio.hurt);
            obj->life.count -= 1;
            previous->next = node->next;
        }
        if (attack(node->pos) != 0 && count == 0) {
            sfSound_play(win->audio.hurt);
            obj->life.count -= 1;
            *begin = node->next;
        }
        if (attack(node->pos) == 0) {
            count++;
            previous = node;
        }
    }
}

int check_target(zombie_t *temp, win_t *win)
{
    return (temp->pos.x > win->mouse.x - temp->size * 32 &&
        temp->pos.x < win->mouse.x &&
        temp->pos.y > win->mouse.y - temp->size * 32 &&
        temp->pos.y < win->mouse.y);
}

static void score_manage(int hit, obj_t *obj, win_t *win)
{
    if (hit) {
        win->enemies.kill += 1;
        obj->charge.count += 2;
        obj->player.score += 20 + min(20 * (obj->player.combo - 1), 0);
        obj->player.combo += 1;
        obj->player.combo_size = 60;
    } else
        obj->player.combo = 0;
}

void attack_zombie(win_t *win, obj_t *obj, zombie_t **zombie)
{
    zombie_t *prev = NULL;
    zombie_t *temp = *zombie;
    int test = 0;
    int nb = 0;
    int hit = 0;

    for (; temp != NULL;) {
        if (check_target(temp, win) == 0) {
            nb++;
            prev = temp;
        } else
            hit = big_slime(&(obj->zombie), temp, win);
        if (check_target(temp, win) != 0 && nb != 0)
            prev->next = temp->next;
        if (check_target(temp, win) != 0 && nb == 0)
            *zombie = temp->next;
        temp = temp->next;
    }
    score_manage(hit, obj, win);
}
