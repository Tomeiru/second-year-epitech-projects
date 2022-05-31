/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** users
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static bool users_handler(void)
{
    printf("Currently in users function handler");
    return (SUCCESS_CMD);
}

bool users_parse(client_t *client, int ac, char **av, list_t *transactions)
{
    printf("Currently in users function parser");
    UNUSED(client);
    UNUSED(av);
    UNUSED(transactions);
    if (ac)
        return (ERROR_CMD);
    return (users_handler());
}