/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** subscribe
*/

#include "teams.h"
#include "macros.h"
#include "utils.h"

void subscribe_to_team_cmd(client_t *client, server_t *srv, void *data)
{
    subscribe_cmd_arg_t *arg = data;
    team_t *team;
    uuid_node_t *node;

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, srv->save)))
        return;
    if (!does_list_contains_uuid(arg->team_uuid, team->subscribers)) {
        node = safe_malloc(sizeof(uuid_node_t));
        memcpy(node->uuid, client->uuid, sizeof(uuid_t));
        node->next = NULL;
        push_node_back((list_t*) &team->subscribers, (node_t*) node);
        team->subscribers_nb++;
    }
    client_send_success(client, arg->transaction);
}

void unsubscribe_to_team_cmd(client_t *client, server_t *srv, void *data)
{
    unsubscribe_cmd_arg_t *arg = data;
    team_t *team;

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, srv->save)))
        return;
    if (does_list_contains_uuid(arg->team_uuid, team->subscribers)) {
        delete_uuid_from_list(client->uuid, &team->subscribers);
        team->subscribers_nb--;
    }
    client_send_success(client, arg->transaction);
}

void list_subscribed_teams_cmd(client_t *client, server_t *srv, void *data)
{
    list_subscribed_teams_cmd_arg_t *arg = data;
    user_t *user;
    team_t *team;

    if (!check_client_logged(client, arg->transaction))
        return;
    user = get_user_by_uuid(client->uuid, srv->save);
    client_send_success(client, arg->transaction);
    client_send_value(client, user->teams_nb, sizeof(uint));
    for (uuid_list_t lst = user->teams; lst; lst = (uuid_list_t) lst->next) {
        team = get_team_by_uuid(lst->uuid, srv->save);
        client_send_data(client, team->uuid, sizeof(uuid_t));
        client_send_data(client, team->name, MAX_NAME_LENGTH);
        client_send_data(client, team->desc, MAX_BODY_LENGTH);
    }
}

void list_users_subscribed_cmd(client_t *client, server_t *srv, void *data)
{
    list_users_subscribed_to_team_cmd_arg_t *arg = data;
    team_t *team;
    user_t *user;

    if (!check_client_logged(client, arg->transaction)
    || (team = GET_TEAM(client, arg, srv->save)))
        return;
    client_send_success(client, arg->transaction);
    client_send_value(client, team->subscribers_nb, sizeof(uint));
    for (uuid_list_t lst = team->subscribers;
    lst; lst = (uuid_list_t) lst->next) {
        user = get_user_by_uuid(lst->uuid, srv->save);
        client_send_data(client, user->uuid, sizeof(uuid_t));
        client_send_data(client, user->name, MAX_NAME_LENGTH);
    }
}
