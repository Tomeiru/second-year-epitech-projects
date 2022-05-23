/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** pm
*/

#include "teams.h"
#include "logging_server.h"

void send_pm_cmd(client_t *client, server_t *server, void *data)
{
    send_pm_cmd_arg_t *arg = data;

    if (!check_client_logged(client, arg->transaction))
        return;
}

void get_pm_cmd(client_t *client, server_t *server, void *data)
{
    get_pm_cmd_arg_t *arg = data;

    if (!check_client_logged(client, arg->transaction))
        return;
}
