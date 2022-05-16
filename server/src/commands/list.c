/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** list
*/

#include "commands.h"

const command_t COMMANDS[COMMANDS_NB] = {
    {00, sizeof(login_cmd_arg_t), login_cmd},
    {01, 0, logout_cmd},
    {02, sizeof(create_team_cmd_arg_t), create_team_cmd},
    {03, sizeof(create_channel_cmd_arg_t), create_channel_cmd},
    {04, sizeof(create_thread_cmd_arg_t), create_thread_cmd},
    {05, sizeof(create_comment_cmd_arg_t), create_comment_cmd},
    {06, sizeof(send_pm_cmd_arg_t), send_pm_cmd},
    {06, sizeof(get_pm_cmd_arg_t), get_pm_cmd},
};
