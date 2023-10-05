/*
** PROJECT, 2022
** RPG
** File description:
** play_music.c
*/

#include "rpg.h"
#include "music.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

void draw_setting_menu(rpg_t *game)
{
    if (game->button[2]->clicked) {
        for (int i = 0; i < 2; i++) {
            game->drop[i]->visible = true;
        }
        game->cursor[0]->visible = true;
        game->button[4]->visible = true;
    } else {
        for (int i = 0; i < 2; i++) {
            game->drop[i]->visible = false;
        }
        game->cursor[0]->visible = false;
        game->button[4]->visible = false;
    }
    if (game->button[4]->clicked) {
        game->music[0]->play = false;
    } else {
        game->music[0]->play = true;
    }
}

void set_volume(rpg_t *game)
{
    game->music[0]->volume = game->cursor[0]->value * 100;
    sfMusic_setVolume(game->music[0]->music, game->music[0]->volume);
}

void menu_setting(music_t **music, rpg_t *game)
{
    draw_setting_menu(game);
    play_and_stop_music(music);
    set_volume(game);
}
