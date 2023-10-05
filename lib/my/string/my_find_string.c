/*
** PROJECT, 2022
** my_strstr.c function
** File description:
** ctrl F function in a string
*/

#include <stddef.h>

char *my_find_string(char *str ,char const *to_find)
{
    int i = 0;
    int w = 0;

    if (to_find == 0) {
        return (str);
    }

    while (str[i] != '\0') {
        while (str[i + w] == to_find[w] && to_find[w] != '\0') {
            w++;
        }
        if (to_find[w] == '\0') {
            return &str[i];
        }
        w = 0;
        i++;
    }
    return NULL;
}
