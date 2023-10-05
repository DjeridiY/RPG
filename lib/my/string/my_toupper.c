/*
** PROJECT, 2022
** c-library
** File description:
** my_toupper.c
*/

int my_toupper(int c)
{
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}
