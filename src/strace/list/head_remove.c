/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines list_head_remove
*/

#include "head_remove.h"
#include "is_empty.h"
#include "remove.h"
#include <stddef.h>

struct strace_list_item *strace_list_head_remove(
    struct strace_list_item *list_head)
{
    struct strace_list_item *result = strace_list_is_empty(list_head) ? NULL :
        list_head->prev;

    if (result != NULL)
        strace_list_remove(result);
    return (result);
}
