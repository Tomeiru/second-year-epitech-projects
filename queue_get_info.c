/*
** EPITECH PROJECT, 2022
** PM
** File description:
** queue_get_info
*/

#include "queue.h"

unsigned int queue_get_size(queue_t queue)
{
    return (list_get_size(queue));
}

bool queue_is_empty(queue_t queue)
{
    return (list_is_empty(queue));
}

void *queue_front(queue_t queue)
{
    return (list_get_elem_at_front(queue));
}