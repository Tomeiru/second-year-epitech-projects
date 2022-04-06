/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_hex
*/

#pragma once

#include "../printf.h"
#include "../zero_extend_signed_to_umax.h"

#define STRACE_SYSCALL_PRINT_HEX(self, value) strace_printf(self, "%#jx", \
    STRACE_ZERO_EXTEND_SIGNED_TO_UMAX(value))
