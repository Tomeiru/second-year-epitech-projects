/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** send
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static bool send_handler(char *user_uuid, char *message_body)
{
    printf("Currently in send function handler with user_uuid \"%s\" and \
    message_body \"%s\"\n", user_uuid, message_body);
    return (SUCCESS_CMD);
}

bool send_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    printf("Currently in send function parser");
    UNUSED(client);
    UNUSED(transactions);
    if (ac != 2)
        return (ERROR_CMD);
    send_handler(av[0], av[1]);
    return (SUCCESS_CMD);
}