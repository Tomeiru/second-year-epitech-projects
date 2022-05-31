/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** chained_list
*/

#include "chained_list.h"

void delete_node(node_t **root, int index)
{
    node_t *tmp = *root;
    node_t *prev;

    if (index == 0) {
        *root = tmp->next;
        free(tmp);
        return;
    }
    for (int i = 0; tmp && i != index; tmp = tmp->next)
        prev = tmp;
    if (!tmp)
        return;
    prev->next = tmp->next;
    free(tmp);
}

void delete_node_with_data(list_t *list, void *data)
{
    node_t *prev = NULL;

    if (!(*list))
        return;
    for (list_t cpy = *list; cpy; prev = cpy, cpy = cpy->next) {
        if (cpy->data != data)
            continue;
        if (prev)
            prev->next = cpy->next;
        else
            *list = cpy->next;
        free(cpy);
        break;
    }
}

int node_len(list_t list)
{
    int count = 0;

    for (list_t tmp = list; tmp; tmp = tmp->next, count++);
    return (count);
}

void delete_list(list_t list)
{
    list_t next;

    for (list_t cpy = list; cpy; cpy = next) {
        next = cpy->next;
        free(cpy);
    }
}

void delete_uuid_from_list(uuid_t uuid, uuid_list_t *list)
{
    uuid_list_t *node = NULL;
    int i = 0;

    for (uuid_list_t cpy = *list; cpy; cpy = (uuid_list_t) cpy->next, i++) {
        if (!uuid_compare(uuid, cpy->uuid)) {
            node = cpy;
            break;
        }
    }
    if (node)
        delete_node(list, i);
}
