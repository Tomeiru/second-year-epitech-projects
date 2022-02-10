##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	sources/calloc.c	\
		sources/free.c	\
		sources/malloc.c	\
		sources/realloc.c	\
		sources/reallocarray.c

CFLAGS = -Wall -Wextra -fpic -I./include

OBJ = 	$(SRC:.c=.o)

NAME = libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -shared -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
