/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** create.c
*/

#include "my.h"
#include "rpg.h"
#include "back.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void object_create(rpg_t *game)
{
    back_object(game->back);
    dropdown_object(game->drop);
    button_object(game->button);
    create_music(game->music);
    cursor_object(game->cursor);
    item_object(game->item);
    stat_object(game->stat, game->item);
    image_object(game->image);
    rectangle_object(game->rect);
    text_object(game->text);
    effect_object(game->effect);
    entity_object(game->entity, game->stat, game->effect);
    view_object(game->view, game);
    map_object(game->map, game);
    sound_effect_object(game->sound);
    spawn_entities(game);
}

int create(rpg_t *game)
{
    game->fullscreen = false;
    malloc_object(game);
    game->clock->clock = sfClock_create();
    game->clock->time_pressed = 0;
    game->window = create_window("my_rpg", 1280, 720);
    object_create(game);
    adapt_back_to_screen(game);
    sfRenderWindow_setFramerateLimit(game->window, 120);
    return 0;
}
