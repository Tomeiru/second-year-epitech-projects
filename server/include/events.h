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
