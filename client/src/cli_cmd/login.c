/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** login
*/

#include "cli_teams.h"
#include "cmd_args.h"

static void handle_login_transaction(client_t *client, void *data)
{
    UNUSED(client);
    UNUSED(data);
    puts("[INFO] Logged in !");
}

void login_cli_cmd(client_t *client, int ac, char **av, list_t *transactions)
{
    login_cmd_arg_t cmd_arg;

    if (ac != 1 || strlen(av[0]) >= MAX_NAME_LENGTH)
        return;
    cmd_arg.transaction = transaction_create(NULL,
    handle_login_transaction, NULL, transactions)->id;
    strncpy(cmd_arg.name, av[0], MAX_NAME_LENGTH);
    client_send_cmd(client->conn, LOGIN_ID, &cmd_arg, sizeof(cmd_arg));
}

static void handle_logout_transaction(client_t *client, void *data)
{
    UNUSED(client);
    UNUSED(data);
    puts("[INFO] Logged out !");
}

void logout_cli_cmd(client_t *client, int ac, char **av, list_t *transactions)
{
    logout_cmd_arg_t cmd_arg;

    UNUSED(ac);
    UNUSED(av);
    cmd_arg.transaction = transaction_create(NULL,
    handle_logout_transaction, NULL, transactions)->id;
    client_send_cmd(client->conn, LOGOUT_ID, &cmd_arg, sizeof(cmd_arg));
}
