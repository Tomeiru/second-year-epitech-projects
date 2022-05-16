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

typedef struct name_node_s {
    struct node_s *next;
    char name[MAX_NAME_LENGTH];
} name_node_t;

typedef struct desc_node_s {
    struct node_s *next;
    char desc[MAX_DESCRIPTION_LENGTH];
} desc_node_t;

typedef struct body_node_s {
    struct node_s *next;
    char body[MAX_BODY_LENGTH];
} body_node_t;

typedef struct uuid_node_s {
    struct node_s *next;
    char uuid[16];
} uuid_node_t;

typedef node_t *list_t;
typedef name_node_t *name_list_t;
typedef desc_node_t *desc_list_t;
typedef body_node_t *body_list_t;
typedef uuid_node_t *uuid_list_t;

void push_front(node_t **root, void *data);
void push_at_n(node_t *prev_node, void *data);
void push_back(node_t **root, void *data);
int node_len(list_t list);
void delete_node(node_t **root, int index);
void delete_list(node_t **root);
