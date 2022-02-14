##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	201yams.hs

NAME =	201yams

$(NAME):	$(SRC)
		@ghc $(SRC) -o $(NAME)

all:	$(NAME)

clean:
		rm -fr *.hi
		rm -fr *.o

fclean:	clean
		rm -fr $(NAME)

re:	fclean all