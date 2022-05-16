/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** responses
*/

#include "teams.h"
#include "responses.h"

void client_send_error(client_t *client, char *msg)
{
    response_t response = ERROR_OCCURED;

    client_send_value(client, response, sizeof(response_t));
    client_send_array(client, msg, sizeof(char), strlen(msg));
}

void client_send_unknown_cmd(client_t *client)
{
    response_t response = UNKNOWN_COMMAND;

    client_send_value(client, response, sizeof(response_t));
}
