/*
** PROJECT, 2022
** Paint
** File description:
** destroy_dropdown.c
*/

#include "my.h"
#include "rpg.h"
#include "drop.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

void destroy_option(button_t **option, int nbr_option)
{
    for (int i = 0; i < nbr_option; i++) {
        sfRectangleShape_destroy(option[i]->rect);
        sfText_destroy(option[i]->text->title);
        sfFont_destroy(option[i]->text->font);
        free(option[i]->text);
        free(option[i]->name);
        free(option[i]);
    }
    free(option);
}

void destroy_drop(drop_t **drop)
{
    for (int i = 0; i < nbr_drop; i++) {
        destroy_option(drop[i]->option, option_nbr[i]);
        sfRectangleShape_destroy(drop[i]->rect);
        sfText_destroy(drop[i]->text->title);
        sfFont_destroy(drop[i]->text->font);
        free(drop[i]->text);
        free(drop[i]->name);
        free(drop[i]);
    }
    free(drop);
}
