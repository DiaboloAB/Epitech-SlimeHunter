/*
** EPITECH PROJECT, 2022
** init_obj
** File description:
** init_obj
*/

#include "duckhunt.h"

sfSprite *init_sprite(sfTexture *texture, sfVector2f size)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_scale(sprite, size);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static grass_t init_grass(my_textures_t texture)
{
    grass_t grass = {0};

    grass.sprite = init_sprite(texture.grass, (sfVector2f){2, 2});
    return grass;
}

static crossh_t init_crossh(my_textures_t texture)
{
    crossh_t crossh = {0};

    crossh.rex = 0;
    crossh.sprite = init_sprite(texture.crosshair, (sfVector2f){2, 2});
    return crossh;
}

static player_t init_player(my_textures_t texture)
{
    player_t player = {0};

    init_score(&player);
    player.sprite = init_sprite(texture.player, (sfVector2f){3, 3});
    sfSprite_setPosition(player.sprite, (sfVector2f){X2 - 32, Y2 - 32});
    return player;
}

obj_t init_objects(my_textures_t textures)
{
    obj_t obj = {0};
    obj.zombie = NULL;
    obj.spawner = NULL;
    obj.grass = init_grass(textures);
    obj.grass2 = init_grass2(textures);
    obj.player = init_player(textures);
    obj.crossh = init_crossh(textures);
    obj.life = init_life(textures);
    obj.charge = init_charge(textures);
    return obj;
}
