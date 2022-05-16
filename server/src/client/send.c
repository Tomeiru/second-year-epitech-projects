/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** responses
*/

#include "teams.h"

void client_send_array(client_t *client, void *data, size_t size, size_t n)
{
    write(client->fd, &n, sizeof(size_t));
    write(client->fd, data, size * n);
}

void client_send_linked_list(client_t *client, list_t list, size_t size)
{
    size_t len = node_len(list);

    write(client->fd, &len, sizeof(size_t));
    for (list_t cpy = list; cpy; cpy = cpy->next)
        write(client->fd, cpy->data, size);
}

void client_send_data(client_t *client, void *data, size_t size)
{
    write(client->fd, data, size);
}

void client_send_value(client_t *client, size_t value, size_t size)
{
    write(client->fd, &value, size);
}
