/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** utils
*/

#include "teams.h"

const command_t *get_command_from_id(command_id_t id)
{
    for (int i = 0; i < COMMANDS_NB; i++) {
        if (COMMANDS[i].id == id)
            return &COMMANDS[i];
    }
    return NULL;
}

bool check_client_logged(client_t *client, uint64_t transation)
{
    if (!client->logged) {
        client_send_error(client, transation, ERROR_UNAUTHORIZED, NULL);
        return false;
    }
    return true;
}

bool check_user_belongs_to_team(client_t *client, team_t *team, uint64_t transation, bool throw)
{
    uuid_t user;

    memset(user, 0, 16);
    for (uuid_list_t list = team->subscribers; list; list = list->next) {
        memcpy(user, list->uuid, 16);
        if (!uuid_compare(user, client->uuid))
            return (true);
    }
    if (throw)
        client_send_error(client, transation, ERROR_UNAUTHORIZED, NULL);
    return (false);
}
