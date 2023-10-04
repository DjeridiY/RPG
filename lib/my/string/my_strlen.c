/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** my_strlen function
*/

#include <unistd.h>
#include <stdio.h>

int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    return (i);
}
