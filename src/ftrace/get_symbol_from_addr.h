/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares get_symbol_from_addr
*/

#pragma once

#include "../ftrace.h"

struct ftrace_symbol *ftrace_get_symbol_from_addr(struct ftrace *self,
    struct ftrace_process *proc, void *address);
