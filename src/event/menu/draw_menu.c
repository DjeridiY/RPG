/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** draw_menu.c
*/

#include "rpg.h"
#include "music.h"
#include "my.h"
#include "print_stat.h"
#include "image.h"
#include "text.h"
#include "rectangle.h"
#include "text.h"
#include "entity.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>

void set_all_true(rpg_t *game)
{
    for (int i = 0; i < img_nbr; i++)
        game->image[i]->visible = true;
    for (int i = 0; i < rect_nbr; i++)
        game->rect[i]->visibility = true;
    for (int i = 0; i < text_nbr - 3; i++)
        game->text[i]->visible = true;
    if (game->entity[0]->stat->utility->equiped)
        game->entity[0]->stat->utility->visible = true;
    if (game->entity[0]->stat->weapon->equiped)
        game->entity[0]->stat->weapon->visible = true;
    for (int i = 0; i < text_nbr - 3; i++)
        game->text[i]->visible = true;
    for (int i = 0; i < entity_nbr; i++)
        game->entity[i]->visible = false;
    for (int i = 5; i < 9; i++)
        game->button[i]->visible = true;
}

void menu_on(rpg_t *game)
{
    for (int i = 0; i < print_nbr; i++) {
        sfText_setPosition(game->stat[0]->print_stat[i]->title,
        game->stat[0]->print_stat[i]->pos);
        sfText_setFillColor(game->stat[0]->print_stat[i]->title,
        game->stat[0]->print_stat[i]->color);
        game->stat[0]->print_stat[i]->visible = true;
    }
    set_all_true(game);
    for (int i = 6; i < 8; i++) {
        game->button[i]->visible = true;
    }
}

void set_all_false(rpg_t *game)
{
    for (int i = 0; i < img_nbr; i++)
        game->image[i]->visible = false;
    for (int i = 0; i < rect_nbr; i++)
        game->rect[i]->visibility = false;
    for (int i = 0; i < text_nbr; i++)
        game->text[i]->visible = false;
    if (game->entity[0]->stat->utility->equiped)
        game->entity[0]->stat->utility->visible = false;
    if (game->entity[0]->stat->weapon->equiped)
        game->entity[0]->stat->weapon->visible = false;
    for (int i = 0; i < text_nbr - 3; i++)
        game->text[i]->visible = false;
    for (int i = 0; i < entity_nbr; i++)
        game->entity[i]->visible = true;
    for (int i = 5; i < 9; i++)
        game->button[i]->visible = false;
}

void menu_off(rpg_t *game)
{
    for (int i = 0; i < print_nbr; i++) {
        sfText_setPosition(game->stat[0]->print_stat[i]->title,
        game->stat[0]->print_stat[i]->pos);
        sfText_setFillColor(game->stat[0]->print_stat[i]->title,
        game->stat[0]->print_stat[i]->color);
        game->stat[0]->print_stat[i]->visible = false;
    }
    set_all_false(game);
}

void draw_menu(rpg_t *game)
{
    if (game->button[2]->visible) {
        if (game->button[2]->clicked == false) {
            menu_on(game);
        } else {
            menu_off(game);
        }
    } else {
        menu_off(game);
    }
}
