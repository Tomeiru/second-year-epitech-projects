##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC =	src/check_and_get_args.c	\
		src/client_loop.c	\
		src/connect_func.c	\
		src/delete_func.c	\
		src/list_manip.c	\
		src/myftp.c	\
		src/no_effect_func.c	\
		src/parse_port_args.c	\
		src/pass_act_func.c	\
		src/transfer_func.c	\
		src/utils.c	\
		src/wd_func.c

MAIN =	src/main.c

INC_PATH =	include

NAME =	myftp

OBJ = 	$(SRC:.c=.o)

OBJMAIN = 	$(MAIN:.c=.o)

CFLAGS = -I. -I$(INC_PATH) -Wall -Wextra -g

$(NAME):	$(OBJ)	$(OBJMAIN)
		@gcc -o $(NAME) $(OBJ) $(OBJMAIN) $(CFLAGS)

all:	$(NAME)

clean:
		rm -f $(OBJ) $(OBJMAIN)

fclean:	clean
		rm -fr $(NAME)

re:	fclean all
