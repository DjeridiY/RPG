/*
** PROJECT, 2022
** RPG
** File description:
** game_print.c
*/

#include "my.h"
#include "rpg.h"
#include "item.h"
#include "entity.h"
#include "stat.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

void unset_life(sfVector2f pos, rpg_t *game)
{
    for (int i = 1; i < stat_nbr; i++) {
        if (game->entity[i]->status == 2 || game->button[2]->visible == true) {
            game->stat[i]->print_stat[5]->visible = false;
            continue;
        }
        pos = game->entity[i]->pos;
        game->stat[i]->print_stat[5]->visible = true;
        sfText_setPosition(game->stat[i]->print_stat[5]->title,
        get_vector(pos.x + 20, pos.y - 25));
        sfText_setFillColor(game->stat[i]->print_stat[5]->title, sfWhite);
    }
}

void life(rpg_t *game)
{
    sfVector2f pos = game->entity[0]->pos;

    if (game->button[2]->visible == false) {
        game->text[1]->visible = true;
        sfText_setPosition(game->text[1]->title,
        get_vector(pos.x + 35, pos.y - 25));
        sfText_setFillColor(game->text[1]->title, sfWhite);
        game->stat[0]->print_stat[5]->visible = true;
        sfText_setPosition(game->stat[0]->print_stat[5]->title,
        get_vector(pos.x + 20, pos.y - 25));
        sfText_setFillColor(game->stat[0]->print_stat[5]->title, sfWhite);
    } else {
        game->text[1]->visible = true;
        sfText_setPosition(game->text[1]->title, game->text[1]->pos);
        sfText_setFillColor(game->text[1]->title, game->text[1]->color);
    }
    unset_life(pos, game);
}

void update(rpg_t *game)
{
    sfText_setString(game->text[7]->title, my_itoa(game->stat[0]->max_hp));
    life(game);
    adapt_item(game->item);
    get_time(game->clock);
    entity_hitbox(game);
    update_stat(game->stat, game);
    entity_die(game->entity);
    move_entity(game);
}
