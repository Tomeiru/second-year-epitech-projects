/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** cmd_list
*/

#include "server_cmds.h"

const serv_cmd_t SERV_CMDS[SERV_CMD_NB] = {
    {RESPONSE_ID, reponse_serv_cmd},
    {EVENT_USER_LOGIN_ID, event_login_serv_cmd},
    {EVENT_USER_LOGOUT_ID, event_logout_serv_cmd},
};