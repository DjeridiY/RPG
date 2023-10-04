/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** header prototype function
*/

#include <stdarg.h>

int flag_decimal(va_list ap, int precis);
int flag_integer(va_list ap, int precis);
int flag_octal(va_list ap, int precis);
int flag_percent(va_list ap, int precis);
int flag_string(va_list ap, int precis);
int flag_character(va_list ap, int precis);
int flag_unsigned(va_list ap, int precis);
int flag_hexa_min(va_list ap, int precis);
int flag_hexa_maj(va_list ap, int precis);
int flag_binary(va_list ap, int precis);
int flag_pointer(va_list ap, int precis);
int flag_s_maj(va_list ap, int precis);
int flag_expo_min(va_list ap, int precis);
int flag_float(va_list ap, int precis);
int flag_expo_maj(va_list ap, int precis);

#ifndef FUNCTION_H_
    #define FUNCTION_H_

typedef struct flag_detect {
    char character;
    int (*cmp)(va_list, int);
    int end;
} flag_detect_t;
flag_detect_t tab_function[] = {
    {'d', &flag_decimal, false},
    {'i', &flag_integer, false},
    {'%', &flag_percent, false},
    {'o', &flag_octal, false},
    {'s', &flag_string, false},
    {'c', &flag_character, false},
    {'u', &flag_unsigned, false},
    {'x', &flag_hexa_min, false},
    {'X', &flag_hexa_maj, false},
    {'p', &flag_pointer, false},
    {'S', &flag_s_maj, false},
    {'f', &flag_float, false},
    {'e', &flag_expo_min, false},
    {'E', &flag_expo_maj, false},
    {'b', &flag_binary, false},
    {'k', &flag_s_maj, true}
};

#endif /* FUNCTION_H_ */
