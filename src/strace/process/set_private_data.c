/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines set_private_data
*/

#include "set_private_data.h"
#include <stddef.h>

int strace_process_set_private_data(struct strace_process *self,
    void *private_data, void (*private_data_free_func_ptr)(void *))
{
    if (self->private_data != NULL)
        return (-1);
    self->private_data_free_func_ptr = private_data_free_func_ptr;
    self->private_data = private_data;
    return (0);
}
