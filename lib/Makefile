##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Compile projects
##

SRC		=	my_printf.c\
			my_arraylen.c\
			my_put_nbr.c\
			my_putchar.c\
			my_putstr.c\
			my_str_to_word_array.c\
			my_strcmp.c\
			my_strdup.c\
			my_strlen.c\
			my_strstr.c\
			my_strcat.c\
			my_strcpy.c\
			my_memcpy.c\
			my_free.c\
			my_count_occurences.c\
			my_clean_str.c\
			create_array.c\
			my_printf_err.c\

OBJ		=		$(SRC:.c=.o)

NAME	=		libmy.a

CFLAGS	=		-I ./include/

all: 	$(NAME)
$(NAME):		$(OBJ)
		ar rc libmy.a *.o
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
