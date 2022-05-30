/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** cli_cmds
*/

#pragma once

#include "chained_list.h"

#define CLI_CMD_NB 2

typedef struct client_s client_t;

typedef void (*cli_cmd_execute_fct_t)(client_t *client,
int ac, char **av, list_t *transations);

typedef struct cli_cmd_s {
    char *name;
    int name_len;
    cli_cmd_execute_fct_t execute;
} cli_cmd_t;

void login_cli_cmd(client_t *client,
int ac, char **av, list_t *transactions);
void logout_cli_cmd(client_t *client,
int ac, char **av, list_t *transactions);

extern const cli_cmd_t CLI_CMDS[CLI_CMD_NB];
