/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** subscribed
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static void handle_subscribed_team_transaction(client_t *client, void *data)
{
    UNUSED(client);
    UNUSED(data);
    puts("[INFO] Subscribed team handle");
}

static bool subscribed_team_handler(client_t *client, list_t *transactions)
{
    list_subscribed_teams_cmd_arg_t cmd_arg;

    cmd_arg.transaction = transaction_create(NULL,
    handle_subscribed_team_transaction, NULL, transactions)->id;
    client_send_cmd(client->conn, LIST_SUBSCRIBED_TEAMS_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

static bool subscribed_user_handler(client_t *client, char *team_uuid, list_t *transactions)
{
    list_users_subscribed_to_team_cmd_arg_t cmd_arg;
    uuid_t team;

    memset(team, 0, 16);
    if (uuid_parse(team_uuid, team))
        return (ERROR_CMD);
    cmd_arg.transaction = transaction_create(NULL,
    handle_subscribed_team_transaction, NULL, transactions)->id;
    memcpy(cmd_arg.team_uuid, team, 16);
    client_send_cmd(client->conn, LIST_USERS_SUBSCRIBED_TO_TEAM_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool subscribed_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    if (!ac)
        return (subscribed_team_handler(client, transactions));
    if (ac == 1)
        return (subscribed_user_handler(client, av[0], transactions));
    return (ERROR_CMD);
}