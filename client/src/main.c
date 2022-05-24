/*
** EPITECH PROJECT, 2022
** teams
** File description:
** main
*/
#include "conn.h"
#include "safe_malloc.h"
#include "utils.h"

conn_t *init_connect(char *ip, int port)
{
    conn_t *connection = safe_malloc(sizeof(conn_t));
    struct sockaddr_in serv_addr = {.sin_family = AF_INET,
    .sin_port = htons(port)};

    if ((connection->serv_fd = socket(AF_INET, SOCK_STREAM, 0)) <  0) {
        printf("Client ocket creation error\n");
        return (NULL);
    }
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) {
        printf("Invalid adress or adress not supported\n");
        return (NULL);
    }
    if ((connection->cli_fd = connect(connection->serv_fd,
    (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0) {
        printf("Connection Failed\n");
        return (NULL);
    }
    connection->sockaddr = serv_addr;
    return (connection);
}

int start_cli(char *ip, int port)
{
    conn_t *connection = init_connect(ip, port);
    char sending[1024] = { 0 };
    char received[1024] = { 0 };
    int valread = 0;

    if (!connection)
        return (84);
    while (1) {
        read(connection->serv_fd, sending, 1024);
        write(connection->serv_fd, sending, 1024);
        printf("Message sent\r\n");
        valread = read(connection->serv_fd, received, 1024);
        printf("Received : %s\n", received);
    }
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