/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** send
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static void handle_send_transaction(client_t *client, void *data)
{
    UNUSED(client);
    UNUSED(data);
    puts("[INFO] Send command transaction");
}

static bool send_handler(client_t *client, char *user_uuid, char *message_body,
list_t *transactions)
{
    send_pm_cmd_arg_t cmd_arg;
    uuid_t user;

    memset(user, 0, 16);
    memset(cmd_arg.msg, 0, MAX_BODY_LENGTH);
    if (uuid_parse(user_uuid, user))
        return (ERROR_CMD);
    cmd_arg.transaction = transaction_create(NULL,
    handle_send_transaction, NULL, transactions)->id;
    memcpy(cmd_arg.user_uuid, user, 16);
    memcpy(cmd_arg.msg, message_body, MAX_BODY_LENGTH);
    client_send_cmd(client->conn, SEND_PM_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool send_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    if (ac != 2 || strlen(av[1]) >= MAX_BODY_LENGTH)
        return (ERROR_CMD);
    send_handler(client, av[0], av[1], transactions);
    return (SUCCESS_CMD);
}