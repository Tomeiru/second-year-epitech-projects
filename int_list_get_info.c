/*
** EPITECH PROJECT, 2022
** PM
** File description:
** int_list_get_info
*/

#include "int_list.h"
#include "stdlib.h"

bool int_list_is_empty(int_list_t list)
{
    if (list == NULL)
        return (true);
    return (false);
}

unsigned int int_list_get_size(int_list_t list)
{
    unsigned int ret = 0;

    if (list == NULL)
        return (ret);
    for ( ; list->next != NULL; list = list->next)
        ret++;
    return (++ret);
}

int int_list_get_elem_at_front(int_list_t list)
{
    if (list == NULL)
        return (0);
    return (list->value);
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (list == NULL)
        return (0);
    for ( ; list->next != NULL; list = list->next);
    return (list->value);
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    unsigned int act_pos = 0;

    if (list == NULL)
        return (0);
    for ( ; list->next != NULL; list = list->next) {
        if (act_pos == position)
            break;
        act_pos++;
    }if (act_pos != position)
        return (0);
    return (list->value);
}