/*
** EPITECH PROJECT, 2022
** duckhunt
** File description:
** duckhunt
*/

#ifndef _DUCKHUNT_H__
    #define _DUCKHUNT_H__
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <time.h>
    #include <unistd.h>
    #include <stdio.h>

    #define X 1000
    #define Y 800
    #define X2 500
    #define Y2 400
    #define TIMER(time) (TIMER2(sfClock_getElapsedTime(time).microseconds))
    #define TIMER2(time) ((float)(time) / 1000000)

    typedef struct audio_s {
        sfSoundBuffer *menu_buffer;
        sfSound *menu;
        sfSoundBuffer *death_buffer;
        sfSound *death;
        sfSoundBuffer *empty_buffer;
        sfSound *empty;
        sfSoundBuffer *game_buffer;
        sfSound *game;
        sfSoundBuffer *shot_buffer;
        sfSound *shot;
        sfSoundBuffer *hurt_buffer;
        sfSound *hurt;
        sfSoundBuffer *level_buffer;
        sfSound *level;
    } audio_t;

    typedef struct pause_s {
        sfTexture *pause_texture;
        sfSprite *pause;
        sfTexture *menu_texture;
        sfSprite *menu;
        sfTexture *menu2_texture;
        sfSprite *menu2;
        sfTexture *quit_texture;
        sfSprite *quit;
        sfTexture *quit2_texture;
        sfSprite *quit2;
        sfTexture *resume_texture;
        sfSprite *resume;
        sfTexture *resume2_texture;
        sfSprite *resume2;
    } pause_t;

    typedef struct my_textures_s {
        sfTexture *bush;
        sfTexture *charges;
        sfTexture *charges2;
        sfTexture *crosshair;
        sfTexture *grass;
        sfTexture *life;
        sfTexture *life2;
        sfTexture *player;
        sfTexture *spawner;
        sfTexture *zombie;
        sfTexture *zombie2;
    } my_textures_t;

    typedef struct enemies_s {
        sfClock *ztime;
        float zcd;
        int zrate;
        int nb;
        int lvl;
        int lvlup;
        int kill;
        int speed;
        sfRectangleShape *rectangle;
        sfSprite *zsprite;
        sfSprite *zsprite2;
        sfSprite *bushsp;
        sfFont *font;
        sfText *lvl_text;
        sfText *lvl_text2;
        char *str_lvl;
    } enemies_t;

    typedef struct my_window_s {
        sfRenderWindow *window;
        sfEvent event;
        sfClock *time;
        float deltaT;
        struct enemies_s enemies;
        sfVector2i mouse;
        audio_t audio;
        pause_t pause;
        int high_score;
    } win_t;

    typedef struct life_s {
        int count;
        sfSprite *full;
        sfSprite *empty;
        int x;
        int y;
        sfClock *time;
        int frame;
        int nbFrame;
        float cd;
    } life_t;

    typedef struct charge_s {
        int count;
        sfSprite *full;
        sfSprite *empty;
        int x;
        int y;
        sfClock *time;
        int frame;
        int nbFrame;
        float cd;
    } charge_t;

    typedef struct zombie_s {
        sfSprite *sprite;
        sfVector2f pos;
        sfClock *time;
        int frame;
        int nbframe;
        float cd;
        float speed;
        int side;
        int size;
        struct zombie_s *next;
    } zombie_t;

    typedef struct spawner_s {
        sfSprite *sprite;
        sfVector2f pos;
        int side;
        struct spawner_s *next;
    } spawner_t;

    typedef struct crossh_s {
        sfSprite *sprite;
        int rex;
    } crossh_t;

    typedef struct grass_s {
        sfSprite *sprite;
    } grass_t;

    typedef struct player_s {
        sfText *score_text;
        sfText *combo_text;
        sfFont *font;
        int score;
        int combo;
        char *str_score;
        char *str_combo;
        int combo_size;
        sfSprite *sprite;
    } player_t;

    typedef struct objects_s {
        grass_t grass;
        grass_t grass2;
        player_t player;
        crossh_t crossh;
        charge_t charge;
        life_t life;
        zombie_t *zombie;
        spawner_t *spawner;
    } obj_t;

    int hunter(void);
    int main_loop(win_t *win, obj_t *obj);
    obj_t init_objects(my_textures_t textures);
    void draw_obj(win_t *win, obj_t *obj);
    sfSprite *init_sprite(sfTexture *texture, sfVector2f size);
    life_t init_life(my_textures_t textures);
    void draw_life(win_t *win, life_t *life);
    charge_t init_charge(my_textures_t textures);
    void draw_charge(win_t *win, charge_t *charge);
    void get_deltat(win_t *win);
    int my_random(int min, int max);
    int add_zombie(zombie_t **zombie, win_t *win);
    void manage_zombie(win_t *win, obj_t *obj, zombie_t **zombie);
    void init_enemies(win_t *win, my_textures_t textures);
    int cap_nb(int nb, int max);
    grass_t init_grass2(my_textures_t textures);
    void zcheck(win_t *win, obj_t *obj, zombie_t **zombie);
    void zombie_attack(zombie_t **begin, obj_t *obj, win_t *win);
    void attack_zombie(win_t *win, obj_t *obj, zombie_t **zombie);
    int check_target(zombie_t *temp, win_t *win);
    void init_score(player_t *player);
    void my_atoa(int nb, char *str);
    int min(int nb, int min);
    void add_bush(spawner_t **spawner, win_t *win);
    void draw_spawner(win_t *win, spawner_t **spawner);
    void free_all(win_t *win, obj_t *obj, my_textures_t *texture);
    audio_t init_audio(void);
    void free_zombie(zombie_t **zombie, spawner_t **spawner);
    void new_game(win_t *win, obj_t *obj);
    void pause_loop(win_t *win, obj_t *obj);
    pause_t init_pause(void);
    int get_score(void);
    void save_score(int nb);
    int my_power(int a, int b);
    void draw_lvl(win_t *win, obj_t *obj);
    void spawn_new_zombie(win_t *win, obj_t *obj, zombie_t **zombie);
    int add_zombie_bush(zombie_t **zombie, win_t *win,
        sfVector2f spawn, int side);
    void difficulty(zombie_t *zombie, win_t *win);
    int big_slime(zombie_t **chain, zombie_t *zombie, win_t *win);

#endif
