/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** list
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static void handle_list_transaction(client_t *client, void *data)
{
    UNUSED(client);
    UNUSED(data);
    puts("[INFO] Lists has successfully been called");
}

static bool list_handler(client_t *client, command_id_t cmd, list_t *transactions)
{
    list_cmd_arg_t cmd_arg;

    memcpy(cmd_arg.team_uuid, client->use->team, 16);
    memcpy(cmd_arg.channel_uuid, client->use->channel, 16);
    memcpy(cmd_arg.thread_uuid, client->use->thread, 16);
    cmd_arg.transaction = transaction_create(NULL,
    handle_list_transaction, NULL, transactions)->id;
    client_send_cmd(client->conn, cmd, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool list_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    UNUSED(av);
    if (ac)
        return (ERROR_CMD);
    for (int i = 0; i < 4; i++)
        if (client->use->state == (use_state_t)i)
            return (list_handler(client, LIST_TEAMS_ID + i, transactions));
    return (ERROR_CMD);
}