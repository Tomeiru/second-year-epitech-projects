/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** server
*/

#include "cli_teams.h"
#include "logging_client.h"
#include "safe_malloc.h"
#include "transaction.h"
#include "utils.h"
#include "responses.h"
#include "cmd_ids.h"
#include "server_cmds.h"

static void log_error(error_t error, char uuid[36])
{
    switch (error) {
        case ERROR_ALREADY_EXISTS:
        client_error_already_exist();
        break;
        case ERROR_UNAUTHORIZED:
        client_error_unauthorized();
        break;
        case ERROR_UNKNOWN_TEAM:
        client_error_unknown_team(uuid);
        break;
        case ERROR_UNKNOWN_CHANNEL:
        client_error_unknown_channel(uuid);
        break;
        case ERROR_UNKNOWN_THREAD:
        client_error_unknown_thread(uuid);
        break;
        case ERROR_UNKNOWN_USER:
        client_error_unknown_user(uuid);
        break;
    }
}

static void handle_server_error(conn_t *conn)
{
    error_t error;
    uuid_t uuid;
    char uuid_str[36] = {0};

    read(conn->socket, &error, sizeof(error_t));
    if (error == ERROR_UNKNOWN_TEAM
    || error == ERROR_UNKNOWN_CHANNEL
    || error == ERROR_UNKNOWN_THREAD
    || error == ERROR_UNKNOWN_USER)
        uuid_unparse(uuid, uuid_str);
    log_error(error, uuid_str);
}

bool reponse_serv_cmd(client_t *client, list_t *transactions)
{
    uint64_t transaction;
    response_t response;

    read(client->conn->socket, &response, sizeof(response_t));
    read(client->conn->socket, &transaction, sizeof(uint64_t));
    switch (response) {
        case COMMAND_OK:
            handle_transaction_with_id(transaction, client, transactions);
            return (false);
        case ERROR_OCCURED:
            handle_server_error(client->conn);
            transaction_destroy_with_id(transaction, transactions);
            return (false);
        case UNKNOWN_COMMAND:
            puts("[ALERT] Unknown commend has been send !");
            return (false);
    }
    return (false);
}

bool handle_server_msg(client_t *client, list_t *transations)
{
    command_id_t cmd;

    if (read(client->conn->socket, &cmd, sizeof(command_id_t)) <= 0)
        return true;
    for (int i = 0; i < SERV_CMD_NB; i++)
        if (SERV_CMDS[i].id == cmd)
            return (SERV_CMDS[i].fct(client, transations));
    return false;
}
