/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares set_private_data
*/

#pragma once

#include "../../ftrace.h"

int ftrace_process_set_private_data(struct ftrace_process *self,
    void *private_data, void (*private_data_free_func_ptr)(void *));
