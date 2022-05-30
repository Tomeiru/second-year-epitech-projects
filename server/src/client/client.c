/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** client
*/

#include "teams.h"
#include "cmd_ids.h"

client_t *client_create(int fd, sockaddr_in_t *sockaddr, list_t *list)
{
    client_t *client = safe_malloc(sizeof(client_t));

    client->fd = fd;
    client->quit = false;
    client->logged = true;
    memcpy(&client->sockaddr, sockaddr, sizeof(sockaddr_in_t));
    memset(client->uuid, 0, sizeof(uuid_t));
    push_back(list, client);
    printf("Connection from %s with port %d\n",
    inet_ntoa(sockaddr->sin_addr), htons(sockaddr->sin_port));
    return (client);
}

void client_delete(client_t *client)
{
    close(client->fd);
    free(client);
}

void client_update(client_t *client, server_t *srv)
{
    command_id_t cmd_id = NULL_COMMAND_ID;
    const command_t *cmd;
    char buf[1024];

    puts("Update client !");
    if (read(client->fd, &cmd_id, sizeof(command_id_t)) == 0) {
        client->quit = true;
        return;
    }
    cmd = get_command_from_id(cmd_id);
    printf("Receive cmd %hhu\n", cmd_id);
    if (cmd == NULL || (cmd->size_args
    && (size_t) read(client->fd, buf, cmd->size_args) != cmd->size_args)) {
        client_send_unknown_cmd(client);
        return;
    }
    cmd->fct(client, srv, buf);
}
