/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** list
*/

#include "cmd_ids.h"
#include "commands.h"

const command_t COMMANDS[COMMANDS_NB] = {
    {LOGIN_ID, sizeof(login_cmd_arg_t), login_cmd},
    {LOGOUT_ID, sizeof(logout_cmd_arg_t), logout_cmd},
    {CREATE_TEAM_ID, sizeof(create_team_channel_cmd_arg_t), create_team_cmd},
    {CREATE_CHANNEL_ID,
    sizeof(create_team_channel_cmd_arg_t), create_channel_cmd},
    {CREATE_THREAD_ID, sizeof(create_thread_cmd_arg_t), create_thread_cmd},
    {CREATE_COMMENT_ID, sizeof(create_comment_cmd_arg_t), create_comment_cmd},
    {SEND_PM_ID, sizeof(send_pm_cmd_arg_t), send_pm_cmd},
    {GET_PMS_ID, sizeof(get_pm_cmd_arg_t), get_pm_cmd},
};
