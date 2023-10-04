/*
** EPITECH PROJECT, 2022
** flag_string
** File description:
** print string
*/

#include <stdarg.h>

int my_putstr(char const *str);
int my_strlen(char *c);

int flag_string(va_list ap, int precis)
{
    char *string;
    int length = 0;

    string = va_arg(ap, char *);
    my_putstr(string);
    length = 0;
    length = my_strlen(string);
    return (length);
}
