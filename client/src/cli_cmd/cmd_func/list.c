/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** list
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

bool list_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    printf("Currently in list function parser");
    UNUSED(client);
    UNUSED(ac);
    UNUSED(av);
    UNUSED(transactions);
    return (SUCCESS_CMD);
}