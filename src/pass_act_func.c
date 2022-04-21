/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** pass_act_func
*/

#include "myftp.h"

int dp_ret(int fd, char *str)
{
    dprintf(fd, str);
    return (0);
}

int pasv_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    int port = 0;

    if (!this->authentified)
        return (dp_ret(this->fd, "530 Not logged in!\r\n"));
    if (this->active || this->passive)
        return (dp_ret(this->fd, "503 Already opened a connection"));
    if (!strcmp(args, "\n")) {
        this->passive = 1;
        this->server_fd = start_server(-1);
        getsockname(this->server_fd, (struct sockaddr *)&addr, &len);
        port = ntohs(addr.sin_port);
        dprintf(this->fd, "227 (127,0,0,1,%i,%i)\r\n", port / 1000,
        port % 1000);
        return (0);
    }
    return (dp_ret(this->fd, "501 PASV doesn't take any argument\r\n"));
}

int check_elements_port_args(char *args)
{
    int count = 0;
    int i = 1;

    if (strlen(args) < 11)
        return (1);
    if (args[0] != '(')
        return (1);
    for ( ; args[i]; i++) {
        if (args[i] == ',' && isdigit(args[i - 1]))
            count++;
    }
    if (count != 5 || args[--i] != ')' || !isdigit(args[--i]))
        return (1);
    return (0);

}

int launch_client(fd_node_t *this, char *ip, char *port)
{
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    if (client_sock == -1)
        return (print_error("socket() call failed"));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(client_sock, (struct sockaddr *)&server_addr,
    sizeof(server_addr)))
        return (print_error("connect() call failed"));
    this->client_fd = client_sock;
    free(ip);
    free(port);
    return (0);
}

int port_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);
    char *ip;
    char *port;

    if (!this->authentified)
        return (dp_ret(this->fd, "530 Not logged in!\r\n"));
    if (this->active || this->passive)
        return (dp_ret(this->fd, "503 Already opened a connection"));
    if (!strcmp(args, "\n"))
        return (dp_ret(this->fd, "550 PORT needs a IP-Port to work\r\n"));
    args[strlen(args) - 2] = '\0';
    if (parse_port_args(args, &ip, &port))
        return (dp_ret(this->fd, "550 Invalid IP-Port\r\n"));
    this->active = 1;
    dprintf(this->fd, "200 Active mode toggled on\r\n");
    return (launch_client(this, ip, port));
}