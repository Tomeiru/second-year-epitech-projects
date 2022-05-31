/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** use
*/

#include "cli_teams.h"
#include "cli_cmds.h"
#include "cmd_args.h"

static bool empty_use_handler(char **av, client_t *client)
{
    client->use->state = NO_USE_STATE;
    memset(client->use->team, 0, 16);
    memset(client->use->channel, 0, 16);
    memset(client->use->thread, 0, 16);
    UNUSED(av);
    return (SUCCESS_CMD);
}

static bool team_use_handler(char **av, client_t *client)
{
    uuid_t team;

    memset(team, 0, 16);
    if (uuid_parse(av[0], team))
        return (ERROR_CMD);
    client->use->state = TEAM_USE_STATE;
    memcpy(client->use->team, team, 16);
    memset(client->use->channel, 0, 16);
    memset(client->use->thread, 0, 16);
    return (SUCCESS_CMD);
}

static bool channel_use_handler(char **av, client_t *client)
{
    uuid_t team;
    uuid_t channel;

    memset(team, 0, 16);
    memset(channel, 0, 16);
    if (uuid_parse(av[0], team) || uuid_parse(av[1], channel))
        return (ERROR_CMD);
    client->use->state = CHANNEL_USE_STATE;
    memcpy(client->use->team, team, 16);
    memcpy(client->use->channel, channel, 16);
    memset(client->use->thread, 0, 16);
    return (SUCCESS_CMD);
}

static bool thread_use_handler(char **av, client_t *client)
{
    uuid_t team;
    uuid_t channel;
    uuid_t thread;

    memset(team, 0, 16);
    memset(channel, 0, 16);
    memset(thread, 0, 16);
    if (uuid_parse(av[0], team) || uuid_parse(av[1], channel) ||
    uuid_parse(av[2], thread))
        return (ERROR_CMD);
    client->use->state = THREAD_USE_STATE;
    memcpy(client->use->team, team, 16);
    memcpy(client->use->channel, channel, 16);
    memcpy(client->use->thread, thread, 16);
    return (SUCCESS_CMD);
}

bool use_parse(client_t *client, int ac, char **av, list_t *transactions)
{
    bool (*use_handlers[4])(char **, client_t *) = {
        empty_use_handler, team_use_handler, channel_use_handler,
        thread_use_handler
    };
    for (int i = 0; i < 4; i++)
        if (i == ac)
            return (use_handlers[i](av, client));
    UNUSED(transactions);
    return (ERROR_CMD);
}
