/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** pm
*/

#include "teams.h"
#include "logging_server.h"

void send_pm_cmd(client_t *client, save_t *save, void *data)
{
    send_pm_cmd_arg_t *arg = data;

    if (!client_check_logged(client))
        return;
}

void get_pm_cmd(client_t *client, save_t *save, void *data)
{
    get_pm_cmd_arg_t *arg = data;

    if (!client_check_logged(client))
        return;
}
