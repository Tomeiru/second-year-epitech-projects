##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	main.c

NAME =	204ducks

OBJ = 	$(SRC:.c=.o)

CFLAGS = -g -I./include -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CPPFLAGS) -lm

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
