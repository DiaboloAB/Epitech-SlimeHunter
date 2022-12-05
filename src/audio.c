/*
** EPITECH PROJECT, 2022
** audio
** File description:
** audio
*/

#include "duckhunt.h"

static void init_sound_buffer(audio_t *audio)
{
    audio->death_buffer = sfSoundBuffer_createFromFile("audio/death.ogg");
    audio->menu_buffer = sfSoundBuffer_createFromFile("audio/menu.ogg");
    audio->empty_buffer = sfSoundBuffer_createFromFile("audio/empty.ogg");
    audio->game_buffer = sfSoundBuffer_createFromFile("audio/game.ogg");
    audio->shot_buffer = sfSoundBuffer_createFromFile("audio/shot.ogg");
    audio->hurt_buffer = sfSoundBuffer_createFromFile("audio/hurt.ogg");
    audio->level_buffer = sfSoundBuffer_createFromFile("audio/level.ogg");
}

static void create_sound(audio_t *audio)
{
    audio->death = sfSound_create();
    audio->menu = sfSound_create();
    audio->empty = sfSound_create();
    audio->game = sfSound_create();
    audio->shot = sfSound_create();
    audio->hurt = sfSound_create();
    audio->level = sfSound_create();
}

audio_t init_audio(void)
{
    audio_t audio = {0};
    init_sound_buffer(&audio);
    create_sound(&audio);
    sfSound_setBuffer(audio.death, audio.death_buffer);
    sfSound_setVolume(audio.death, 50);
    sfSound_setVolume(audio.hurt, 50);
    sfSound_setBuffer(audio.menu, audio.menu_buffer);
    sfSound_setLoop(audio.menu, sfTrue);
    sfSound_setBuffer(audio.empty, audio.empty_buffer);
    sfSound_setBuffer(audio.game, audio.game_buffer);
    sfSound_setLoop(audio.game, sfTrue);
    sfSound_setVolume(audio.game, 40);
    sfSound_setBuffer(audio.shot, audio.shot_buffer);
    sfSound_setBuffer(audio.hurt, audio.hurt_buffer);
    sfSound_setBuffer(audio.level, audio.level_buffer);
    return audio;
}
