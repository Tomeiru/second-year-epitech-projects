##
## EPITECH PROJECT, 2022
## teams
## File description:
## Makefile
##

SRC_SRV			=	server/src/main.c 			\
					server/src/adding_list.c	\
					server/src/delete_list.c 	\
					server/src/my_teams.c 		\

INC_SRV			=	server/include

OBJ_SRV			=	$(SRC_SRV:.c=.o)

NAME_SRV		=	myteams_server

SRC_CLI			=	client/src/main.c 	\

INC_CLI			=	nm/include

OBJ_CLI			=	$(SRC_CLI:.c=.o)

NAME_CLI		=	myteams_cli

CFLAGS			+=	-W -Wall

all: server client

server: CFLAGS += -I$(INC_SRV)
server: $(NAME_SRV)

client: CFLAGS += -I$(INC_CLI)
client: $(NAME_CLI)

$(NAME_SRV): $(OBJ_SRV)
	gcc $(CFLAGS) -o $(NAME_SRV) $(OBJ_SRV)

$(NAME_CLI): $(OBJ_CLI)
	gcc $(CFLAGS) -o $(NAME_CLI) $(OBJ_CLI)

debug: CFLAGS += -g
debug: re

clean:
	rm -f $(OBJ_SRV)
	rm -f $(OBJ_CLI)

fclean: clean
	rm -f $(NAME_SRV)
	rm -f $(NAME_CLI)

re: fclean all

.PHONY: all nm objdump debug clean fclean