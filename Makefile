##
## EPITECH PROJECT, 2022
## teams
## File description:
## Makefile
##

SRC_COMMON		=	common/src/adding_list.c		\
					common/src/delete_list.c		\
					common/src/safe_malloc.c

SRC_SRV			=	server/src/main.c 				\
					server/src/server.c 			\
					server/src/server_utils.c 		\
					server/src/client.c 			\
					server/src/utils.c				\
					server/src/commands/list.c		\
					server/src/commands/login.c		\
					server/src/commands/create.c	\
					server/src/commands/pm.c		\
					server/src/commands/utils.c

SRC_CLI			=	client/src/main.c

INC_COMMON		=	common/include
INC_SRV			=	server/include
INC_CLI			=	nm/include

OBJ_COMMON		=	$(SRC_COMMON:.c=.o)
OBJ_SRV			=	$(SRC_SRV:.c=.o)
OBJ_CLI			=	$(SRC_CLI:.c=.o)

NAME_SRV		=	myteams_server
NAME_CLI		=	myteams_cli

CFLAGS			+=	-W -Wall

all: server client

server: CFLAGS += -I$(INC_SRV) -I$(INC_COMMON)
server: $(NAME_SRV)

client: CFLAGS += -I$(INC_CLI) -I$(INC_COMMON)
client: $(NAME_CLI)

$(NAME_SRV): $(OBJ_COMMON) $(OBJ_SRV)
	gcc $(CFLAGS) -o $(NAME_SRV) $(OBJ_COMMON) $(OBJ_SRV)

$(NAME_CLI): $(OBJ_COMMON) $(OBJ_CLI)
	gcc $(CFLAGS) -o $(NAME_CLI) $(OBJ_COMMON) $(OBJ_CLI)

debug: CFLAGS += -g
debug: re

clean:
	rm -f $(OBJ_COMMON)
	rm -f $(OBJ_SRV)
	rm -f $(OBJ_CLI)

fclean: clean
	rm -f $(NAME_SRV)
	rm -f $(NAME_CLI)

re: fclean all

.PHONY: all nm objdump debug clean fclean
