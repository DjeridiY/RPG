/*
** PROJECT, 2022
** PushSwap
** File description:
** linked_list.h
*/

#include <stddef.h>

#ifndef LIST_H_
    #define LIST_H_

typedef struct list {

    void *data;
    struct list *next;

} list_t;

#endif /* LIST_H_ */
