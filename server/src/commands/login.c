/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** login
*/

#include "teams.h"

void login_cmd(client_t *client, server_t *srv, void *data)
{

}

void logout_cmd(client_t *client, server_t *srv, void *data)
{
    if (!client_check_logged(client))
        return;
    client->quit = true;
}
