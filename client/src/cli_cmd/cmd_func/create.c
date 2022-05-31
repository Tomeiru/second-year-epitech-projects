/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** create
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

bool create_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    printf("Currently in create function parser\n");
    if (!ac)
        return (ERROR_CMD);
    UNUSED(client);
    UNUSED(ac);
    UNUSED(av);
    UNUSED(transactions);
    return (SUCCESS_CMD);
}