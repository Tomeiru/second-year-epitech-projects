/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** cli_cmds
*/

#pragma once

#include "chained_list.h"
#include <stdbool.h>

#define CLI_CMD_NB 14
#define TEAMS_EOF false
#define SUCCESS_CMD true
#define ERROR_CMD -1

typedef struct client_s client_t;

typedef bool (*cli_cmd_execute_fct_t)(client_t *client,
int ac, char **av, list_t *transations);

typedef struct cli_cmd_s {
    char *name;
    int name_len;
    cli_cmd_execute_fct_t execute;
} cli_cmd_t;

bool create_parser(client_t *client, int ac, char **av, list_t *transactions);
bool help_parser(client_t *client, int ac, char **av, list_t *transactions);
bool info_parser(client_t *client, int ac, char **av, list_t *transactions);
bool list_parser(client_t *client, int ac, char **av, list_t *transactions);
bool login_parser(client_t *client, int ac, char **av, list_t *transactions);
bool logout_parser(client_t *client, int ac, char **av, list_t *transactions);
bool messages_parser(client_t *client, int ac, char **av, list_t *transactions);
bool send_parser(client_t *client, int ac, char **av, list_t *transactions);
bool subscribe_parser(client_t *client, int ac, char **av,
list_t *transactions);
bool subscribed_parser(client_t *client, int ac, char **av,
list_t *transactions);
bool unsubscribe_parser(client_t *client, int ac, char **av,
list_t *transactions);
bool use_parse(client_t *client, int ac, char **av, list_t *transactions);
bool user_parse(client_t *client, int ac, char **av, list_t *transactions);
bool users_parse(client_t *client, int ac, char **av, list_t *transactions);

extern const cli_cmd_t CLI_CMDS[CLI_CMD_NB];
