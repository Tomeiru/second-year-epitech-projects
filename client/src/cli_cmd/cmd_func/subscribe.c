/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** subscribe
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static void handle_subscribe_transaction(client_t *client, void *data)
{
    UNUSED(client);
    UNUSED(data);
    puts("[INFO] Subscribe command transaction");
}

static bool subscribe_handler(client_t *client, char *team_uuid, list_t *transactions)
{
    subscribe_cmd_arg_t cmd_arg;
    uuid_t team;

    memset(team, 0, 16);
    if (uuid_parse(team_uuid, team))
        return (ERROR_CMD);
    cmd_arg.transaction = transaction_create(NULL,
    handle_subscribe_transaction, NULL, transactions)->id;
    memcpy(cmd_arg.team_uuid, team, 16);
    client_send_cmd(client->conn, SUBSCRIBE_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool subscribe_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    if (ac != 1)
        return (ERROR_CMD);
    return (subscribe_handler(client, av[0], transactions));
}