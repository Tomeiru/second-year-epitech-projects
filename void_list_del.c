/*
** EPITECH PROJECT, 2022
** PM
** File description:
** list_del
*/

#include "list.h"
#include "stdlib.h"

bool list_del_elem_at_front(list_t *front_ptr)
{
    node_t *temp = *(front_ptr);

    if ((*front_ptr) == NULL)
        return (false);
    (*front_ptr) = (*front_ptr)->next;
    free(temp);
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    node_t *temp = *(front_ptr);

    if ((*front_ptr) == NULL)
        return (false);
    if (temp->next == NULL) {
        free(temp);
        (*front_ptr) = NULL;
        return (true);
    }
    for ( ; temp->next->next != NULL; temp = temp->next);
    free(temp->next);
    temp->next = NULL;
    return (true);
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    node_t *temp = *(front_ptr);
    node_t *temp_sec = NULL;
    unsigned int actual_pos = 0;

    if (position == 0)
        return (list_del_elem_at_front(front_ptr));
    if (position + 1 == list_get_size((*front_ptr)))
        return (list_del_elem_at_back(front_ptr));
    if ((*front_ptr) == NULL || temp->next == NULL)
        return (false);
    for ( ; temp->next != NULL; temp = temp->next) {
        actual_pos++;
        if (actual_pos == position)
            break;
    }if (actual_pos != position)
        return (false);
    temp_sec = temp->next->next;
    free(temp->next);
    temp->next = temp_sec;
    return (true);
}

void list_clear(list_t *front)
{
    while (list_del_elem_at_front(front) == true);
}