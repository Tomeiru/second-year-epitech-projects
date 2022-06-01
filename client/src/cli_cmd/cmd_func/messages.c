/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** messages
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"
#include "logging_client.h"

static void handle_messages_transaction(client_t *client, void *data)
{
    size_t nb;
    message_t msg;
    char uuid[36];

    UNUSED(data);
    puts("[INFO] Messages command transaction");
    read(client->conn->socket, &nb, sizeof(size_t));
    for (size_t i = 0; i < nb; i++) {
        read(client->conn->socket, &msg, sizeof(message_t));
        uuid_unparse(msg.uuid, uuid);
        client_private_message_print_messages(uuid, msg.time, msg.msg);
    }
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