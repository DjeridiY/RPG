/*
** PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** get_printable_stat.c
*/


#include "my.h"
#include "rpg.h"
#include "stat.h"
#include "print_stat.h"
#include "item.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

text_t **get_printable_stat(int i, stat_t *stat)
{
    text_t **print_stat = malloc(sizeof(text_t *) * (print_nbr));

    for (int i = 0; i < 10; i++) {
        print_stat[i] = create_text(p_visbility[i], p_size[i],
        get_vector(p_pos_x[i], p_pos_y[i]), get_color(p_red[i], p_green[i],
        p_blue[i], p_alpha[i]));
    }
    return print_stat;
}
