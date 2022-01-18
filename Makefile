##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	string_init_destroy.c	\
		string_assign.c	\
		string_append.c	\
		string_info.c	\
		string_clear.c	\
		string_compare.c	\
		string_copy.c	\
		string_find.c

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