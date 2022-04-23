/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** retr_func
*/

#include "myftp.h"

void do_retr(char *filename, fd_node_t *this, int online_fd)
{
    char *write_in_file;
    int fd = 0;
    int len = 0;
    int read_ret = 0;
    char buffer[1025];

    fd = open(filename, O_RDONLY);
    read_ret = read(fd, buffer, 1024);
    buffer[read_ret] = '\0';
    write_in_file = malloc(sizeof(char) * (read_ret + 1));
    memcpy(write_in_file + len, buffer, read_ret + 1);
    len += read_ret;
    while ((read_ret = read(fd, buffer, 1024)) > 0) {
        write_in_file = realloc(write_in_file, (len + read_ret + 1));
        memcpy(write_in_file + len, buffer, read_ret);
        len += read_ret;
    }close(fd);
    write(online_fd, write_in_file, len);
    close_correct_ft(this);
    exit(dp_ret(this->fd, "226 File transfer done\r\n"));
}

int retr_active(char *filename, fd_node_t *this)
{
    int fork_ret = fork();

    if (fork_ret == -1)
        return (print_error("fork() error"));
    if (fork_ret == 0)
        do_retr(filename, this, this->client_fd);
    return (0);
}

int retr_passive(char *filename, fd_node_t *this)
{
    int fork_ret = fork();

    if (fork_ret == -1)
        return (print_error("fork() error"));
    if (fork_ret == 0)
        do_retr(filename, this, this->pasv_connected);
    return (0);
}

int retr_absolute_path(char *args, fd_node_t *this)
{
    char *pos = strstr(args, this->home);
    struct stat statbuffer;
    int ret_val = stat(args, &statbuffer);

    if (pos == NULL || pos != args) {
        close_correct_ft(this);
        return (dp_ret(this->fd, "550 Out of FTP Scope\r\n"));
    }if (ret_val == -1 || access(args, R_OK) == -1 ||
    !S_ISREG(statbuffer.st_mode)) {
        close_correct_ft(this);
        return (dp_ret(this->fd, "425 No permission to read here\r\n"));
    }dprintf(this->fd, "150 File status okay!\r\n");
    if (this->active)
        return (retr_active(args, this));
    return (retr_passive(args, this));
}

int retr_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    if (!this->authentified)
        return (dp_ret(this->fd, "530 Not logged in!\r\n"));
    if (!this->passive && !this->active)
        return (dp_ret(this->fd, "425 You need to do PASV or PORT before\r\n"));
    if (this->passive && !this->pasv_connected) {
        close_correct_ft(this);
        return (dp_ret(this->fd, "425 You didn't connect to the server\r\n"));
    }if (!strcmp(args, "\n")) {
        close_correct_ft(this);
        return (dp_ret(this->fd, "425 RETR needs a filepath\r\n"));
    }args[strlen(args) - 2] = '\0';
    if (args[0] == '/')
        return (retr_absolute_path(args, this));
    return (retr_absolute_path(rel_to_abs(args, this), this));
}