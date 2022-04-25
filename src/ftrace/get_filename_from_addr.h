/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declare get_filename_from_addr
*/

#pragma once

#include "../ftrace.h"

const char *ftrace_get_filename_from_addr(struct ftrace *self,
    struct ftrace_process *proc, void *address);
