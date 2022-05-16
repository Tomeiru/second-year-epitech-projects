/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** cmd_args
*/

#pragma once

#include "buffer_sizes.h"

typedef unsigned char uuid_t[16];

typedef struct login_cmd_arg_s {
    char name[MAX_NAME_LENGTH];
} login_cmd_arg_t;

typedef struct create_team_cmd_arg_s {
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
} create_team_cmd_arg_t;

typedef struct create_channel_cmd_arg_s {
    uuid_t team_uuid;
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
} create_channel_cmd_arg_t;

typedef struct create_thread_cmd_arg_s {
    uuid_t team_uuid;
    uuid_t channel_uuid;
    char title[MAX_NAME_LENGTH];
    char msg[MAX_BODY_LENGTH];
} create_thread_cmd_arg_t;

typedef struct create_comment_cmd_arg_s {
    uuid_t team_uuid;
    uuid_t channel_uuid;
    uuid_t thread_uuid;
    char comment[MAX_DESCRIPTION_LENGTH];
} create_comment_cmd_arg_t;

typedef struct send_pm_cmd_arg_s {
    uuid_t user_uuid;
    char msg[MAX_BODY_LENGTH];
} send_pm_cmd_arg_t;

typedef struct get_pm_cmd_arg_s {
    uuid_t user_uuid;
} get_pm_cmd_arg_t;
