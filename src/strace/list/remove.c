/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines list_remove
*/

#include "remove.h"
#include "is_empty.h"
#include <stddef.h>

void strace_list_remove(struct strace_list_item *list)
{
    if (list->next == NULL || list->prev == NULL ||
        strace_list_is_empty(list))
        return;
    list->prev->next = list->next;
    list->next->prev = list->prev;
    list->prev = list;
    list->next = list;
}
