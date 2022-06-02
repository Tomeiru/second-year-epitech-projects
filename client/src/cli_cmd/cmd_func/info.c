/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** info
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static bool info_handler(client_t *client, command_id_t cmd, transaction_execute_fct_t func ,list_t *transactions)
{
    list_cmd_arg_t cmd_arg;

    printf("%i\n", (int) cmd);
    memcpy(cmd_arg.team_uuid, client->use->team, 16);
    memcpy(cmd_arg.channel_uuid, client->use->channel, 16);
    memcpy(cmd_arg.thread_uuid, client->use->thread, 16);
    cmd_arg.transaction = transaction_create(NULL,
    func, NULL, transactions)->id;
    client_send_cmd(client->conn, cmd, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool info_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    transaction_execute_fct_t func[4] = {
        handle_info_user_transaction, handle_info_team_transaction,
        handle_info_channel_transaction, handle_info_thread_transaction
    };

    UNUSED(av);
    printf("I'm here %i %i\n", (int)client->use->state, ac);
    if (ac)
        return (ERROR_CMD);
    printf("I'm here %i\n", (int)client->use->state);
    for (int i = 0; i < 4; i++)
        if (client->use->state == (use_state_t)i)
            return (info_handler(client, INFO_CURRENT_USER_ID + i, func[i], transactions));
    return (ERROR_CMD);
}