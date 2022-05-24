/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** server_cmds
*/

#pragma once

#include "chained_list.h"
#include "cmd_ids.h"

#define SERV_CMD_NB 1

typedef struct conn_s conn_t;

typedef void (*serv_cmd_execute_fct_t)(conn_t *conn, list_t *transations);

typedef struct serv_cmd_s {
    command_id_t id;
    serv_cmd_execute_fct_t fct;
} serv_cmd_t;

void reponse_serv_cmd(conn_t *conn, list_t *transactions);

extern const serv_cmd_t SERV_CMDS[SERV_CMD_NB];
