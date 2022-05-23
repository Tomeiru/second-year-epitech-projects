/*
** EPITECH PROJECT, 2022
** ftp
** File description:
** chained_list
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "buffer_sizes.h"

typedef struct node_s {
    struct node_s *next;
    void *data;
} node_t;

typedef struct uuid_node_s {
    struct node_s *next;
    char uuid[16];
} uuid_node_t;

typedef node_t *list_t;
typedef uuid_node_t *uuid_list_t;

void push_front(node_t **root, void *data);
void push_at_n(node_t *prev_node, void *data);
void push_back(node_t **root, void *data);
void push_node_front(node_t **root, node_t *node);
void push_node_back(node_t **root, node_t *node);

int node_len(list_t list);
void delete_node(node_t **root, int index);
void delete_node_with_data(list_t *list, void *data);
void delete_list(node_t **root);
