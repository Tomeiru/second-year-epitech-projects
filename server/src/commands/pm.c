/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** pm
*/

#include "teams.h"
#include "logging_server.h"

void send_pm_cmd(client_t *client, server_t *srv, void *data)
{
    send_pm_cmd_arg_t *arg = data;
    discussion_t *discussion;
    char uuids[36 * 2];

    if (!check_client_logged(client, arg->transaction)
    || !get_user_or_error(client, arg->user_uuid, srv->save, arg->transaction))
        return;
    if (!(discussion = get_discussion_by_user_uuids(client->uuid,
    arg->user_uuid, srv->save)))
        discussion = discussion_create(client->uuid, arg->user_uuid, srv->save);
    message_create(client->uuid, arg->msg, discussion);
    uuid_unparse(client->uuid, uuids);
    uuid_unparse(arg->user_uuid, uuids + 36);
    server_event_private_message_sended(uuids, uuids + 36, arg->msg);
    client_send_success(client, arg->transaction);
}

void get_pm_cmd(client_t *client, server_t *srv, void *data)
{
    get_pm_cmd_arg_t *arg = data;
    discussion_t *disc;

    if (!check_client_logged(client, arg->transaction)
    || !get_user_or_error(client, arg->user_uuid, srv->save, arg->transaction))
        return;
    disc = get_discussion_by_user_uuids(client->uuid,
    arg->user_uuid, srv->save);
    client_send_success(client, arg->transaction);
    if (disc)
        client_send_linked_list(client, disc->messages, sizeof(message_t));
    else
        client_send_linked_list(client, NULL, sizeof(message_t));
}
