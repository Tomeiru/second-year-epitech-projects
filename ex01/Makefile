##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	my_convert_temp.cpp

INC_PATH =	include

NAME =	my_convert_temp

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