/*
** PROJECT, 2022
** c-library
** File description:
** file_to_tab.c
*/

#include "../my.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

char **file_to_tab(char *file)
{
    int size = 0;
    struct stat sb;
    stat(file, &sb);
    int nbr_of_char = sb.st_size;
    int fd = open(file, O_RDONLY);
    char *str = NULL;
    char **tab = NULL;

    str = malloc(sizeof(char) * (nbr_of_char + 1));
    *str = (char){0};
    size = read(fd, str, (nbr_of_char));
    str[size] = '\0';
    tab = my_str_to_word_array(str, '\n');
    close(fd);
    return tab;
}
