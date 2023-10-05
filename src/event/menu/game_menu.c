/*
** PROJECT, 2022
** RPG
** File description:
** play_music.c
*/

#include "rpg.h"
#include "music.h"
#include "my.h"
#include "print_stat.h"
#include "image.h"
#include "text.h"
#include "rectangle.h"
#include "text.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

void draw_setting(rpg_t *game)
{
    if (game->button[2]->clicked) {
        for (int i = 0; i < 2; i++)
            game->drop[i]->visible = true;
        game->cursor[0]->visible = true;
        for (int i = 4; i < 5; i++)
            game->button[i]->visible = true;
    } else {
        for (int i = 0; i < 2; i++)
            game->drop[i]->visible = false;
        game->cursor[0]->visible = false;
        for (int i = 4; i < 5; i++)
            game->button[i]->visible = false;
    }
}

void play_music(rpg_t *game)
{
    if (game->button[4]->clicked) {
        game->music[1]->play = false;
    } else {
        game->music[1]->play = true;
    }
}

void game_set_volume(rpg_t *game)
{
    game->music[1]->volume = game->cursor[0]->value * 100;
    sfMusic_setVolume(game->music[1]->music, game->music[1]->volume);
}

void game_setting_management(music_t **music, rpg_t *game)
{
    play_music(game);
    draw_setting(game);
    play_and_stop_music(music);
    game_set_volume(game);
    draw_menu(game);
    if (game->button[2]->visible ||
    game->entity[0]->status == 2 ||
    game->entity[1]->stat->hp <= 0) {
        game->text[16]->visible = false;
        game->text[15]->visible = false;
        game->text[14]->visible = false;
    } else {
        game->text[16]->visible = true;
        game->text[15]->visible = true;
        game->text[14]->visible = true;
    }
    sfView_setCenter(game->view->camera, (sfVector2f) {0, 0});
}
