/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** events
*/

#pragma once

#include "teams.h"

void event_user_logged_in(server_t *server, user_t *user);
void event_user_logged_out(server_t *server, user_t *user);
void event_team_created(server_t *server, team_t *team);
void event_channel_created(server_t *server, team_t *team, channel_t *channel);
void event_thread_created(server_t *server, team_t *team, thread_t *thread);
void event_comment_created(server_t *server, team_t *team, thread_t *thread,
comment_t *comment);
