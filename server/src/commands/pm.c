/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** pm
*/

#include "teams.h"
#include "logging_server.h"

static void event_private_message_sended(client_t *sender,
uuid_t receiver, char *msg, server_t *srv)
{
    client_t *client = get_connected_client(receiver, srv);
    char sender_str[36];
    char receiver_str[36];

    uuid_unparse(sender->uuid, sender_str);
    uuid_unparse(receiver, receiver_str);
    server_event_private_message_sended(sender_str, receiver_str, msg);
    if (client) {
        client_send_value(client, EVENT_PM_RECEIVED_ID, sizeof(command_id_t));
        client_send_data(client, sender->uuid, sizeof(uuid_t));
        client_send_data(client, msg, MAX_BODY_LENGTH);
    }
}

void send_pm_cmd(client_t *client, server_t *srv, void *data)
{
    send_pm_cmd_arg_t *arg = data;
    discussion_t *discussion;

    if (!check_client_logged(client, arg->transaction)
    || !get_user_or_error(client, arg->user_uuid, srv->save, arg->transaction))
        return;
    if (!(discussion = get_discussion_by_user_uuids(client->uuid,
    arg->user_uuid, srv->save)))
        discussion = discussion_create(client->uuid, arg->user_uuid, srv->save);
    message_create(client->uuid, arg->msg, discussion);
    client_send_success(client, arg->transaction);
    event_private_message_sended(client, arg->user_uuid, arg->msg, srv);
    save_infos(srv->save, SAVEFILE_PATH);
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
