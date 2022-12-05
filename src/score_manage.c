/*
** EPITECH PROJECT, 2022
** score
** File description:
** score
*/

#include "duckhunt.h"
#include <fcntl.h>

static int get_nbr(char *str)
{
    int nb = 0;
    int units = 0;
    for (units; str[units] > 47 && str[units] < 58; units++);
    for (int i = 0; str[i] > 47 && str[i] < 58; i++, units--)
        nb += (str[i] - 48) * my_power(10, units - 1);
    return nb;
}

int get_score(void)
{
    int nb = 0;
    char *buff = NULL;
    size_t size = 0;
    FILE *fp = fopen(".score.txt", "r");

    if (fp == NULL)
        return 84;
    if (getline(&buff, &size, fp) == -1)
        return 84;
    nb = get_nbr(buff);
    fclose(fp);
    return nb;
}

void save_score(int nb)
{
    int i = 0;
    int units = 0;
    int a = 1;
    char str[1] = " ";
    int units_save = 0;
    if (nb == 0)
        return;
    int fd = open(".score.txt", O_WRONLY);
    for (; a <= nb / 10; units++, a *= 10);
    while (units >= 0) {
        str[0] = (nb / a + 48);
        write(fd, str, 1);
        nb = nb % a;
        a = a / 10;
        units = units - 1;
    }
    write(fd, "\n", 1);
    close(fd);
}
