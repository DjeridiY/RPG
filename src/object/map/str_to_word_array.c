/*
** PROJECT, 2022
** Task04
** File description:
** task04
*/

#include <stdlib.h>
#include "my.h"
#include "rpg.h"
#include <stdio.h>
#include <string.h>

int my_char_is(char const c, const char *separator)
{
    if (c == 0)
        return 0;
    for (int i = 0; separator[i] != 0; i++)
        if (separator[i] == c)
            return 0;
    return 1;
}

int count_need_array_lign(char const *str, const char *separator)
{
    int cn = 0;
    char last_char = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (my_char_is(str[i], separator) == 1 &&
                my_char_is(last_char, separator) == 0)
            cn++;
        last_char = str[i];
    }
    return cn;
}

int count_need_array_cln(char const *str, int position, const char *separator)
{
    int i = 0;

    while (my_char_is(str[position + i], separator) == 1)
        i++;
    return i;
}

char **init_array(char *str, const char *separator)
{
    int size = count_need_array_lign(str, separator);
    char **array = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i < size; i++) {
        array[i] = malloc(sizeof(char) * 3001);
        for (int j = 0; j < 3000; j++)
            array[i][j] = 0;
    }
    array[size] = NULL;
    return array;
}

char **str_to_word_array(char *str, const char *separator)
{
    char **array = init_array(str, separator);
    int col = 0;
    int lign = 0;
    char last_char = 0;

    for (int i = 0; str[i] != 0; i++) {
        if (my_char_is(str[i], separator) == 1 &&
                my_char_is(last_char, separator) == 0 && col != 0) {
            array[lign][col] = 0;
            lign++;
            col = 0;
        } if (my_char_is(str[i], separator) == 1) {
            array[lign][col] = str[i];
            col++;
        }
        last_char = str[i];
    }
    return array;
}
