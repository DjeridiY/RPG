/*
** PROJECT, 2022
** Librairy
** File description:
** my_strdup.c
*/

#include <stdlib.h>
#include <string.h>
#include "../my.h"

char *my_strdup(char *str)
{
    int length;
    char *copy;

    length = my_strlen(str);
    copy = malloc(sizeof(char) * (length + 1));
    if (copy == NULL) {
        return (NULL);
    }
    copy = my_strcpy(copy, str);
    copy[length] = '\0';
    return copy;
}
