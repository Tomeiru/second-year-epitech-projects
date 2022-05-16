/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** utils
*/

#include "teams.h"

bool client_check_logged(client_t *client)
{
    if (!client->logged) {
        client_send_error(client, "Not logged.");
        return true;
    }
    return false;
}
