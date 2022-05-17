/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** save
*/

#pragma once

#include <uuid/uuid.h>
#include <stdbool.h>
#include "buffer_sizes.h"
#include "chained_list.h"

typedef struct save_s {
    list_t users;
    list_t discussions;
    list_t teams;
} save_t;

typedef struct user_s {
    uuid_t uuid;
    char name[MAX_NAME_LENGTH];
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

user_t *user_create(char *name, save_t *save);
discussion_t *discussion_create(user_t *usr1, user_t *usr2, save_t *save);
team_t *team_create(char *name, char *desc, save_t *save);
channel_t *channel_create(char *name, char *desc, team_t *team);
thread_t *thread_create(char *name,
char *msg, uuid_t sender, channel_t *channel);
comment_t *comment_create(char *msg, uuid_t sender, thread_t *thread);

user_t *get_user_by_name(char *name, save_t *save);
user_t *get_user_by_uuid(uuid_t uuid, save_t *save);
team_t *get_team_by_uuid(uuid_t uuid, save_t *save);
channel_t *get_channel_by_uuid(uuid_t uuid, team_t *team);
thread_t *get_thread_by_uuid(uuid_t uuid, channel_t *channel);