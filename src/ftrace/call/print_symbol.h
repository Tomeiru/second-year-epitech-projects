/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_symbol
*/

#pragma once

#include "../../ftrace.h"

void ftrace_call_print_symbol(struct ftrace *self, struct ftrace_process *proc,
    struct ftrace_symbol *symbol, void *address);
