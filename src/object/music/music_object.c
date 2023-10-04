/*
** EPITECH PROJECT, 2022
** B-MUL-100-PAR-1-1-myhunter-yanis.djeridi
** File description:
** create_window.c
*/

#include "rpg.h"
#include "music.h"
#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

music_t *set_music(int i)
{
    music_t *music = malloc(sizeof(music_t));

    music->music = sfMusic_createFromFile(music_file[i]);
    music->music_name = my_strdup((char *)(music_name[i]));
    music->volume = volume[i];
    music->play = play[i];
    sfMusic_setVolume(music->music, music->volume);
    sfMusic_setLoop(music->music, sfTrue);
    return music;
}

void create_music(music_t **music)
{
    for (int i = 0; i < music_nbr; i++) {
        music[i] = set_music(i);
    }
}
