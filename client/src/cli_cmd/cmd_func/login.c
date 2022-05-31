/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** login
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static void handle_login_transaction(client_t *client, void *data)
{
    UNUSED(client);
    UNUSED(data);
    puts("[INFO] Logged in !");
}

bool login_cli_cmd(client_t *client, int ac, char **av, list_t *transactions)
{
    login_cmd_arg_t cmd_arg;

    if (ac != 1 || strlen(av[0]) >= MAX_NAME_LENGTH)
        return (ERROR_CMD);
    cmd_arg.transaction = transaction_create(NULL,
    handle_login_transaction, NULL, transactions)->id;
    strncpy(cmd_arg.name, av[0], MAX_NAME_LENGTH);
    client_send_cmd(client->conn, LOGIN_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}