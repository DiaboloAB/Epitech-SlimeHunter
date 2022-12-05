/*
** EPITECH PROJECT, 2022
** init_obj
** File description:
** init_obj
*/

#include "duckhunt.h"

life_t init_life(my_textures_t textures)
{
    life_t life = {0};
    life.count = 3;
    life.x = X - 225;
    life.y = Y - 100;
    life.frame = 0;
    life.nbFrame = 10;
    life.time = sfClock_create();
    life.cd = 0.15;
    life.full = init_sprite(textures.life, (sfVector2f){4, 4});
    life.empty = init_sprite(textures.life2, (sfVector2f){4, 4});
    return life;
}

charge_t init_charge(my_textures_t textures)
{
    charge_t charge = {0};
    charge.count = 3;
    charge.x = 25;
    charge.y = Y - 100;
    charge.frame = 0;
    charge.nbFrame = 10;
    charge.time = sfClock_create();
    charge.cd = 0.15;
    charge.full = init_sprite(textures.charges, (sfVector2f){4, 4});
    charge.empty = init_sprite(textures.charges2, (sfVector2f){4, 4});
    return charge;
}

grass_t init_grass2(my_textures_t textures)
{
    grass_t grass2 = {0};

    grass2.sprite = init_sprite(textures.bush, (sfVector2f){2, 2});
    return grass2;
}

static sfVector2f bushspawn(int *node_side)
{
    sfVector2f spawn = {0};
    int side = my_random(1, 4);
    if (side == 1)
        spawn = (sfVector2f){my_random(50, -50), my_random(100, 200)};
    if (side == 3)
        spawn = (sfVector2f){my_random(X - 300, X - 150),
            my_random(50, Y - 50)};
    if (side == 2)
        spawn = (sfVector2f){my_random(50, X - 50),
            my_random(Y - 200, Y - 100)};
    if (side == 4)
        spawn = (sfVector2f){my_random(150, 300), my_random(50, Y - 50)};
    *node_side = side - 1;
    return spawn;
}

void add_bush(spawner_t **spawner, win_t *win)
{
    spawner_t *node = malloc(sizeof(zombie_t));
    node->pos = bushspawn(&(node->side));
    node->sprite = win->enemies.bushsp;
    node->next = *spawner;
    *spawner = node;
}
