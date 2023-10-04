/*
** EPITECH PROJECT, 2022
** strncat
** File description:
** strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int o = 0;
    int lengh = my_strlen(dest);

    if (nb > lengh) {
        while (src[i] != '\0') {
            dest[i + lengh] = src[i];
            i++;
        }
        dest[i + lengh] = '\0';
    }
    if (nb < lengh) {
        while (i < nb) {
            dest[i] = src[i];
            i++;
        }
    }
    dest[i + lengh] = '\0';
    return (dest);
}
