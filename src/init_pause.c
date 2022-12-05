/*
** EPITECH PROJECT, 2022
** init_pause
** File description:
** init_pause
*/

#include "duckhunt.h"

static void init_pause_texture(pause_t *pause)
{
    pause->pause_texture = sfTexture_createFromFile(
        "sprites/buttons/pause.png", NULL);
    pause->menu_texture = sfTexture_createFromFile(
        "sprites/buttons/menu.png", NULL);
    pause->menu2_texture = sfTexture_createFromFile(
        "sprites/buttons/menu2.png", NULL);
    pause->quit_texture = sfTexture_createFromFile(
        "sprites/buttons/quit.png", NULL);
    pause->quit2_texture = sfTexture_createFromFile(
        "sprites/buttons/quit2.png", NULL);
    pause->resume_texture = sfTexture_createFromFile(
        "sprites/buttons/resume.png", NULL);
    pause->resume2_texture = sfTexture_createFromFile(
        "sprites/buttons/resume2.png", NULL);
}

pause_t init_pause(void)
{
    pause_t pause = {0};
    init_pause_texture(&pause);
    pause.pause = sfSprite_create();
    sfSprite_setTexture(pause.pause, pause.pause_texture, sfTrue);
    pause.menu = sfSprite_create();
    sfSprite_setTexture(pause.menu, pause.menu_texture, sfTrue);
    pause.menu2 = sfSprite_create();
    sfSprite_setTexture(pause.menu2, pause.menu2_texture, sfTrue);
    pause.quit = sfSprite_create();
    sfSprite_setTexture(pause.quit, pause.quit_texture, sfTrue);
    pause.quit2 = sfSprite_create();
    sfSprite_setTexture(pause.quit2, pause.quit2_texture, sfTrue);
    pause.resume = sfSprite_create();
    sfSprite_setTexture(pause.resume, pause.resume_texture, sfTrue);
    pause.resume2 = sfSprite_create();
    sfSprite_setTexture(pause.resume2, pause.resume2_texture, sfTrue);
    return pause;
}
