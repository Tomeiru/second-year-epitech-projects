##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/objdump.c	\
		src/utils.c	\
		src/sixty_four/bfd_flags_sfour.c	\
		src/sixty_four/objdump_sfour.c	\
		src/thirty_two/bfd_flags_ttwo.c	\
		src/thirty_two/objdump_ttwo.c

MAIN =	src/main.c

INC_PATH =	include

NAME =	my_objdump

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
