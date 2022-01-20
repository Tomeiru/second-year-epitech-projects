##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	tests/tests_PLAYER.c	\
		tests/tests_POINT.c	\
		tests/tests_VERTEX.c	\
		tests/tests_CHAR.c	\
		tests/tests_INT.c	\
		tests/tests_FLOAT.c	\
		tests/player.c	\
		new.c	\
		point.c \
		vertex.c \
		char.c	\
		int.c	\
		float.c

INC_PATH =	tests

NAME =	unit_tests

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH) --coverage

tests_run:	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -lcriterion
		./unit_tests

clean:
		rm -f $(OBJ)
		rm -f */*.gc*
		rm -f *.gc*


fclean:	clean
		rm -fr $(NAME)

re:	fclean tests_run