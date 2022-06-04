/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** subscribe
*/

#include "teams.h"
#include "macros.h"
#include "utils.h"
#include "logging_server.h"

static void subscribe_user_to_team(client_t *client,
team_t *team, save_t *save)
{
    user_t *user = get_user_by_uuid(client->uuid, save);
    uuid_node_t *node_team = safe_malloc(sizeof(uuid_node_t));
    uuid_node_t *node_user = safe_malloc(sizeof(uuid_node_t));

    memcpy(node_team->uuid, team->uuid, sizeof(uuid_t));
    memcpy(node_user->uuid, client->uuid, sizeof(uuid_t));
    node_team->next = NULL;
    node_user->next = NULL;
    push_node_back((list_t*) &user->teams, (node_t*) node_team);
    push_node_back((list_t*) &team->subscribers, (node_t*) node_user);
    user->teams_nb++;
    team->subscribers_nb++;
    save_infos(save, SAVEFILE_PATH);
}

static void unsubscribe_user_to_team(client_t *client,
team_t *team, save_t *save)
{
    user_t *user = get_user_by_uuid(client->uuid, save);

    delete_uuid_from_list(team->uuid, &user->teams);
    delete_uuid_from_list(client->uuid, &team->subscribers);
    user->teams_nb--;
    team->subscribers_nb--;
    save_infos(save, SAVEFILE_PATH);
}

void subscribe_to_team_cmd(client_t *client, server_t *srv, void *data)
{
    subscribe_cmd_arg_t *arg = data;
    team_t *team;
    char user_uuid[36];
    char team_uuid[36];

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, srv->save)))
        return;
    if (does_list_contains_uuid(client->uuid, team->subscribers))
        return client_send_error(client,
        arg->transaction, ERROR_UNAUTHORIZED, NULL);
    subscribe_user_to_team(client, team, srv->save);
    client_send_success(client, arg->transaction);
    client_send_data(client, team->uuid, sizeof(uuid_t));
    client_send_data(client, client->uuid, sizeof(uuid_t));
    uuid_unparse(arg->team_uuid, team_uuid);
    uuid_unparse(client->uuid, user_uuid);
    server_event_user_subscribed(team_uuid, user_uuid);
}

void unsubscribe_to_team_cmd(client_t *client, server_t *srv, void *data)
{
    unsubscribe_cmd_arg_t *arg = data;
    team_t *team;
    char user_uuid[36];
    char team_uuid[36];

    if (!check_client_logged(client, arg->transaction)
    || !(team = GET_TEAM(client, arg, srv->save)))
        return;
    if (!does_list_contains_uuid(client->uuid, team->subscribers))
        return client_send_error(client,
        arg->transaction, ERROR_UNAUTHORIZED, NULL);
    unsubscribe_user_to_team(client, team, srv->save);
    client_send_success(client, arg->transaction);
    client_send_data(client, team->uuid, sizeof(uuid_t));
    client_send_data(client, client->uuid, sizeof(uuid_t));
    uuid_unparse(arg->team_uuid, team_uuid);
    uuid_unparse(client->uuid, user_uuid);
    server_event_user_unsubscribed(team_uuid, user_uuid);
}
