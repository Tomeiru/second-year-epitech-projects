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

int node_len(node_t **root)
{
    int count = 0;
    node_t *tmp = *root;

    for (; tmp; tmp = tmp->next)
        count++;

    return (count);
}

void delete_list(node_t **root)
{
    int len = node_len(root);

    for (int i = 0; i < len; i++)
        delete_node(root, 0);
}
