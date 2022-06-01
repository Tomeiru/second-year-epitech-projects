/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** subscribed
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"
#include "logging_client.h"

static void handle_subscribed_teams_transaction(client_t *client, void *data)
{
    size_t nb;
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    char uuid_str[36];

    UNUSED(data);
    puts("[INFO] Subscribed teams handle");
    read(client->conn->socket, &nb, sizeof(size_t));
    for (size_t i = 0; i < nb; i++) {
        read(client->conn->socket, uuid, sizeof(uuid_t));
        read(client->conn->socket, name, MAX_NAME_LENGTH);
        read(client->conn->socket, desc, MAX_DESCRIPTION_LENGTH);
        uuid_unparse(uuid, uuid_str);
        client_print_teams(uuid_str, name, desc);
    }
}

static void handle_subscribed_users_transaction(client_t *client, void *data)
{
    size_t nb;
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    size_t connected;
    char uuid_str[36];

    UNUSED(data);
    puts("[INFO] Subscribed users handle");
    read(client->conn->socket, &nb, sizeof(size_t));
    for (size_t i = 0; i < nb; i++) {
        read(client->conn->socket, uuid, sizeof(uuid_t));
        read(client->conn->socket, name, MAX_NAME_LENGTH);
        read(client->conn->socket, &connected, sizeof(size_t));
        uuid_unparse(uuid, uuid_str);
        client_print_users(uuid_str, name, connected);
    }
}

static bool subscribed_teams_handler(client_t *client, list_t *transactions)
{
    list_subscribed_teams_cmd_arg_t cmd_arg;

    cmd_arg.transaction = transaction_create(NULL,
    handle_subscribed_teams_transaction, NULL, transactions)->id;
    client_send_cmd(client->conn,
    LIST_SUBSCRIBED_TEAMS_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

static bool subscribed_users_handler(client_t *client,
char *team_uuid, list_t *transactions)
{
    list_users_subscribed_to_team_cmd_arg_t cmd_arg;
    uuid_t team;

    memset(team, 0, 16);
    if (uuid_parse(team_uuid, team))
        return (ERROR_CMD);
    cmd_arg.transaction = transaction_create(NULL,
    handle_subscribed_users_transaction, NULL, transactions)->id;
    memcpy(cmd_arg.team_uuid, team, 16);
    client_send_cmd(client->conn,
    LIST_USERS_SUBSCRIBED_TO_TEAM_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool subscribed_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    if (!ac)
        return (subscribed_teams_handler(client, transactions));
    if (ac == 1)
        return (subscribed_users_handler(client, av[0], transactions));
    return (ERROR_CMD);
}
