/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** change_window_size.c
*/

#include "my.h"
#include "rpg.h"
#include "drop.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void setup_window(drop_t **drop, sfRenderWindow *window, int i, rpg_t *game)
{
    char *temp = NULL;
    char **tab = NULL;
    sfVector2u test;

    if (drop[0]->option[i]->clicked) {
        temp = my_strdup(drop[0]->option[i]->name);
        tab = my_str_to_word_array(temp, 'x');
        test.x = (float)my_atoi(tab[0]);
        test.y = (float)my_atoi(tab[1]);
        sfRenderWindow_setSize(window, test);
        drop[0]->option[i]->clicked = false;
        free(temp);
        free_tab(tab);
    }
}

void change_window_size(drop_t **drop, sfRenderWindow *window, rpg_t *game)
{
    if (drop[0]->clicked) {
        for (int i = 0; i < option_nbr[0]; i++) {
            setup_window(drop, window, i, game);
        }
    }
}
