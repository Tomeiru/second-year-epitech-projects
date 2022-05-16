/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** save
*/

#pragma once

#include <uuid/uuid.h>
#include "buffer_sizes.h"
#include "chained_list.h"

typedef struct save_s {
    list_t users;
    list_t discussions;
    list_t teams;
} save_t;

typedef struct user_s {
    uuid_t uuid;
    uuid_list_t teams;
    uint teams_nb;
    uuid_list_t discussions;
    uint discussions_nb;
} user_t;

typedef struct team_s {
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    uuid_list_t users;
    uint users_nb;
    list_t channels;
    uint channels_nb;
} team_t;

typedef struct channel_s {
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESCRIPTION_LENGTH];
    list_t threads;
    uint threads_nb;
} channel_t;

typedef struct thread_s {
    uuid_t uuid;
    uuid_t user;
    char name[MAX_NAME_LENGTH];
    char msg[MAX_BODY_LENGTH];
    list_t comments;
    uint comments_nb;
} thread_t;

typedef struct comment_s {
    uuid_t uuid;
    uuid_t user;
    char msg[MAX_BODY_LENGTH];
} comment_t;

typedef struct discussion_s {
    uuid_t uuid;
    uuid_t users[2];
    list_t messages;
    uint messages_nb;
} discussion_t;

typedef struct message_s {
    uuid_t uuid;
    uuid_t user;
    char msg[MAX_BODY_LENGTH];
} message_t;

bool save_infos(save_t *save, char *path);
void save_uuids(uuid_list_t uuids, int fd);
void save_teams(list_t teams, int fd);

void load_infos(save_t *save, char *path);
void load_uuids(uuid_list_t *uuids, uint n, int fd);
void load_teams(save_t *save, int fd);
