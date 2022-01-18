/*
** EPITECH PROJECT, 2022
** PM
** File description:
** list_get_info
*/

#include "list.h"
#include "stdlib.h"

bool list_is_empty(list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

unsigned int list_get_size(list_t list)
{
    unsigned int ret = 0;

    if (list == NULL)
        return (ret);
    for ( ; list->next != NULL; list = list->next)
        ret++;
    return (++ret);
}

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return (NULL);
    return (list->value);
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return (NULL);
    for ( ; list->next != NULL; list = list->next);
    return (list->value);
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    unsigned int act_pos = 0;

    if (list == NULL)
        return (NULL);
    for ( ; list->next != NULL; list = list->next) {
        if (act_pos == position)
            break;
        act_pos++;
    }if (act_pos != position)
        return (NULL);
    return (list->value);
}