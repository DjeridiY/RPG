/*
** PROJECT, 2022
** my
** File description:
** my.h
*/

#include "list.h"

#ifndef MY_H_
    #define MY_H_

void bubble_sort_array(char **tab, int size_of_tab);

void free_tab(char **tab);
void free_tab_int(int **tab, int size);
void print_tab(char **tab);
void print_tab_int(int **tab, int size, int length);
char **my_str_to_word_array(char *str, char selecteur);
char **my_tabdup(char **array);
int size_of_tab(char **tab);

char *my_itoa(int number);
int my_str_isalpha(char *str);
int my_str_isnum(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strdup(char *str);
int my_strlen(const char *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_find_string(char *str ,char const *to_find);
int my_tolower(int c);
int my_toupper(int c);
char *remove_char(char *str, char not_allowed_char);
int my_atoi(char *str);

void my_putchar(char c);
int my_putnbr(int nbr);
int my_putstr(char *str);
int my_printf(const char *format, ...);

void free_list(list_t *list);
int list_size(list_t *list);
void print_list(list_t *list);
list_t *params_to_list(int ac, char **av);

char *file_to_string(char *file);
char **file_to_tab(char *file);

#endif /* MY_H_ */
