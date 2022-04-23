/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** stor_func
*/

#include "myftp.h"

void do_stor(char *filename, fd_node_t *this, int online_fd)
{
    char *write_in_file;
    int fd = 0;
    int len = 0;
    int read_ret = 0;
    char buffer[1025];

    fd = open(filename, O_WRONLY | O_CREAT, 0777);
    read_ret = read(online_fd, buffer, 1024);
    buffer[read_ret] = '\0';
    write_in_file = malloc(sizeof(char) * (read_ret + 1));
    memcpy(write_in_file + len, buffer, read_ret + 1);
    len += read_ret;
    while ((read_ret = read(online_fd, buffer, 1024)) > 0) {
        write_in_file = realloc(write_in_file, (len + read_ret + 1));
        memcpy(write_in_file + len, buffer, read_ret);
        len += read_ret;
    }close(fd);
    write(fd, write_in_file, len);
    close_correct_ft(this);
    exit(dp_ret(this->fd, "226 File transfer done\r\n"));
}

int stor_active(char *filename, fd_node_t *this)
{
    int fork_ret = fork();

    if (fork_ret == -1)
        return (print_error("fork() error"));
    if (fork_ret == 0)
        do_stor(filename, this, this->client_fd);
    return (0);
}

int stor_passive(char *filename, fd_node_t *this)
{
    int fork_ret = fork();

    if (fork_ret == -1)
        return (print_error("fork() error"));
    if (fork_ret == 0)
        do_stor(filename, this, this->pasv_connected);
    return (0);
}

int stor_absolute_path(char *args, fd_node_t *this)
{
    char *pos = strstr(args, this->home);
    struct stat statbuffer;
    int ret_val = stat(args, &statbuffer);

    if (pos == NULL || pos != args) {
        close_correct_ft(this);
        return (dp_ret(this->fd, "550 Out of FTP Scope\r\n"));
    }if (ret_val != -1 && !S_ISREG(statbuffer.st_mode)) {
        close_correct_ft(this);
        return (dp_ret(this->fd, "425 Already exist and is a Directory\r\n"));
    }if (ret_val != -1 && access(args, W_OK) == -1) {
        close_correct_ft(this);
        return (dp_ret(this->fd, "425 No permission to write here\r\n"));
    }dprintf(this->fd, "150 File status okay!\r\n");
    if (this->active)
        return (stor_active(args, this));
    return (stor_passive(args, this));
}

int stor_func(fd_node_t **list, int index, char *args)
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
        return (dp_ret(this->fd, "425 STOR needs a filepath\r\n"));
    }args[strlen(args) - 2] = '\0';
    if (args[0] == '/')
        return (stor_absolute_path(args, this));
    return (stor_absolute_path(rel_to_abs(args, this), this));
}