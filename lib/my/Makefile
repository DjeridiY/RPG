##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SORT	=	sort/

EXTRACT	=	extract/

TAB	=	tab/

LIST	=	list/

STRING	=	string/

PRINT	=	print/

PRINTF	=	print/my_printf/

SRC	=	$(EXTRACT)file_to_string.c	\
		$(EXTRACT)file_to_tab.c	\
		$(TAB)free_tab_int.c	\
		$(TAB)free_tab.c	\
		$(TAB)print_tab.c	\
		$(TAB)print_tab_int.c	\
		$(TAB)my_str_to_word_array.c	\
		$(TAB)my_tabdup.c	\
		$(TAB)size_of_tab.c	\
		$(STRING)my_itoa.c	\
		$(STRING)my_str_isalpha.c	\
		$(STRING)my_str_isnum.c	\
		$(STRING)my_strcat.c	\
		$(STRING)my_strcmp.c	\
		$(STRING)my_strcpy.c	\
		$(STRING)my_strdup.c	\
		$(STRING)my_strlen.c	\
		$(STRING)my_strncat.c	\
		$(STRING)my_strncmp.c	\
		$(STRING)my_strncpy.c	\
		$(STRING)my_find_string.c	\
		$(STRING)my_tolower.c	\
		$(STRING)my_toupper.c	\
		$(STRING)remove_char.c	\
		$(STRING)my_atoi.c	\
		$(PRINT)my_putchar.c	\
		$(PRINT)my_putnbr.c	\
		$(PRINT)my_putstr.c	\
		$(PRINT)my_putnbr_unsigned.c	\
		$(PRINTF)my_printf.c	\
		$(PRINTF)other/count.c	\
		$(PRINTF)my_putnbr_base/my_putnbr_base8.c	\
        $(PRINTF)my_putnbr_base/my_putnbr_base8_modif.c	\
        $(PRINTF)my_putnbr_base/my_putnbr_base_hexa_maj.c	\
        $(PRINTF)my_putnbr_base/my_putnbr_base_hexa_min.c	\
        $(PRINTF)my_putnbr_base/my_putnbr_base_hexa_min_for_p.c	\
        $(PRINTF)my_putnbr_base/my_putnbr_binary.c	\
		$(PRINTF)flags/flag_binary.c	\
        $(PRINTF)flags/flag_character.c	\
        $(PRINTF)flags/flag_decimal.c	\
    	$(PRINTF)flags/flag_hexa_maj.c	\
        $(PRINTF)flags/flag_hexa_min.c	\
        $(PRINTF)flags/flag_integer.c	\
        $(PRINTF)flags/flag_n.c	\
        $(PRINTF)flags/flag_octal.c	\
        $(PRINTF)flags/flag_s_maj.c	\
        $(PRINTF)flags/flag_percent.c	\
        $(PRINTF)flags/flag_pointer.c	\
        $(PRINTF)flags/flag_string.c	\
        $(PRINTF)flags/flag_unsigned.c	\
		$(PRINTF)flags/flag_expo.c	\
		$(PRINTF)flags/flag_float.c	\
		$(PRINTF)flags/flag_expo_maj.c \
		$(LIST)free_list.c	\
		$(LIST)list_size.c	\
		$(LIST)params_to_list.c	\
		$(LIST)print_list.c	\
		$(SORT)bubble_sort_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
clean :
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)
	rm -f $(NAME)
	rm -f ../../$(NAME)

re:     fclean all

.PHONY: all clean fclean re
