/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** draw.c
*/

#include "my.h"
#include "rpg.h"
#include "back.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void draw(rpg_t *game)
{
    draw_back(game->back, game->window);
    draw_drop(game->drop, game->window, game);
    draw_image(game->image, game->window);
    draw_rectangle(game->rect, game->window);
    draw_button(game->button, game->window);
    draw_cursor(game->cursor, game->window);
    draw_item(game->item, game->window);
    draw_stat(game->stat, game->window);
    draw_entire_text(game->text, game->window);
    draw_entity(game->entity, game->window);
    visual_effect(game);
}
