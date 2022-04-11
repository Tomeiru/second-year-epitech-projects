/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines list_head_remove
*/

#include "head_remove.h"
#include "is_empty.h"
#include "remove.h"
#include <stddef.h>

struct ftrace_list_item *ftrace_list_head_remove(
    struct ftrace_list_item *list_head)
{
    struct ftrace_list_item *result =
        ftrace_list_is_empty(list_head) ? NULL : list_head->prev;

    if (result != NULL)
        ftrace_list_remove(result);
    return (result);
}
