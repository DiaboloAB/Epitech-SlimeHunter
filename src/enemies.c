/*
** EPITECH PROJECT, 2022
** enemies
** File description:
** enemies
*/

#include "duckhunt.h"

int add_zombie_bush(zombie_t **zombie, win_t *win,
    sfVector2f spawn, int side)
{
    zombie_t *node = malloc(sizeof(zombie_t));
    node->side = side;
    node->pos = spawn;
    node->sprite = win->enemies.zsprite;
    node->time = sfClock_create();
    node->frame = 0;
    node->nbframe = 4;
    node->cd = 0.2;
    node->speed = 100;
    node->size = 2;
    node->next = *zombie;
    *zombie = node;
    return 0;
}

void spawn_new_zombie(win_t *win, obj_t *obj, zombie_t **zombie)
{
    spawner_t *temp = obj->spawner;

    for (; temp != NULL; temp = temp->next) {
        if (my_random(0, 100) < 20)
            add_zombie_bush(&(obj->zombie), win,
                temp->pos, temp->side);
    }
    if (my_random(0, 100) < win->enemies.zrate)
        for (int i = 0; i < win->enemies.nb; i++)
            add_zombie(&(obj->zombie), win);
}

void draw_lvl(win_t *win, obj_t *obj)
{
    if (win->enemies.kill == win->enemies.lvlup) {
        win->enemies.lvl += 1;
        win->enemies.kill = 0;
        win->enemies.lvlup += 1;
        sfSound_play(win->audio.level);
        if ((win->enemies.lvl == 2 || win->enemies.lvl % 5 == 0) &&
            win->enemies.lvl <= 25)
            add_bush(&(obj->spawner), win);
    }
    my_atoa(win->enemies.lvl, win->enemies.str_lvl);
    sfText_setString(win->enemies.lvl_text2, win->enemies.str_lvl + 1);
    sfRenderWindow_drawText(win->window, win->enemies.lvl_text, NULL);
    sfRenderWindow_drawText(win->window, win->enemies.lvl_text2, NULL);
    sfRectangleShape_setSize(win->enemies.rectangle,
        (sfVector2f){(win->enemies.kill * 1000 / win->enemies.lvlup), 5});
    sfRenderWindow_drawRectangleShape(win->window,
        win->enemies.rectangle, NULL);
}

void init_lvl_text(enemies_t *enemies)
{
    enemies->font = sfFont_createFromFile("sprites/big-shot.ttf");
    enemies->lvl_text = sfText_create();
    enemies->lvl_text2 = sfText_create();
    sfText_setFont(enemies->lvl_text, enemies->font);
    sfText_setFont(enemies->lvl_text2, enemies->font);
    enemies->str_lvl = malloc(sizeof(char) * 50);
    for (int i = 0; i < 50; i ++)
        enemies->str_lvl[i] == '\0';
    sfText_setCharacterSize(enemies->lvl_text, 25);
    sfText_setCharacterSize(enemies->lvl_text2, 25);
    sfText_setString(enemies->lvl_text, "level ");
    sfText_setPosition(enemies->lvl_text, (sfVector2f){450, 740});
    sfText_setPosition(enemies->lvl_text2, (sfVector2f){535, 740});
}

void init_enemies(win_t *win, my_textures_t textures)
{
    win->enemies.zrate = 70;
    win->enemies.zcd = 2;
    win->enemies.ztime = sfClock_create();
    win->enemies.nb = 3;
    win->enemies.lvl = 1;
    win->enemies.lvlup = 8;
    win->enemies.kill = 0;
    win->enemies.speed = 100;
    win->enemies.rectangle = sfRectangleShape_create();
    sfRectangleShape_setFillColor(win->enemies.rectangle, sfWhite);
    sfRectangleShape_setPosition(win->enemies.rectangle, (sfVector2f){0, 795});
    sfRectangleShape_setSize(win->enemies.rectangle, (sfVector2f){100, 0});
    init_lvl_text(&(win->enemies));
    win->enemies.zsprite = init_sprite(textures.zombie,
        (sfVector2f){2, 2});
    win->enemies.zsprite2 = init_sprite(textures.zombie2,
        (sfVector2f){2, 2});
    win->enemies.bushsp = init_sprite(textures.spawner,
        (sfVector2f){2, 2});
}
