/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines free_private_data
*/

#include "free_private_data.h"
#include <stddef.h>

void strace_process_free_private_data(struct strace_process *self)
{
    if (self->private_data != NULL) {
        if (self->private_data_free_func_ptr != NULL) {
            self->private_data_free_func_ptr(self->private_data);
            self->private_data_free_func_ptr = NULL;
        }
        self->private_data = NULL;
    }
}
