/*
** EPITECH PROJECT, 2022
** buttons
** File description:
** buttons
*/

#include "duckhunt.h"

int quit_button(sfVector2i mouse)
{
    if (mouse.x > 800 && mouse.x < 960 &&
        mouse.y > 20 && mouse.y < 75)
        return 1;
    return 0;
}

int play_button(sfVector2i mouse)
{
    if (mouse.x > 390 && mouse.x < 645 &&
        mouse.y > 430 && mouse.y < 525)
        return 1;
    return 0;
}

int menu_button(sfVector2i mouse)
{
    if (mouse.x > 400 && mouse.x < 635 &&
        mouse.y > 350 && mouse.y < 400)
        return 1;
    return 0;
}
