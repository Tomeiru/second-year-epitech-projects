/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** utils
*/

#include "cli_teams.h"

void client_send_cmd_id(conn_t *conn, command_id_t cmd)
{
    write(conn->socket, &cmd, sizeof(command_id_t));
}

void client_send_data(conn_t *conn, void *data, size_t size)
{
    write(conn->socket, data, size);
}

void client_send_cmd(conn_t *conn, command_id_t cmd, void *data, size_t size)
{
    client_send_cmd_id(conn, cmd);
    client_send_data(conn, data, size);
}
