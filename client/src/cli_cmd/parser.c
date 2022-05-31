/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** parser
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "utils.h"

static char **get_command(int *len)
{
    char input[1024];

    memset(input, 0, 1024);
    *len = read(0, input, 1023);
    if (*len == 0)
        return (NULL);
    input[*len - 1] = '\0';
    return (teams_cl_to_arr(input));
}

bool handle_user_cmd(client_t *client, list_t *transactions)
{
    int len = 0;
    char **command = get_command(&len);
    int arg_num = 0;

    if (len == 0)
        return (TEAMS_EOF);
    if (command == NULL)
        return (ERROR_CMD);
    arg_num = get_len_array(command, sizeof(char *)) - 1;
    for (int i = 0; i < CLI_CMD_NB; i++)
        if (!strcmp(command[0], CLI_CMDS[i].name))
            return (CLI_CMDS[i].execute(client, arg_num, !arg_num ?
            NULL : command + 1, transactions));
    return (SUCCESS_CMD);
}
