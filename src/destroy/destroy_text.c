/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** destroy_back.c
*/

#include "my.h"
#include "back.h"
#include "rpg.h"
#include "stat.h"
#include <stdlib.h>

void destroy_text(text_t *text)
{
    sfText_destroy(text->title);
    sfFont_destroy(text->font);
    free(text);
}
