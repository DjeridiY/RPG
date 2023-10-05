/*
** PROJECT, 2022
** c-library
** File description:
** free_linked_list.c
*/

#include <stddef.h>
#include "../list.h"
#include <stdlib.h>

void free_list(list_t *list)
{
    list_t *tmp;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}
