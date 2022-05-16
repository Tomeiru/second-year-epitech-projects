/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** create
*/

#include "teams.h"

void create_team_cmd(client_t *client, server_t *srv, void *data)
{
    if (!client_check_logged(client))
        return;
}

void create_channel_cmd(client_t *client, server_t *srv, void *data)
{
    if (!client_check_logged(client))
        return;
}

void create_thread_cmd(client_t *client, server_t *srv, void *data)
{
    if (!client_check_logged(client))
        return;
}

void create_comment_cmd(client_t *client, server_t *srv, void *data)
{
    if (!client_check_logged(client))
        return;
}
