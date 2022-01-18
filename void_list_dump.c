/*
** EPITECH PROJECT, 2022
** PM
** File description:
** list_dump
*/

#include "list.h"
#include "stdlib.h"
#include "stdio.h"

void list_dump(list_t list, value_displayer_t val_disp)
{
    if (list == NULL)
        return;
    for ( ; list != NULL; list = list->next)
        val_disp(list->value);
    return;
}