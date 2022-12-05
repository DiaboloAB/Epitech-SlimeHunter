/*
** EPITECH PROJECT, 2022
** draw_obj
** File description:
** draw_obj
*/

#include "duckhunt.h"

void draw_life(win_t *win, life_t *life)
{
    if (TIMER(life->time) > life->cd) {
        life->frame += 1;
        sfClock_restart(life->time);
    }
    if (life->frame == life->nbFrame)
        life->frame = 0;
    sfSprite_setTextureRect(life->empty,
        (sfIntRect){0, life->frame * 16, 16 * 3, 16});
    sfSprite_setTextureRect(life->full,
        (sfIntRect){0, life->frame * 16, 16 * life->count, 16});
    sfSprite_setPosition(life->empty, (sfVector2f){life->x, life->y});
    sfRenderWindow_drawSprite(win->window, life->empty, NULL);
    sfSprite_setPosition(life->full, (sfVector2f){life->x - 2, life->y - 2});
    sfRenderWindow_drawSprite(win->window, life->full, NULL);
}

void draw_charge(win_t *win, charge_t *charge)
{
    if (TIMER(charge->time) > charge->cd) {
        charge->frame += 1;
        sfClock_restart(charge->time);
    }
    if (charge->frame == charge->nbFrame)
        charge->frame = 0;
    sfSprite_setTextureRect(charge->empty,
        (sfIntRect){0, charge->frame * 16, 16 * 3, 16});
    sfSprite_setTextureRect(charge->full,
        (sfIntRect){0, charge->frame * 16, 16 * charge->count, 16});
    sfSprite_setPosition(charge->empty, (sfVector2f){charge->x, charge->y});
    sfRenderWindow_drawSprite(win->window, charge->empty, NULL);
    sfSprite_setPosition(charge->full,
        (sfVector2f){charge->x - 2, charge->y - 2});
    sfRenderWindow_drawSprite(win->window, charge->full, NULL);
}

void draw_spawner(win_t *win, spawner_t **spawner)
{
    spawner_t *temp = *spawner;

    int i = 0;
    for (; temp != NULL; temp = temp->next) {
        sfSprite_setPosition(temp->sprite,
            (sfVector2f){temp->pos.x - 24, temp->pos.y - 24});
        sfRenderWindow_drawSprite(win->window, temp->sprite, NULL);
    }
}
