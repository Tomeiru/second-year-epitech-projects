##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/NanoTekSpice.cpp	\

NAME =	nanotekspice

OBJ = 	$(SRC:.cpp=.o)

CPPFLAGS = -I./include -I./include/Module -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
