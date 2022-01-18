/*
** EPITECH PROJECT, 2022
** PM
** File description:
** int_list_add
*/

#include "int_list.h"
#include "stdlib.h"

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_node_t *node = malloc(sizeof(int_node_t));

    if (node == NULL)
        return (false);
    node->value = elem;
    node->next = (*front_ptr);
    (*front_ptr) = node;
    return (true);
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_node_t *node;
    int_node_t *temp = *(front_ptr);

    if (temp == NULL)
        return (int_list_add_elem_at_front(front_ptr, elem));
    node = malloc(sizeof(int_node_t));
    if (node == NULL)
        return (false);
    node->value = elem;
    node->next = NULL;
    for ( ; temp->next != NULL; temp = temp->next);
    temp->next = node;
    return (true);
}

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
unsigned int position)
{
    int_node_t *node;
    int_node_t *temp = *(front_ptr);
    unsigned int actual_pos = 1;

    if (position == 0)
        return (int_list_add_elem_at_front(front_ptr, elem));
    node = malloc(sizeof(int_node_t));
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