/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_address
*/

#pragma once

#include "../../strace.h"
#include <stdint.h>

void strace_syscall_print_address(struct strace *self, uint64_t address);
