/*
** EPITECH PROJECT, 2022
** PM
** File description:
** int_list_del
*/

#include "int_list.h"
#include "stdlib.h"

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_node_t *temp = *(front_ptr);

    if ((*front_ptr) == NULL)
        return (false);
    (*front_ptr) = (*front_ptr)->next;
    free(temp);
    return (true);
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_node_t *temp = *(front_ptr);

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

bool int_list_del_elem_at_position(int_list_t *front_ptr, unsigned int position)
{
    int_node_t *temp = *(front_ptr);
    int_node_t *temp_sec = NULL;
    unsigned int actual_pos = 1;

    if (position == 0)
        return (int_list_del_elem_at_front(front_ptr));
    if ((*front_ptr) == NULL || temp->next == NULL)
        return (false);
    for ( ; temp->next != NULL; temp = temp->next) {
        if (actual_pos == position)
            break;
        actual_pos++;
    }if (actual_pos != position)
        return (false);
    temp_sec = temp->next->next;
    free(temp->next);
    temp->next = temp_sec;
    return (true);
}

void int_list_clear(int_list_t *front_ptr)
{
    while (int_list_del_elem_at_front(front_ptr) == true);
}