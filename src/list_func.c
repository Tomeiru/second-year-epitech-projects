/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** list_func
*/

#include "myftp.h"

void do_file(char *filename, fd_node_t *this, int online_fd)
{
    char *write_in_file = NULL;
    DIR *fd = 0;
    struct dirent *dir;
    int len = 0;
    int i = 0;

    fd = opendir(filename);
    while ((dir = readdir(fd)) != NULL) {
        write_in_file = realloc(write_in_file, (write_in_file == NULL ? 0
        : (strlen(write_in_file))) + strlen(dir->d_name) + 2);
        write_in_file[0] = (i++ == 0 ? '\0' : write_in_file[0]);
        strcat(write_in_file, dir->d_name);
        strcat(write_in_file, " ");
        len += strlen(dir->d_name) + 1;
    }write_in_file[len] = '\0';
    write(online_fd, write_in_file, len);
    dp_ret(this->fd, "226 File transfer done\r\n");
    close_correct_ft(this);
    exit(0);
}

int file_active(char *filename, fd_node_t *this)
{
    int fork_ret = fork();

    if (fork_ret == -1)
        return (print_error("fork() error"));
    if (fork_ret == 0)
        do_file(filename, this, this->client_fd);
    return (0);
}

int file_passive(char *filename, fd_node_t *this)
{
    int fork_ret = fork();

    if (fork_ret == -1)
        return (print_error("fork() error"));
    if (fork_ret == 0)
        do_file(filename, this, this->pasv_connected);
    return (0);
}

int file_absolute_path(char *args, fd_node_t *this)
{
    char *pos = strstr(args, this->home);
    struct stat statbuffer;
    int ret_val = stat(args, &statbuffer);

    if (pos == NULL || pos != args) {
        close_correct_ft(this);
        return (dp_ret(this->fd, "550 Out of FTP Scope\r\n"));
    }if (ret_val != -1 && S_ISREG(statbuffer.st_mode)) {
        close_correct_ft(this);
        return (dp_ret(this->fd, "425 Isn't a directory\r\n"));
    }dprintf(this->fd, "150 File status okay!\r\n");
    if (this->active)
        return (file_active(args, this));
    return (file_passive(args, this));
}

int list_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    if (!this->authentified)
        return (dp_ret(this->fd, "530 Not logged in!\r\n"));
    if (!this->passive && !this->active)
        return (dp_ret(this->fd, "425 You need to do PASV or PORT before\r\n"));
    if (this->passive && !this->pasv_connected) {
        close_correct_ft(this);
        return (dp_ret(this->fd, "425 You didn't connect to the server\r\n"));
    }if (!strcmp(args, "\n"))
        return (file_absolute_path(this->wd, this));
    args[strlen(args) - 2] = '\0';
    if (args[0] == '/')
        return (file_absolute_path(args, this));
    return (file_absolute_path(rel_to_abs(args, this), this));
}