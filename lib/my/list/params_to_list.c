/*
** EPITECH PROJECT, 2022
** c-library
** File description:
** params_to_linked_list.c
*/

#include <stdlib.h>
#include "../list.h"
#include "../my.h"
#include <stdio.h>
#include <stdlib.h>

list_t *params_to_list(int ac, char **av)
{
    int i = 0;
    list_t *current = NULL;
    list_t *last = NULL;
    list_t *list = NULL;
    int stock = 0;

    list = malloc(sizeof(list_t));
    list->data = av[1];
    list->next = NULL;
    last = list;
    for (i = 2; i < ac; i++) {
        current = malloc(sizeof(list_t));
        current->data = av[i];
        current->next = NULL;
        last->next = current;
        last = current;
    }
    return list;
}
