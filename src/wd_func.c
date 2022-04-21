/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** wd_func
*/

#include "myftp.h"

int pwd_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    if (!this->authentified) {
        dprintf(this->fd, "530 Not logged in!\r\n");
        return (0);
    }
    if (!strcmp(args, "\n")) {
        dprintf(this->fd, "257 %s\r\n", this->wd);
        return (0);
    }
    dprintf(this->fd, "501 PWD doesn't take any argument\r\n");
    return (0);
}

void cwd_absolute_path(char *args, fd_node_t *this)
{
    struct stat statbuffer;

    if (stat(args, &statbuffer) != -1 && !S_ISREG(statbuffer.st_mode)) {
        free(this->wd);
        this->wd = realpath(args, NULL);
        dprintf(this->fd, "200 Successfully changed WD\r\n");
        return;
    }
    dprintf(this->fd, "503 %s isn't a valid directory\r\n", args);
}

void cwd_relative_path(char *args, fd_node_t *this)
{
    char *filepath = strdup(this->wd);
    struct stat statbuffer;

    filepath = realloc(filepath, strlen(filepath + strlen(args) + 2));
    filepath = strcat(filepath, "/");
    filepath = strcat(filepath, args);
    if (stat(filepath, &statbuffer) != -1 && !S_ISREG(statbuffer.st_mode)) {
        free(this->wd);
        this->wd = realpath(filepath, NULL);
        dprintf(this->fd, "200 Successfully changed WD\r\n");
        return;
    }
    dprintf(this->fd, "503 %s isn't a valid directory\r\n", args);
}

int cwd_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    if (!this->authentified) {
        dprintf(this->fd, "530 Not logged in!\r\n");
        return (0);
    }
    if (!strcmp(args, "\n") || strlen(args) == 2) {
        dprintf(this->fd, "501 CWD needs a path to work\r\n");
        return (0);
    }
    args[strlen(args) - 2] = '\0';
    if (args[0] == '/') {
        cwd_absolute_path(args, this);
        return (0);
    }
    cwd_relative_path(args, this);
    return (0);
}

int cdup_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);
    char *temp;

    if (!this->authentified) {
        dprintf(this->fd, "530 Not logged in!\r\n");
        return (0);
    }
    if (!strcmp(args, "\n")) {
        if (!strcmp(this->wd, "/")) {
            dprintf(this->fd, "503 / doesn't have a parent directory\r\n");
            return (0);
        }this->wd = realloc(this->wd, strlen(this->wd + 4));
        this->wd = strcat(this->wd, "/..");
        temp = realpath(this->wd, NULL);
        free(this->wd);
        this->wd = temp;
        dprintf(this->fd, "200 Successfully changed WD\r\n");
        return (0);
    }dprintf(this->fd, "501 CDUP doesn't take any argument\r\n");
    return (0);
}