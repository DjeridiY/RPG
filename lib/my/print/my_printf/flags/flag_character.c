/*
** EPITECH PROJECT, 2022
** flag_character
** File description:
** print a character
*/

#include <stdarg.h>

void my_putchar(char c);

int flag_character(va_list ap, int precis)
{
    char character;

    character = (char) va_arg(ap, int);
    my_putchar(character);
    return (1);
}
