/*
** PROJECT, 2022
** RPG
** File description:
** play_and_stop_music.c
*/

#include "rpg.h"
#include "music.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

void check_pause(music_t **music, int i)
{
    if (sfMusic_getStatus(music[i]->music) == sfPaused) {
        sfMusic_play(music[i]->music);
    }
}

void check_play(music_t **music, int i)
{
    if (sfMusic_getStatus(music[i]->music) == sfPlaying) {
        sfMusic_pause(music[i]->music);
    }
}

void play_and_stop_music(music_t **music)
{
    for (int i = 0; i < music_nbr; i++) {
        if (music[i]->play) {
            check_pause(music, i);
        } else {
            check_play(music, i);
        }
    }
}
