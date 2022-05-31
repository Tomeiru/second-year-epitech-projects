/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** messages
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static void handle_messages_transaction(client_t *client, void *data)
{
    UNUSED(client);
    UNUSED(data);
    puts("[INFO] Messags command transaction");
}

static bool messages_handler(client_t *client, char *user_uuid, list_t *transactions)
{
    get_pm_cmd_arg_t cmd_arg;
    uuid_t user;

    memset(user, 0, 16);
    if (uuid_parse(user_uuid, user))
        return (ERROR_CMD);
    cmd_arg.transaction = transaction_create(NULL,
    handle_messages_transaction, NULL, transactions)->id;
    memcpy(cmd_arg.user_uuid, user, 16);
    client_send_cmd(client->conn, GET_PMS_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool messages_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    if (ac != 1)
        return (ERROR_CMD);
    return (messages_handler(client, av[0], transactions));
}