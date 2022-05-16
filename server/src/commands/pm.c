/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** pm
*/

#include "teams.h"

void send_pm_cmd(client_t *client, server_t *srv, void *data)
{
    if (!client_check_logged(client))
        return;
}

void get_pm_cmd(client_t *client, server_t *srv, void *data)
{
    if (!client_check_logged(client))
        return;
}
