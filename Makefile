##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/main.cpp	\
		src/Error.cpp \
		src/Unsold.cpp

NAME =	202unsold

OBJ = 	$(SRC:.cpp=.o)

CPPFLAGS = -g -I./include -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
