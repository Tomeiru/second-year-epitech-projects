/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** subscribe
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static bool subscribe_handler(char *team_uuid)
{
    printf("Currently in subscribe function handler with team_uuid \"%s\"\n",
    team_uuid);
    return (SUCCESS_CMD);
}

bool subscribe_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    printf("Currently in subscribe function parser");
    UNUSED(client);
    UNUSED(transactions);
    if (ac != 1)
        return (ERROR_CMD);
    return (subscribe_handler(av[0]));
}