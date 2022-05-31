/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** messages
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static bool messages_handler(char *user_uuid)
{
    printf("Currently in messages function handler with user_uuid \"%s\"\n",
    user_uuid);
    return (SUCCESS_CMD);
}

bool messages_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    printf("Currently in messages function parser");
    UNUSED(client);
    UNUSED(transactions);
    if (ac != 1)
        return (ERROR_CMD);
    messages_handler(av[0]);
    return (SUCCESS_CMD);
}