/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-myrpg-yanis.djeridi
** File description:
** map_object.c
*/

#include "my.h"
#include "rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdio.h>

int len_liste(list_t *liste)
{
    list_t *tmp = liste;
    int cn = 0;

    while (tmp != NULL) {
        cn++;
        tmp = tmp->next;
    }
    return cn;
}

void add_to_list(list_t **liste, void *data)
{
    list_t *element = malloc(sizeof(list_t));

    element->data = data;
    element->next = *liste;
    *liste = element;
}

int **malloc_structure(int x, int y)
{
    int **structure = malloc(sizeof(int *) * y);

    for (int i = 0; i < y; i++)
        structure[i] = malloc(sizeof(int) * x);
    for (int y_tab = 0; y_tab < y; y_tab++)
        for (int x_tab = 0; x_tab < x; x_tab++)
            structure[y_tab][x_tab] = 0;
    return structure;
}

bool is_valid(sfVector2f pos, int width, int height)
{
    if (pos.x >= 0 && pos.x < width && pos.y >= 0 && pos.y < height)
        return true;
    return false;
}
