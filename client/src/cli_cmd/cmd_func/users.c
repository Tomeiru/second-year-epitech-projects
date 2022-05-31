/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** users
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static void handle_users_transaction(client_t *client, void *data)
{
    UNUSED(client);
    UNUSED(data);
    puts("[INFO] Users has successfully been called");
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