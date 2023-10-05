/*
** PROJECT, 2022
** RPG
** File description:
** destroy_back.c
*/

#include "my.h"
#include "rpg.h"
#include "text.h"
#include <stdlib.h>

void destroy_entire_text(text_t **text)
{
    for (int i = 0; i < text_nbr; i++) {
        destroy_text(text[i]);
    }
    free(text);
}
