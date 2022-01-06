##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	DoOp.hs

NAME =	doop

$(NAME):	$(SRC)
		@ghc $(SRC) -o $(NAME)

all:	$(NAME)

clean:	
		rm -fr *.hi
		rm -fr *.o

fclean:	clean
		rm -fr $(NAME)

re:	fclean all