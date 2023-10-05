/*
** PROJECT, 2022
** c-library
** File description:
** linked_list_size.c
*/

#include <stdlib.h>
#include "../list.h"
#include "../my.h"
#include <stdio.h>
#include <stdlib.h>

int list_size(list_t *list)
{
    int count = 0;
    struct list *temp;

    temp = list;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}
