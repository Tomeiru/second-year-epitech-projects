##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/panoramix.c

MAIN =	src/main.c

INC_PATH =	include

NAME =	panoramix

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS) -lpthread

all:	$(NAME)

clean:
		rm -f $(OBJ) $(OBJMAIN)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
