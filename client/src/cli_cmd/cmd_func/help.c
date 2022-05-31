/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** help
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static bool help_handler(void)
{
    printf("Successfully called help function");
    return (SUCCESS_CMD);
}

bool help_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    printf("Currently in help function parser");
    UNUSED(client);
    UNUSED(av);
    UNUSED(transactions);
    if (ac)
        return (ERROR_CMD);
    return (help_handler());
}