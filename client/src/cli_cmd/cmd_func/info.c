/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** info
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

bool info_parser(client_t *client, int ac, char **av, list_t *transactions)
{
    printf("Currently in info function parser");
    UNUSED(client);
    UNUSED(ac);
    UNUSED(av);
    UNUSED(transactions);
    return (SUCCESS_CMD);
}