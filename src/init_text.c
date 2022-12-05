/*
** EPITECH PROJECT, 2022
** init_text
** File description:
** init_text
*/

#include "home.h"

void init_score_home(home_t *home)
{
    home->font = sfFont_createFromFile("sprites/big-shot.ttf");
    home->score_text = sfText_create();
    home->high_text = sfText_create();
    sfText_setFont(home->score_text, home->font);
    sfText_setFont(home->high_text, home->font);
    home->str_score = malloc(sizeof(char) * 50);
    home->str_high = malloc(sizeof(char) * 50);
    for (int i = 0; i < 50; i ++) {
        home->str_score[i] == '\0';
        home->str_high[i] == '\0';
    }
    sfText_setCharacterSize(home->high_text, 20);
    sfText_setCharacterSize(home->score_text, 20);
    sfText_setPosition(home->high_text, (sfVector2f){500, 532});
    sfText_setPosition(home->score_text, (sfVector2f){500, 567});
}

void init_score(player_t *player)
{
    player->font = sfFont_createFromFile("sprites/big-shot.ttf");
    player->combo_text = sfText_create();
    player->score_text = sfText_create();
    sfText_setFont(player->combo_text, player->font);
    sfText_setFont(player->score_text, player->font);
    sfText_setCharacterSize(player->score_text, 50);
    sfText_setPosition(player->score_text, (sfVector2f){40, 25});
    sfText_setPosition(player->combo_text, (sfVector2f){40, 75});
    player->str_combo = malloc(sizeof(char) * 50);
    player->str_score = malloc(sizeof(char) * 50);
    for (int i = 0; i < 50; i ++) {
        player->str_score[i] == '\0';
        player->str_combo[i] == '\0';
    }
    player->score = 0;
    player->combo = 0;
}

void my_atoa(int nb, char *str)
{
    int i = 1;
    int units = 0;
    int a = 1;
    for (; a <= nb / 10; units++, a *= 10);
    str[0] = 'x';
    while (units >= 0) {
        str[i++] = (nb / a + 48);
        nb = nb % a;
        a = a / 10;
        units = units - 1;
    }

    str[i] = '\0';
}
