/*
** EPITECH PROJECT, 2022
** c-library
** File description:
** my_tolower.c
*/

int my_tolower(int c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}
