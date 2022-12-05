/*
** EPITECH PROJECT, 2022
** tools
** File description:
** tools
*/

#include "duckhunt.h"
#include "my_printf.h"

void get_deltat(win_t *win)
{
    win->deltaT = TIMER(win->time);
    sfClock_restart(win->time);
}

int my_power(int a, int b)
{
    if (b == 0)
        return 1;
    int x = a;
    for (int i = 0; i < b - 1; i++)
        x *= a;
    return x;
}

int my_random(int min, int max)
{
    return ((rand() + min) % (max - min + 1) + min);
}

int cap_nb(int nb, int max)
{
    if (nb >= max)
        return 0;
    return nb;
}

int min(int nb, int min)
{
    if (nb < min)
        return min;
    return nb;
}
