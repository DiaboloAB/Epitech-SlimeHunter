/*
** EPITECH PROJECT, 2022
** freeall
** File description:
** freeall
*/

#include "duckhunt.h"

static void free_texture(my_textures_t *texture)
{
    sfTexture_destroy(texture->bush);
    sfTexture_destroy(texture->charges);
    sfTexture_destroy(texture->charges2);
    sfTexture_destroy(texture->crosshair);
    sfTexture_destroy(texture->grass);
    sfTexture_destroy(texture->life);
    sfTexture_destroy(texture->life2);
    sfTexture_destroy(texture->player);
    sfTexture_destroy(texture->spawner);
    sfTexture_destroy(texture->zombie);
}

static void destroy_text(obj_t *obj)
{
    sfText_destroy(obj->player.score_text);
    sfText_destroy(obj->player.combo_text);
    sfFont_destroy(obj->player.font);
}

static void destroy_clock(obj_t *obj, win_t *win)
{
    sfClock_destroy(obj->life.time);
    sfClock_destroy(obj->charge.time);
}

void free_zombie(zombie_t **zombie, spawner_t **spawner)
{
    zombie_t *temp = *zombie;
    zombie_t *prev = NULL;
    spawner_t *temp2 = *spawner;
    spawner_t *prev2 = NULL;
    for (; temp != NULL;) {
        sfClock_destroy(temp->time);
        prev = temp;
        temp = temp->next;
        free(prev);
    }
    for (; temp != NULL;) {
        prev2 = temp2;
        temp2 = temp2->next;
        free(prev2);
    }
}

void free_all(win_t *win, obj_t *obj, my_textures_t *texture)
{
    sfRectangleShape_destroy(win->enemies.rectangle);
    sfSprite_destroy(obj->charge.empty);
    sfSprite_destroy(obj->charge.full);
    sfSprite_destroy(obj->life.empty);
    sfSprite_destroy(obj->life.full);
    sfSprite_destroy(obj->crossh.sprite);
    sfSprite_destroy(obj->grass.sprite);
    sfSprite_destroy(obj->player.sprite);
    free_texture(texture);
    destroy_text(obj);
    free_zombie(&(obj->zombie), &(obj->spawner));
    sfRenderWindow_destroy(win->window);
}
