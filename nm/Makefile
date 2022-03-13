##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/nm_func.c	\
		src/utils.c	\
		src/sixty_four/nm_sfour.c	\
		src/sixty_four/determine_flag_sfour.c	\
		src/sixty_four/create_sort_list_sfour.c	\
		src/thirty_two/nm_ttwo.c	\
		src/thirty_two/determine_flag_ttwo.c	\
		src/thirty_two/create_sort_list_ttwo.c

MAIN =	src/main.c

INC_PATH =	include

NAME =	my_nm

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)
		mv $(NAME) ../

all:	$(NAME)

clean:
		rm -f $(OBJ) $(OBJMAIN)

fclean:	clean
		rm -fr ../$(NAME)

re:	fclean all
