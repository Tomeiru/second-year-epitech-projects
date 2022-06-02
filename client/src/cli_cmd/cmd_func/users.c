/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** users
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"
#include "logging_client.h"

static void handle_users_transaction(client_t *client, void *data)
{
    size_t nb;
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    size_t connected;
    char uuid_str[36];

    UNUSED(data);
    puts("[INFO] Users has successfully been called");
    read(client->conn->socket, &nb, sizeof(size_t));
    for (size_t i = 0; i < nb; i++) {
        read(client->conn->socket, uuid, sizeof(uuid_t));
        read(client->conn->socket, name, MAX_NAME_LENGTH);
        read(client->conn->socket, &connected, sizeof(size_t));
        uuid_unparse(uuid, uuid_str);
        client_print_users(uuid_str, name, connected);
    }
}

static bool users_handler(client_t *client, list_t *transactions)
{
    list_users_cmd_arg_t cmd_arg;

    cmd_arg.transaction = transaction_create(NULL,
    handle_users_transaction, NULL, transactions)->id;
    client_send_cmd(client->conn, LIST_USERS_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool users_parse(client_t *client, int ac, char **av, list_t *transactions)
{
    UNUSED(av);
    if (ac)
        return (ERROR_CMD);
    return (users_handler(client, transactions));
}