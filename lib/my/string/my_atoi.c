/*
** PROJECT, 2022
** C-Library
** File description:
** string_to_int.c
*/

int my_atoi(char *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return res;
}
