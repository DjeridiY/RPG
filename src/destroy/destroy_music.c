/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** destroy_music.c
*/

#include "my.h"
#include "rpg.h"
#include "music.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void destroy_music(music_t **music)
{
    for (int i = 0; i < music_nbr; i++) {
        sfMusic_destroy(music[i]->music);
        free(music[i]->music_name);
        free(music[i]);
    }
    free(music);
}
