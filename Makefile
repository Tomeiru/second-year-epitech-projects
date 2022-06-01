##
## EPITECH PROJECT, 2022
## teams
## File description:
## Makefile
##

SRC_COMMON		=	common/src/adding_list.c							\
					common/src/delete_list.c							\
					common/src/safe_malloc.c							\
					common/src/teams_cl_to_arr.c						\
					common/src/utils_teams_cl_to_arr.c					\
					common/src/utils.c

SRC_SRV			=	server/src/main.c 									\
					server/src/server.c 								\
					server/src/server_utils.c 							\
					server/src/client/client.c 							\
					server/src/client/send.c	 						\
					server/src/client/responses.c 						\
					server/src/transactions/create.c					\
					server/src/commands/cmd_list.c						\
					server/src/commands/login.c							\
					server/src/commands/create.c						\
					server/src/commands/pm.c							\
					server/src/commands/subscribe.c						\
					server/src/commands/utils.c							\
					server/src/commands/get_or_error.c					\
					server/src/events/create.c							\
					server/src/events/login.c							\
					server/src/save/save.c	 							\
					server/src/save/save_teams.c						\
					server/src/save/load.c	 							\
					server/src/save/load_teams.c						\
					server/src/save/create.c							\
					server/src/save/create_teams.c						\
					server/src/save/find.c								\
					server/src/save/find_teams.c						\
					server/src/save/destroy.c

SRC_CLI			=	client/src/main.c									\
					client/src/transaction.c							\
					client/src/cli_cmd/parser.c							\
					client/src/cli_cmd/cmd_list.c						\
					client/src/cli_cmd/utils.c							\
					client/src/cli_cmd/cmd_func/create_transaction.c	\
					client/src/cli_cmd/cmd_func/create.c				\
					client/src/cli_cmd/cmd_func/help.c					\
					client/src/cli_cmd/cmd_func/info.c					\
					client/src/cli_cmd/cmd_func/list.c					\
					client/src/cli_cmd/cmd_func/login.c					\
					client/src/cli_cmd/cmd_func/logout.c				\
					client/src/cli_cmd/cmd_func/messages.c				\
					client/src/cli_cmd/cmd_func/send.c					\
					client/src/cli_cmd/cmd_func/subscribe.c				\
					client/src/cli_cmd/cmd_func/unsubscribe.c			\
					client/src/cli_cmd/cmd_func/subscribed.c			\
					client/src/cli_cmd/cmd_func/use.c					\
					client/src/cli_cmd/cmd_func/user.c					\
					client/src/cli_cmd/cmd_func/users.c					\
					client/src/serv_cmd/server.c						\
					client/src/serv_cmd/cmd_list.c						\
					client/src/serv_cmd/login.c							\
					client/src/serv_cmd/create.c						\
					client/src/serv_cmd/pm_reply.c

INC_COMMON		=	common/include
INC_SRV			=	server/include
INC_CLI			=	client/include
INC_LIB			=	libs/myteams

OBJ_COMMON		=	$(SRC_COMMON:.c=.o)
OBJ_SRV			=	$(SRC_SRV:.c=.o)
OBJ_CLI			=	$(SRC_CLI:.c=.o)

LIB_DIR			=	libs/myteams
LIB_NAME		=	myteams

NAME_SRV		=	myteams_server
NAME_CLI		=	myteams_cli

CFLAGS			+=	-W -Wall -L$(LIB_DIR) -l$(LIB_NAME) -luuid

all: server client

server: CFLAGS += -I$(INC_SRV) -I$(INC_COMMON) -I$(INC_LIB)
server: $(NAME_SRV)

client: CFLAGS += -I$(INC_CLI) -I$(INC_COMMON) -I$(INC_LIB)
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
