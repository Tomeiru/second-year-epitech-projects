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
    {SUBSCRIBE_ID, sizeof(subscribe_cmd_arg_t), subscribe_to_team_cmd},
    {UNSUBSCRIBE_ID, sizeof(unsubscribe_cmd_arg_t), unsubscribe_to_team_cmd},
    {LIST_USERS_ID, sizeof(list_users_cmd_arg_t), users_cmd},
    {LIST_TEAMS_ID, sizeof(list_cmd_arg_t), list_team_cmd},
    {LIST_CHANNELS_ID, sizeof(list_cmd_arg_t), list_channel_cmd},
    {LIST_THREADS_ID, sizeof(list_cmd_arg_t), list_thread_cmd},
    {LIST_COMMENTS_ID, sizeof(list_cmd_arg_t), list_comment_cmd},
    {LIST_SUBSCRIBED_TEAMS_ID,
    sizeof(list_subscribed_teams_cmd_arg_t), list_subscribed_teams_cmd},
    {LIST_USERS_SUBSCRIBED_TO_TEAM_ID,
    sizeof(list_users_subscribed_to_team_cmd_arg_t), list_users_subscribed_cmd},
};
