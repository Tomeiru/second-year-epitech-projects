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
    {EVENT_PM_RECEIVED_ID, event_pm_received_cmd},
    {EVENT_TEAM_CREATED_ID, event_team_created_cmd},
    {EVENT_CHANNEL_CREATED_ID, event_channel_created_cmd},
    {EVENT_THREAD_CREATED_ID, event_thread_created_cmd},
    {EVENT_REPLY_CREATED_ID, event_comment_created_cmd},
};
