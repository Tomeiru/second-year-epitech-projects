/*
** EPITECH PROJECT, 2022
** teams
** File description:
** main
*/

#include "cli_teams.h"
#include "safe_malloc.h"
#include "utils.h"
#include "cli_cmds.h"

use_t *init_use()
{
    use_t *use = safe_malloc(sizeof(use_t));

    use->state = NO_USE_STATE;
    memset(use->team, 0, 16);
    memset(use->channel, 0, 16);
    memset(use->thread, 0, 16);
    return (use);
}

conn_t *init_connect(char *ip, int port)
{
    conn_t *conn = safe_malloc(sizeof(conn_t));
    struct sockaddr_in serv_addr = {.sin_family = AF_INET,
    .sin_port = htons(port)};

    if ((conn->socket = socket(AF_INET, SOCK_STREAM, 0)) <  0) {
        puts("Client ocket creation error");
        return (NULL);
    }
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        puts("Invalid adress or adress not supported");
        return (NULL);
    }
    if (connect(conn->socket,
    (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        puts("Connection Failed");
        return (NULL);
    }
    conn->sockaddr = serv_addr;
    return (conn);
}

void wait_for_input(fd_set *rdset, conn_t *conn)
{
    FD_ZERO(rdset);
    FD_SET(0, rdset);
    FD_SET(conn->socket, rdset);
    select(conn->socket + 1, rdset, NULL, NULL, NULL);
}

int start_cli(char *ip, int port)
{
    client_t client = {.conn = init_connect(ip, port),  .use = init_use(),
    .connected = false};
    list_t transactions = NULL;
    fd_set rdset;

    if (!client.conn)
        return (84);
    while (1) {
        wait_for_input(&rdset, client.conn);
        if (FD_ISSET(client.conn->socket, &rdset)
        && handle_server_msg(&client, &transactions))
            break;
        if (FD_ISSET(0, &rdset)
        && !handle_user_cmd(&client, &transactions))
            break;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp("-help", av[1]) == 0) {
        printf("USAGE: ./myteams_cli ip port\n\n");
        printf("       ip   is the server ip address on which the server");
        printf(" socket listens\n");
        printf("       port is the port number on which the server socket");
        printf(" listens.\n");
        return (0);
    } else if (ac != 3 || is_not_number(av[2]))
        return (84);
    return (start_cli(av[1], atoi(av[2])));
}
