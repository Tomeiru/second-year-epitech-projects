##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	my_cat.cpp

INC_PATH =	include

NAME =	my_cat

OBJ = 	$(SRC:.cpp=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra

$(NAME):	$(OBJ)	$(OBJMAIN)
		@g++ -o $(NAME) $(OBJ) $(CFLAGS)

all:	$(NAME)

debug:	CFLAGS += -g
debug:	fclean all
		@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all