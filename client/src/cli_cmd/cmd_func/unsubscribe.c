/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** unsubscribe
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"
#include "logging_client.h"

static void handle_unsubscribe_transaction(client_t *client, void *data)
{
    uuid_t team_uuid;
    uuid_t user_uuid;
    char user_uuid_str[36];
    char team_uuid_str[36];

    UNUSED(data);
    puts("[INFO] Unsubscribe command transaction");
    read(client->conn->socket, team_uuid, sizeof(uuid_t));
    read(client->conn->socket, user_uuid, sizeof(uuid_t));
    uuid_unparse(team_uuid, team_uuid_str);
    uuid_unparse(user_uuid, user_uuid_str);
    client_print_unsubscribed(user_uuid_str, team_uuid_str);
}

static bool unsubscribe_handler(client_t *client, char *team_uuid,
list_t *transactions)
{
    unsubscribe_cmd_arg_t cmd_arg;
    uuid_t team;

    memset(team, 0, 16);
    if (uuid_parse(team_uuid, team))
        return (ERROR_CMD);
    cmd_arg.transaction = transaction_create(NULL,
    handle_unsubscribe_transaction, NULL, transactions)->id;
    memcpy(cmd_arg.team_uuid, team, 16);
    client_send_cmd(client->conn, UNSUBSCRIBE_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool unsubscribe_parser(client_t *client, int ac, char **av,
list_t *transactions)
{
    if (ac != 1)
        return (ERROR_CMD);
    return (unsubscribe_handler(client, av[0], transactions));
}