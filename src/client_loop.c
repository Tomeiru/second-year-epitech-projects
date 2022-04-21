/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** client_loop
*/

#include "myftp.h"

void add_new_client(int server_sock, fd_node_t **list, int *fd_max, char *path)
{
    int client_fd = 0;
    struct sockaddr_in client_addr;
    socklen_t size = sizeof(client_addr);

    client_fd = accept(server_sock, (struct sockaddr *)&client_addr, &size);
    printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr),
    ntohs(client_addr.sin_port));
    dprintf(client_fd, "220 Connection established\r\n");
    if (client_fd > server_sock)
        *fd_max = client_fd + 1;
    list_add_at_end(list, client_fd, path);
}

void exec_command(fd_node_t **list, int index, char *buffer)
{
    fd_node_t *this = list_get_element_at(*list, index);
    char *args = NULL;
    char *command = __strtok_r(buffer, " \r", &args);
    int ret = -1;
    char command_arr[14][5] = {
        "USER", "PASS", "CWD", "CDUP", "QUIT", "DELE", "PWD", "PASV",
        "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"
    };
    int (*command_func[14])(fd_node_t **, int, char *) = {
        user_func, pass_func, cwd_func, cdup_func, quit_func, dele_func,
        pwd_func, pasv_func, port_func, help_func, noop_func, retr_func,
        stor_func, list_func
    };

    for (int i = 0; i < 14; i++)
        if (!strcmp(command_arr[i], command))
            ret = command_func[i](list, index, args);
    if (ret == -1)
        dprintf(this->fd, "502 Wrong command or command is not implemented\n");
    return;
}

void client_activity(fd_node_t **list, int index)
{
    fd_node_t *this = list_get_element_at(*list, index);
    char buffer[1024];
    int ret_read = read(this->fd, buffer, 1024);

    if (ret_read == 0) {
        printf("Communication closed with %i\n", this->fd);
        close(this->fd);
        list_remove_index(list, index);
        return;
    }
    buffer[ret_read] = '\0';
    exec_command(list, index, buffer);
}

void check_clients(fd_set set_read, fd_node_t **list)
{
    int i = 0;

    for (fd_node_t *temp = *list; temp; temp = temp->next) {
        if (FD_ISSET(temp->fd, &set_read))
            client_activity(list, i);
        i++;
    }
}

int client_loop(int server_sock, char *path)
{
    fd_set set_read;
    fd_set set_write;
    int select_ret = 0;
    fd_node_t *list = NULL;
    int fd_max = server_sock + 1;

    while (1) {
        ftp_reset_fd(&set_read, &set_write);
        ftp_set_fd(server_sock, list, &set_read, &set_write);
        select_ret = select(fd_max, &set_read, &set_write, NULL, NULL);
        if (select_ret == -1)
            return (print_error("select() call failed"));
        if (!select_ret)
            continue;
        check_clients(set_read, &list);
        if (FD_ISSET(server_sock, &set_read))
            add_new_client(server_sock, &list, &fd_max, path);
    }
    close(server_sock);
    return (0);
}