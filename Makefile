##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	pushSwapChecker.hs

NAME =	pushswap_checker

$(NAME):	$(SRC)
		@ghc $(SRC) -o $(NAME)

all:	$(NAME)

clean:	
		rm -fr *.hi
		rm -fr *.o

fclean:	clean
		rm -fr $(NAME)

re:	fclean all

test: re
		./bonus/tests.sh