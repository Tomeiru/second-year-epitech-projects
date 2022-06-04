/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** parser
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "utils.h"

int read_command(client_t *client)
{
    char c = 0;
    int len = 0;

    len = read(0, &c, 1);
    if (len <= 0)
        return (0);
    if (c == '\n') {
        if (client->len_command)
            client->command[client->len_command] = '\0';
        return (1);
    }
    if (client->len_command) {
        client->command = realloc(client->command, ++(client->len_command) + 1);
        client->command[client->len_command - 1] = c;
        return (-1);
    }
    client->len_command = 1;
    client->command = malloc(sizeof(char) * 2);
    client->command[client->len_command - 1] = c;
    return (-1);
}

bool handle_user_cmd(client_t *client, list_t *transactions)
{
    int done = read_command(client);
    char **command = NULL;
    int arg_num = 0;

    if (!done)
        return (TEAMS_EOF);
    if (done == -1)
        return (ERROR_CMD);
    command = teams_cl_to_arr(client->command);
    free(client->command);
    client->command = NULL;
    client->len_command = 0;
    if (command == NULL)
        return (ERROR_CMD);
    arg_num = get_len_array(command, sizeof(char *)) - 1;
    for (int i = 0; i < CLI_CMD_NB; i++)
        if (!strcmp(command[0], CLI_CMDS[i].name))
            return (CLI_CMDS[i].execute(client, arg_num, !arg_num ?
            NULL : command + 1, transactions));
    return (SUCCESS_CMD);
}
