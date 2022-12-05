/*
** EPITECH PROJECT, 2022
** draw_obj
** File description:
** draw_obj
*/

#include "duckhunt.h"

void draw_grass(win_t *win, grass_t grass)
{
    sfRenderWindow_drawSprite(win->window, grass.sprite, NULL);
}

void draw_player(win_t *win, player_t player)
{
    float angle = atan2(win->mouse.y - 400, win->mouse.x -500) * (180.0 / M_PI);

    if (angle < 0)
        angle = 360 + angle;
    angle = angle / 60;
    sfSprite_setTextureRect(player.sprite,
        (sfIntRect){32 * (int)angle, 0, 32, 32});
    sfRenderWindow_drawSprite(win->window, player.sprite, NULL);
}

void draw_score(win_t *win, player_t *player)
{
    player->combo_size = min(player->combo_size - win->deltaT * 3, 40);
    sfText_setCharacterSize(player->combo_text, player->combo_size);
    my_atoa(player->combo, player->str_combo);
    my_atoa(player->score, player->str_score);
    sfText_setString(player->score_text, player->str_score + 1);
    sfText_setString(player->combo_text, player->str_combo);
    if (player->combo > 1)
        sfRenderWindow_drawText(win->window, player->combo_text, NULL);
    sfRenderWindow_drawText(win->window, player->score_text, NULL);
}

void draw_crossh(win_t *win, crossh_t crossh)
{
    sfSprite_setTextureRect(crossh.sprite,
        (sfIntRect){crossh.rex * 16, 0, 16, 16});
    sfSprite_setPosition(crossh.sprite,
        (sfVector2f){win->mouse.x - 16, win->mouse.y - 16});
    sfRenderWindow_drawSprite(win->window, crossh.sprite, NULL);
}

void draw_obj(win_t *win, obj_t *obj)
{
    zcheck(win, obj, &(obj->zombie));
    draw_grass(win, obj->grass);
    manage_zombie(win, obj, &(obj->zombie));
    draw_player(win, obj->player);
    draw_spawner(win, &(obj->spawner));
    draw_grass(win, obj->grass2);
    draw_life(win, &(obj->life));
    draw_score(win, &(obj->player));
    draw_charge(win, &(obj->charge));
    draw_crossh(win, obj->crossh);
    draw_lvl(win, obj);
    sfRenderWindow_display(win->window);
}
