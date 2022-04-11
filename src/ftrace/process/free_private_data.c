/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines free_private_data
*/

#include "free_private_data.h"
#include <stddef.h>

void ftrace_process_free_private_data(struct ftrace_process *self)
{
    if (self->private_data != NULL) {
        if (self->private_data_free_func_ptr != NULL) {
            self->private_data_free_func_ptr(self->private_data);
            self->private_data_free_func_ptr = NULL;
        }
        self->private_data = NULL;
    }
}
