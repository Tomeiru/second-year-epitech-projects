/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** myftp
*/

#include "myftp.h"

int start_server(int port)
{
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    if (server_sock == -1)
        return (-print_error("socket() call failed"));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)))
        return (-print_error("bind() call failed\n"));
    if (listen(server_sock, 1))
        return (-print_error("listen() call failed\n"));
    return (server_sock);
}

int client_gestion(int server_sock)
{
    int client_fd = 0;
    int fork_pid = 0;
    struct sockaddr_in client_addr;
    socklen_t size = sizeof(client_addr);

    client_fd = accept(server_sock, (struct sockaddr *)&client_addr, &size);
    if (client_fd == -1)
        return (print_error("accept() call failed\n"));
    fork_pid = fork();
    if (fork_pid == -1)
        return (print_error("fork() call failed\n"));
    else if (fork_pid == 0) {
        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr),
        ntohs(client_addr.sin_port));
        write(client_fd, "Hello World!!!\n", 15);
        close(client_fd);
    }
    else
        close(client_fd);
    return (0);
}

int client_loop(int server_sock)
{
    while (1) {
        client_gestion(server_sock);
    }
    close(server_sock);
    return (0);
}

int myftp(char **args)
{
    int port = check_and_get_port(args[0]);
    char *path = check_and_get_path(args[1]);
    int server_fd = 0;

    if (port == -1 || path == NULL)
        return (print_error("wrong argument provided (use -help)"));
    server_fd = start_server(port);
    if (server_fd == -84)
        return (84);
    return (client_loop(server_fd));
}
