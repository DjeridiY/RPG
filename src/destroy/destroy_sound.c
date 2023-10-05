/*
** PROJECT, 2022
** RPG
** File description:
** destroy_music.c
*/

#include "my.h"
#include "rpg.h"
#include "sound_effect.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void destroy_sound(sound_effect_t **sound)
{
    for (int i = 0; i < sound_nbr; i++) {
        sfMusic_destroy(sound[i]->sound);
        free(sound[i]->sound_name);
        free(sound[i]);
    }
    free(sound);
}
