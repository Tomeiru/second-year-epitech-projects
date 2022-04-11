/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines set_private_data
*/

#include "set_private_data.h"
#include <stddef.h>

int ftrace_process_set_private_data(struct ftrace_process *self,
    void *private_data, void (*private_data_free_func_ptr)(void *))
{
    if (self->private_data != NULL)
        return (-1);
    self->private_data_free_func_ptr = private_data_free_func_ptr;
    self->private_data = private_data;
    return (0);
}
