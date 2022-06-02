/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** list
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static bool list_handler(client_t *client, command_id_t cmd,
transaction_execute_fct_t func, list_t *transactions)
{
    list_cmd_arg_t cmd_arg;

    memcpy(cmd_arg.team_uuid, client->use->team, 16);
    memcpy(cmd_arg.channel_uuid, client->use->channel, 16);
    memcpy(cmd_arg.thread_uuid, client->use->thread, 16);
    cmd_arg.transaction = transaction_create(NULL,
    func, NULL, transactions)->id;
    client_send_cmd(client->conn, cmd, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool list_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    transaction_execute_fct_t func[4] = {
        handle_list_team_transaction, handle_list_channel_transaction,
        handle_list_thread_transaction, handle_list_comment_transaction
    };

    UNUSED(av);
    if (ac)
        return (ERROR_CMD);
    for (int i = 0; i < 4; i++)
        if (client->use->state == (use_state_t)i)
            return (list_handler(client, LIST_TEAMS_ID + i,
            func[i], transactions));
    return (ERROR_CMD);
}