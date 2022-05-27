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
