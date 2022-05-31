/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** user
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static bool user_handler(char *user_uuid)
{
    printf("Currently in user function handler with user_uuid \"%s\"\n",
    user_uuid);
    return (SUCCESS_CMD);
}

bool user_parse(client_t *client, int ac, char **av, list_t *transactions)
{
    printf("Currently in user function parser");
    UNUSED(client);
    UNUSED(transactions);
    if (ac != 1)
        return (ERROR_CMD);
    return (user_handler(av[0]));
}