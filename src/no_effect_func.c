/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** no_effect_func
*/

#include "myftp.h"

int help_func(fd_node_t **list, int index, char *args)
{
    UNUSED(list);
    UNUSED(index);
    UNUSED(args);
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
