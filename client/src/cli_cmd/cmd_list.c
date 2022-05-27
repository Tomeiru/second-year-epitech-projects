/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** cmd_list
*/

#include "cli_cmds.h"

const cli_cmd_t CLI_CMDS[CLI_CMD_NB] = {
    {"login", 5, login_cli_cmd},
    {"logout", 6, logout_cli_cmd},
};
