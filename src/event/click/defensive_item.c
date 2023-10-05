/*
** PROJECT, 2022
** RPG
** File description:
** defensive_item.c
*/

#include "rpg.h"
#include "my.h"
#include "item.h"
#include "stat.h"
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdbool.h>
#include <stdlib.h>

void drink_heal_potion(item_t *item, entity_t *player,
item_t *nothing, rpg_t *game)
{
    sfVector2f position_in = player->stat->utility->pos;
    sfVector2f position_out = item->pos;

    if (my_strcmp(item->name, "heal potion") == 0) {
        sfMusic_play(game->sound[4]->sound);
        sfMusic_setPlayingOffset(game->sound[4]->sound, sfTime_Zero);
        player->stat->hp += item->damage;
        item->equiped = false;
        item->visible = false;
        item->used = true;
        if (player->stat->hp > player->stat->max_hp)
            player->stat->hp = player->stat->max_hp;
        player->stat->utility = nothing;
        player->stat->utility->pos = position_in;
        sfSprite_setPosition(player->stat->utility->sprite,
        player->stat->utility->pos);
        player->stat->utility->visible = true;
        player->stat->utility->equiped = true;
    }
}

void drink_speed_potion(item_t *item, entity_t *player,
item_t *nothing, rpg_t *game)
{
    sfVector2f position_in = player->stat->utility->pos;
    sfVector2f position_out = item->pos;

    if (my_strcmp(item->name, "speed potion") == 0) {
        sfMusic_play(game->sound[4]->sound);
        sfMusic_setPlayingOffset(game->sound[4]->sound, sfTime_Zero);
        player->stat->raw_speed += item->damage;
        item->equiped = false;
        item->visible = false;
        item->used = true;
        player->stat->utility = nothing;
        player->stat->utility->pos = position_in;
        sfSprite_setPosition(player->stat->utility->sprite,
        player->stat->utility->pos);
        player->stat->utility->visible = true;
        player->stat->utility->equiped = true;
    }
}

void drink_defense_potion(item_t *item, entity_t *player,
item_t *nothing, rpg_t *game)
{
    sfVector2f position_in = player->stat->utility->pos;
    sfVector2f position_out = item->pos;

    if (my_strcmp(item->name, "defense potion") == 0) {
        sfMusic_play(game->sound[4]->sound);
        sfMusic_setPlayingOffset(game->sound[4]->sound, sfTime_Zero);
        player->stat->defense += 3;
        item->equiped = false;
        item->visible = false;
        item->used = true;
        player->stat->utility = nothing;
        player->stat->utility->pos = position_in;
        sfSprite_setPosition(player->stat->utility->sprite,
        player->stat->utility->pos);
        player->stat->utility->visible = true;
        player->stat->utility->equiped = true;
    }
}

void drink_magic_potion(item_t *item, entity_t *player,
item_t *nothing, rpg_t *game)
{
    sfVector2f position_in = player->stat->utility->pos;
    sfVector2f position_out = item->pos;

    if (my_strcmp(item->name, "magic potion") == 0) {
        sfMusic_play(game->sound[4]->sound);
        sfMusic_setPlayingOffset(game->sound[4]->sound, sfTime_Zero);
        player->stat->xp += 10;
        item->equiped = false;
        item->visible = false;
        item->used = true;
        player->stat->utility = nothing;
        player->stat->utility->pos = position_in;
        sfSprite_setPosition(player->stat->utility->sprite,
        player->stat->utility->pos);
        player->stat->utility->visible = true;
        player->stat->utility->equiped = true;
    }
}

void defensive_item(item_t *item, entity_t *player,
item_t *nothing, rpg_t *game)
{
    if (my_strcmp(item->utility, "defense") != 0)
        return;
    if (item->equiped == false) {
        collect_item(player, item);
    } else {
        drink_speed_potion(item, player, nothing, game);
        drink_heal_potion(item, player, nothing, game);
        drink_defense_potion(item, player, nothing, game);
        drink_magic_potion(item, player, nothing, game);
    }
}
