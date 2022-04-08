/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_unsigned
*/

#pragma once

#include "../printf.h"
#include "../zero_extend_signed_to_umax.h"

#define STRACE_SYSCALL_PRINT_UNSIGNED(self, value) strace_printf(self, "%ju", \
    STRACE_ZERO_EXTEND_SIGNED_TO_UMAX(value))
