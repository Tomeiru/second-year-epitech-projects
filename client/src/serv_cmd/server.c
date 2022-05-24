/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** server
*/

#include "chained_list.h"
#include "conn.h"
#include "safe_malloc.h"
#include "transaction.h"
#include "utils.h"
#include "responses.h"
#include "cmd_ids.h"

void reponse_serv_cmd(conn_t *conn, list_t *transactions)
{
    uint64_t transaction;
    response_t response;

    read(conn->serv_fd, &transaction, sizeof(uint64_t));
    read(conn->serv_fd, &response, sizeof(response_t));
}

bool handle_server_msg(conn_t *connection, list_t *transations)
{
    command_id_t cmd;

    if (read(connection->serv_fd, &cmd, sizeof(command_id_t)) <= 0)
        return true;
    return false;
}
