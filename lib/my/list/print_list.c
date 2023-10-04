/*
** EPITECH PROJECT, 2022
** c-library
** File description:
** print_linked_list.c
*/

#include <stdlib.h>
#include "../list.h"
#include "../my.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(list_t *list)
{
    while (list != NULL) {
        my_printf("%d\n", list->data);
        list = list->next;
    }
}
