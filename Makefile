##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	string_init_destroy.c	\
		assign_function.c	\
		append_function.c

OBJ = 	$(SRC:.c=.o)

NAME = libstring.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		@rm -fr ../libmy.a

re:	fclean all