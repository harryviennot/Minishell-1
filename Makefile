##
## EPITECH PROJECT, 2021
## my_printf
## File description:
## Makefile
##

NAME	=	mysh

SRC	= 	main.c\
		minishell.c\
		remove.c\
		my_cd.c\
		get.c\
		get2.c\
		my_setenv.c\
		my_unsetenv.c\
		check.c\
		multiple_cmds.c\
		redirect.c\

LDFLAGS		=	-L lib/ -lmy

CFLAGS	=		-I ./include/ -g3

OBJ	=	$(SRC:.c=.o)

$(NAME):
		@$(MAKE) -s -C lib/
		@$(MAKE) -s $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LDFLAGS)

all:	$(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

lclean:
		@$(MAKE) -s -C lib/ fclean

re: fclean all
