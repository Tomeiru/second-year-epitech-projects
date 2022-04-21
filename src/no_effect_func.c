/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** no_effect_func
*/

#include "myftp.h"

#define D(x, y) a[x] = strdup(y)

char **create_help_array(void)
{
    char **a = malloc(sizeof(char *) * 14);

    D(0, "USER <SP> <username> <CRLF> : Specify user for authentication");
    D(1, "PASS <SP> <password> <CRLF> : Specify password for authentication");
    D(2, "CWD  <SP> <pathname> <CRLF> : Change working directory");
    D(3, "CDUP <CRLF> : Change working directory to parent directory");
    D(4, "QUIT <CRLF> : Disconnection");
    D(5, "DELE <SP> <pathname> <CRLF> : Delete file on the server");
    D(6, "PWD  <CRLF> : Print working directory");
    D(7, "PASV <CRLF> : Enable \"passive\" mode for data transfer");
    D(8, "PORT <SP> <host-port> <CRLF> : Enable \"active\" mode for data \
transfer");
    D(9, "HELP [<SP> <string>] <CRLF> : List available commands");
    D(10, "NOOP <CRLF> : Do nothing");
    D(11, "RETR <SP> <pathname> <CRLF> : Download file from server to client");
    D(12, "STOR <SP> <pathname> <CRLF> : Upload file from client to server");
    D(13, "LIST [<SP> <pathname>] <CRLF> : List files in the current working \
directory");
    return (a);
}

void display_all_help(fd_node_t *this, char **help_array)
{
    dprintf(this->fd, "214 Command list: ");
    for (int i = 0; i < 13; i++)
        dprintf(this->fd, "%s, ", help_array[i]);
    dprintf(this->fd, "%s\r\n", help_array[13]);
    for (int i = 0; i < 14; i++)
        free(help_array[i]);
    free(help_array);
}

int display_singular_help(fd_node_t *this, char *args, char **help_array)
{
    char command_arr[14][5] = {
        "USER", "PASS", "CWD", "CDUP", "QUIT", "DELE", "PWD", "PASV",
        "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"
    };
    int ret = 1;

    args[strlen(args) - 2] = '\0';
    for (int i = 0; i < 14; i++)
        if (!strcmp(command_arr[i], args)) {
            dprintf(this->fd, "214 Help for command %s: %s\r\n", args,
            help_array[i]);
            ret = 0;
        }
    for (int i = 0; i < 14; i++)
        free(help_array[i]);
    free(help_array);
    return (ret);
}

int help_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);
    char **help_array = create_help_array();

    if (!strcmp(args, "\n")) {
        display_all_help(this, help_array);
        return (0);
    }
    if (display_singular_help(this, args, help_array)) {
        dprintf(this->fd, "501 Command provided as argument does \
not exist\r\n");
    }
    return (0);
}

int noop_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    if (!strcmp(args, "\n")) {
        dprintf(this->fd, "200 Nothing has been done successfully\r\n");
        return (0);
    }
    dprintf(this->fd, "501 NOOP doesn't take any argument\r\n");
    return (0);
}
