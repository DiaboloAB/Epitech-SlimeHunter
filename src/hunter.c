/*
** EPITECH PROJECT, 2022
** hunter
** File description:
** hunter
*/

#include "duckhunt.h"
#include "home.h"

win_t init_my_window(void)
{
    win_t win = {0};
    sfVideoMode mode = {X, Y, 32};
    sfEvent event = {0};
    sfRenderWindow *window;
    window = sfRenderWindow_create((sfVideoMode){X, Y, 32},
        "My Hunter", sfClose, NULL);

    win.window = window;
    win.event = event;
    win.time = sfClock_create();
    win.deltaT = 0;
    win.audio = init_audio();
    win.pause = init_pause();
    win.high_score = get_score();
    sfRenderWindow_setFramerateLimit(window, 60);
    return win;
}

my_textures_t init_texture(void)
{
    my_textures_t textures = {0};
    textures.bush = sfTexture_createFromFile("sprites/bush.png", NULL);
    textures.charges = sfTexture_createFromFile("sprites/charges.png", NULL);
    textures.charges2 = sfTexture_createFromFile("sprites/charges2.png", NULL);
    textures.crosshair = sfTexture_createFromFile("sprites/cursor.png", NULL);
    textures.grass = sfTexture_createFromFile("sprites/grass.png", NULL);
    textures.life = sfTexture_createFromFile("sprites/life.png", NULL);
    textures.life2 = sfTexture_createFromFile("sprites/life2.png", NULL);
    textures.player = sfTexture_createFromFile("sprites/player.png", NULL);
    textures.spawner = sfTexture_createFromFile("sprites/spawner.png", NULL);
    textures.zombie = sfTexture_createFromFile("sprites/zombie.png", NULL);
    textures.zombie2 = sfTexture_createFromFile("sprites/slime_red.png", NULL);
    return textures;
}

home_t init_home(void)
{
    home_t home = {0};
    home.home_texture = sfTexture_createFromFile("sprites/home.png", NULL);
    home.home = sfSprite_create();
    sfSprite_setTexture(home.home, home.home_texture, sfTrue);
    home.cursor_texture = sfTexture_createFromFile("sprites/cursor.png", NULL);
    home.cursor = sfSprite_create();
    sfSprite_setTexture(home.cursor, home.cursor_texture, sfTrue);
    sfSprite_setTextureRect(home.cursor, (sfIntRect){0, 0, 16, 16});
    sfSprite_setScale(home.cursor, (sfVector2f){2, 2});
    home.play_texture = sfTexture_createFromFile("sprites/play.png", NULL);
    home.play = sfSprite_create();
    sfSprite_setTexture(home.play, home.play_texture, sfTrue);
    home.play2_texture = sfTexture_createFromFile("sprites/play2.png", NULL);
    home.play2 = sfSprite_create();
    sfSprite_setTexture(home.play2, home.play2_texture, sfTrue);
    init_score_home(&home);
    return home;
}

int hunter(void)
{
    win_t win = init_my_window();
    home_t home = init_home();
    my_textures_t texture = init_texture();
    init_enemies(&win, texture);
    obj_t obj = init_objects(texture);
    home_loop(&win, &obj, &home);
    save_score(win.high_score);
    free_all(&win, &obj, &texture);
}
