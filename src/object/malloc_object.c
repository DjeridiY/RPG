/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** malloc_object.c
*/

#include "rpg.h"
#include "button.h"
#include "back.h"
#include "cursor.h"
#include "drop.h"
#include "music.h"
#include "item.h"
#include "stat.h"
#include "image.h"
#include "rectangle.h"
#include "text.h"
#include "sound_effect.h"
#include "entity.h"
#include "effect.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void malloc_object(rpg_t *game)
{
    game->back = malloc(sizeof(back_t *) * (back_nbr));
    game->drop = malloc(sizeof(drop_t *) * (nbr_drop));
    game->button = malloc(sizeof(button_t *) * (nbr_button));
    game->music = malloc(sizeof(music_t *) * (music_nbr));
    game->cursor = malloc(sizeof(cursor_t *) * (nbr_of_cursor));
    game->item = malloc(sizeof(item_t *) * (item_nbr));
    game->stat = malloc(sizeof(stat_t *) * (stat_nbr));
    game->image = malloc(sizeof(image_t *) * (img_nbr));
    game->rect = malloc(sizeof(rectangle_t *) * (rect_nbr));
    game->text = malloc(sizeof(text_t *) * (text_nbr));
    game->entity = malloc(sizeof(entity_t *) * (entity_nbr));
    game->clock = malloc(sizeof(clock_rpg_t));
    game->map = malloc(sizeof(map_t));
    game->view = malloc(sizeof(view_world_t));
    game->effect = malloc(sizeof(effect_t *) * (effect_nbr));
    game->sound = malloc(sizeof(sound_effect_t *) * (sound_nbr));
    game->exit_code = 0;
}
