/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** cmd_list
*/

#include "cli_cmds.h"

const cli_cmd_t CLI_CMDS[CLI_CMD_NB] = {
    {"create", 6, create_parser},
    {"help", 4, help_parser},
    {"info", 4, info_parser},
    {"list", 4, list_parser},
    {"login", 5, login_cli_cmd},
    {"logout", 6, logout_cli_cmd},
    {"messages", 8, messages_parser},
    {"send", 4, send_parser},
    {"subscribe", 9, subscribe_parser},
    {"subscribed", 10, subscribed_parser},
    {"unsubscribe", 11, unsubscribe_parser},
    {"use", 3, use_parse},
    {"user", 4, user_parse},
    {"users", 5, users_parse},
};
