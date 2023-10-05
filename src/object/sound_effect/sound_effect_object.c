/*
** PROJECT, 2022
** B-MUL-100-PAR-1-1-myhunter-yanis.djeridi
** File description:
** create_window.c
*/

#include "rpg.h"
#include "sound_effect.h"
#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>

sound_effect_t *create_sound(int i)
{
    sound_effect_t *sound = malloc(sizeof(sound_effect_t));

    sound->sound = sfMusic_createFromFile(sound_file[i]);
    sound->sound_name = my_strdup((char *)(sound_name[i]));
    sound->volume = sound_volume[i];
    sfMusic_setVolume(sound->sound, sound->volume);
    return sound;
}

void sound_effect_object(sound_effect_t **sound)
{
    for (int i = 0; i < sound_nbr; i++) {
        sound[i] = create_sound(i);
    }
}
