/*
** EPITECH PROJECT, 2022
** PM
** File description:
** list_add
*/

#include "list.h"
#include "stdlib.h"

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
        return (false);
    node->value = elem;
    node->next = (*front_ptr);
    (*front_ptr) = node;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    node_t *node;
    node_t *temp = *(front_ptr);

    if (temp == NULL)
        return (list_add_elem_at_front(front_ptr, elem));
    node = malloc(sizeof(node_t));
    if (node == NULL)
        return (false);
    node->value = elem;
    node->next = NULL;
    for ( ; temp->next != NULL; temp = temp->next);
    temp->next = node;
    return (true);
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    node_t *node;
    node_t *temp = *(front_ptr);
    unsigned int actual_pos = 1;

    if (position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    node = malloc(sizeof(node_t));
    if (node == NULL)
        return (false);
    for ( ; temp->next != NULL; temp = temp->next) {
        if (actual_pos == position)
            break;
        actual_pos++;
    }if (actual_pos != position)
        return (false);
    node->value = elem;
    node->next = temp->next;
    temp->next = node;
    return (true);
}