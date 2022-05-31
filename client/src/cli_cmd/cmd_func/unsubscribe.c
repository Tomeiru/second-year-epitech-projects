/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** unsubscribe
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static bool unsubscribe_handler(char *team_uuid)
{
    printf("Currently in unsubscribe function handler with team_uuid \"%s\"\n",
    team_uuid);
    return (SUCCESS_CMD);
}

bool unsubscribe_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    printf("Currently in unsubscribe function parser");
    UNUSED(client);
    UNUSED(av);
    UNUSED(transactions);
    if (ac != 1)
        return (ERROR_CMD);
    unsubscribe_handler(av[0]);
    return (SUCCESS_CMD);
}