/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** list_manip
*/

#include "myftp.h"

void list_add_at_end(fd_node_t **list, int fd, char *wd)
{
    fd_node_t *new = malloc(sizeof(fd_node_t));
    fd_node_t *temp = *list;

    new->fd = fd;
    new->uname_entered = 0;
    new->authentified = 0;
    new->wd = strdup(wd);
    new->home = strdup(wd);
    new->uname = NULL;
    new->next = NULL;
    new->command = NULL;
    if (*list == NULL) {
        *list = new;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = new;
}

fd_node_t *list_get_element_at(fd_node_t *list, int index)
{
    int i = 0;

    for ( ; list; list = list->next) {
        if (i++ == index)
            return (list);
    }
    return (NULL);
}

void list_remove_index(fd_node_t **list, int index)
{
    fd_node_t *bef = NULL;
    int i = 0;

    if (index == 0) {
        free(*list);
        *list = (*list)->next;
        return;
    }
    for (fd_node_t *temp = *list; temp; temp = temp->next) {
        if (i++ == index) {
            bef->next = temp->next;
            free(temp);
            return;
        }
        bef = temp;
    }
    return;
}

void list_erase_all_and_free(fd_node_t **list)
{
    while (*list) {
        close((*list)->fd);
        list_remove_index(list, 0);
    }
}