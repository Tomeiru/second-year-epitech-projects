/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** macros
*/

#pragma once

#define GET_TEAM(client, arg, save) \
    (get_team_or_error(client, arg->team_uuid, save, arg->transaction))

#define GET_CHANNEL(client, arg, team) \
    (get_channel_or_error(client, arg->channel_uuid, team, arg->transaction))

#define GET_THREAD(client, arg, channel) \
    (get_thread_or_error(client, arg->thread_uuid, channel, arg->transaction))

#define GET_USER(client, arg, save) \
    (get_user_or_error(client, arg->user_uuid, save, arg->transaction))
