/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares print_address
*/

#pragma once

#include "../../ftrace.h"
#include <stdint.h>

void ftrace_syscall_print_address(struct ftrace *self, uint64_t address);
