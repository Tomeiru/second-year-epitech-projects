/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares set_private_data
*/

#pragma once

#include "../../strace.h"

int strace_process_set_private_data(struct strace_process *self,
    void *private_data, void (*private_data_free_func_ptr)(void *));
