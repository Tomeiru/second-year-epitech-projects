/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** command_func
*/

#include "myftp.h"

int retr_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    UNUSED(args);
    UNUSED(this);
    return (0);
}

int stor_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    UNUSED(args);
    UNUSED(this);
    return (0);
}

int list_func(fd_node_t **list, int index, char *args)
{
    fd_node_t *this = list_get_element_at(*list, index);

    UNUSED(args);
    UNUSED(this);
    return (0);
}