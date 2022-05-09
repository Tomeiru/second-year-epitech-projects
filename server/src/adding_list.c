/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** adding_list
*/

#include "chained_list.h"

void push_front(node_t **root, void *data)
{
    node_t *node = malloc(sizeof(node_t));

    node->data = data;
    node->next = *root;
    *root = node;
}

void push_at_n(node_t *prev_node, void *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (prev_node == NULL) {
        free(node);
        return;
    }
    node->data = data;
    node->next = prev_node->next;
    prev_node->next = node;
}

void push_back(node_t **root, void *data)
{
    node_t *node = malloc(sizeof(node_t));
    node_t *leaf = *root;

    node->data = data;
    node->next = NULL;
    if (*root == NULL) {
        *root = node;
        return;
    }
    for (; leaf->next; leaf = leaf->next);
    leaf->next = node;
}
