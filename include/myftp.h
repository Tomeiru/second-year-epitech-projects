/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** myftp
*/

#pragma once

//INCLUDES

#include <arpa/inet.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct fd_node_s {
    int fd;
    int uname_entered;
    int authentified;
    int passive;
    int server_fd;
    int active;
    int client_fd;
    char *wd;
    char *home;
    char *uname;
    char *command;
    struct fd_node_s *next;
} fd_node_t;

//PROTOTYPES

int print_error(char *err);
int myftp(char **args);
char *check_and_get_path(char *path);
int check_and_get_port(char *port);
void list_add_at_end(fd_node_t **list, int fd, char *wd);
fd_node_t *list_get_element_at(fd_node_t *list, int index);
void list_remove_index(fd_node_t **list, int index);
int user_func(fd_node_t **list, int index, char *buffer);
int pass_func(fd_node_t **list, int index, char *buffer);
int cwd_func(fd_node_t **list, int index, char *buffer);
int cdup_func(fd_node_t **list, int index, char *buffer);
int quit_func(fd_node_t **list, int index, char *buffer);
int dele_func(fd_node_t **list, int index, char *buffer);
int pwd_func(fd_node_t **list, int index, char *buffer);
int pasv_func(fd_node_t **list, int index, char *buffer);
int port_func(fd_node_t **list, int index, char *buffer);
int help_func(fd_node_t **list, int index, char *buffer);
int noop_func(fd_node_t **list, int index, char *buffer);
int retr_func(fd_node_t **list, int index, char *buffer);
int stor_func(fd_node_t **list, int index, char *buffer);
int list_func(fd_node_t **list, int index, char *buffer);
int client_loop(int server_sock, char *path);
void list_erase_all_and_free(fd_node_t **list);
void free_and_set_command_to_null(fd_node_t *this);
void ftp_set_fd(int server_sock, fd_node_t *list, fd_set *set_read,
int *fd_max);
void ftp_reset_fd(fd_set *set_read);
int start_server(int port);
int parse_port_args(char *args, char **ip, char **port);
int check_elements_port_args(char *args);
void append_to_command(fd_node_t *this, char *buffer);

//DEFINES

#define UNUSED(x) (void)(x)
#define D(x, y) a[x] = strdup(y)
