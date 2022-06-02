/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** create
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"
#include "logging_client.h"

static bool create_comment(client_t *client, char *comment_body,
list_t *transactions)
{
    create_comment_cmd_arg_t cmd_arg;

    memcpy(cmd_arg.team_uuid, client->use->team, 16);
    memcpy(cmd_arg.channel_uuid, client->use->channel, 16);
    memcpy(cmd_arg.thread_uuid, client->use->thread, 16);
    memset(cmd_arg.comment, 0, MAX_BODY_LENGTH);
    cmd_arg.transaction = transaction_create(NULL,
    handle_create_comment_transaction, NULL, transactions)->id;
    strcpy(cmd_arg.comment, comment_body);
    client_send_cmd(client->conn, CREATE_COMMENT_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

static bool create_thread(client_t *client, char *thread_title,
char *thread_message, list_t *transactions)
{
    create_thread_cmd_arg_t cmd_arg;

    memcpy(cmd_arg.team_uuid, client->use->team, 16);
    memcpy(cmd_arg.channel_uuid, client->use->channel, 16);
    memset(cmd_arg.title, 0, MAX_NAME_LENGTH);
    memset(cmd_arg.msg, 0, MAX_BODY_LENGTH);
    cmd_arg.transaction = transaction_create(NULL,
    handle_create_thread_transaction, NULL, transactions)->id;
    strcpy(cmd_arg.title, thread_title);
    strcpy(cmd_arg.msg, thread_message);
    client_send_cmd(client->conn, CREATE_THREAD_ID, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

static bool create_channel_team(client_t *client, char **av, command_id_t cmd,
list_t *transactions)
{
    create_team_channel_cmd_arg_t cmd_arg;

    memcpy(cmd_arg.team_uuid, client->use->team, 16);
    memset(cmd_arg.name, 0, MAX_NAME_LENGTH);
    memset(cmd_arg.desc, 0, MAX_DESCRIPTION_LENGTH);
    cmd_arg.transaction = transaction_create(NULL,
    cmd == CREATE_TEAM_ID ? handle_create_team_transaction :
    handle_create_channel_transaction, NULL, transactions)->id;
    strcpy(cmd_arg.name, av[0]);
    strcpy(cmd_arg.desc, av[1]);
    client_send_cmd(client->conn, cmd, &cmd_arg, sizeof(cmd_arg));
    return (SUCCESS_CMD);
}

bool create_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    if (!ac || ac > 2)
        return (ERROR_CMD);
    if (client->use->state == THREAD_USE_STATE) {
        if (ac != 1 || strlen(av[0]) >= MAX_BODY_LENGTH)
            return (ERROR_CMD);
        return (create_comment(client, av[0], transactions));
    }if (ac != 2)
        return (ERROR_CMD);
    if (client->use->state == CHANNEL_USE_STATE) {
        if (strlen(av[0]) >= MAX_NAME_LENGTH || strlen(av[1]) >=
        MAX_BODY_LENGTH)
            return (ERROR_CMD);
        return (create_thread(client, av[0], av[1], transactions));
    }
    if (strlen(av[0]) >= MAX_NAME_LENGTH || strlen(av[1]) >=
    MAX_DESCRIPTION_LENGTH)
        return (ERROR_CMD);
    for (int i = 0; i < 2; i++)
        if (client->use->state == (use_state_t)i)
            return (create_channel_team(client, av, CREATE_TEAM_ID + i,
            transactions));
    return (SUCCESS_CMD);
}