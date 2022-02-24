##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/NanoTekSpice.cpp	\
		src/NanoError.cpp	\
		src/NanoParser.cpp	\
		src/Component/ABasicComponent.cpp 	\
		src/Component/AGateComponent.cpp	\
		src/Component/AAdvancedComponent.cpp	\

NAME =	nanotekspice

OBJ = 	$(SRC:.cpp=.o)

CPPFLAGS = -g -I./include -I./include/Component -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
