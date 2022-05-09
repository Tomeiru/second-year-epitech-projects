/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** chained_list
*/

#ifndef CHAINED_LIST_H_
    #define CHAINED_LIST_H_

    #include <stdio.h>
    #include <stdlib.h>

typedef struct node_s {
    void *data;
    struct node_s *next;
} node_t;

    void push_front(node_t **root, void *data);
    void push_at_n(node_t *prev_node, void *data);
    void push_back(node_t **root, void *data);
    int node_len(node_t **root);
    void delete_node(node_t **root, int index);
    void delete_list(node_t **root);

#endif /* !CHAINED_LIST_H_ */