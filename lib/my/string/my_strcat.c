/*
** PROJECT, 2022
** strcat
** File description:
** strcat function
*/

#include <stdio.h>
#include "../my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int o = 0;
    int lengh = my_strlen(dest);

    while (src[i] != '\0') {
        dest[i + lengh] = src[i];
        i++;
    }
    dest[i + lengh] = '\0';
    return (dest);
}
