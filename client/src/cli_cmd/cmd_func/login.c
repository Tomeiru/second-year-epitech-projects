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

static bool login_handler(client_t *client, char *user_name, list_t *transactions)
{
    login_cmd_arg_t cmd_arg;

    cmd_arg.transaction = transaction_create(NULL,
    handle_login_transaction, NULL, transactions)->id;
    strncpy(cmd_arg.name, user_name, MAX_NAME_LENGTH);
    client_send_cmd(client->conn, LOGIN_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool login_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    if (ac != 1 || strlen(av[0]) >= MAX_NAME_LENGTH)
        return (ERROR_CMD);
    return (login_handler(client, av[0], transactions));
}