/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** login
*/

#include "teams.h"
#include "logging_server.h"


void login_cmd(client_t *client, save_t *save, void *data)
{
    login_cmd_arg_t *arg = data;
}

void logout_cmd(client_t *client, save_t *save, void *data)
{
    if (!client_check_logged(client))
        return;
    client->quit = true;
}
