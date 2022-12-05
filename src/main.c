/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "duckhunt.h"
#include "my_printf.h"

static int flag_h(char *str)
{
    FILE *fp = fopen("README.txt","r");
    char *buff = NULL;
    size_t size = 0;
    char *flag = "-h";

    if (fp == NULL)
        return 84;
    for (int i = 0; str[i] != 0 || flag[i] != 0; i++)
        if (str[i] != flag[i])
            return 84;
    while (getline(&buff, &size, fp) != -1)
        my_printf(buff);
    fclose(fp);
    free(buff);
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 2)
        return 84;
    if (ac == 2)
        return flag_h(av[1]);
    srand(time(NULL));
    hunter();
    return 0;
}
