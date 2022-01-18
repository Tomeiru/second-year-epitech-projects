##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	tests/tests_ARRAY_1D_TO_2D.c	\
		tests/tests_CONCAT.c	\
		tests/tests_MUL_DIV.c	\
		tests/tests_PRINT.c	\
		ex01/mul_div.c	\
		ex02/concat.c	\
		ex03/array_1d_to_2d.c	\
		ex04/print.c

INC_PATH =	tests

NAME =	unit_tests

OBJ = 	$(SRC:.c=.o)

CFLAGS = -I. -I$(INC_PATH) --coverage

tests_run:	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -lcriterion
		./unit_tests


clean:
		rm -f $(OBJ)
		rm -f *.gc*

fclean:	clean
		rm -fr $(NAME)

re:	fclean tests_run
