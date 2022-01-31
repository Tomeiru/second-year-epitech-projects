##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/main.cpp	\
		src/argumentCheck.cpp

NAME =	MyGKrellm

OBJ = 	$(SRC:.cpp=.o)

CPPFLAGS = -I./includes -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
