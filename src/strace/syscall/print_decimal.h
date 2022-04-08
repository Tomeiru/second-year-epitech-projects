/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_hex
*/

#pragma once

#include "../printf.h"
#include "../sign_extend_unsigned_to_imax.h"

#define STRACE_SYSCALL_PRINT_DECIMAL(self, value) \
    strace_printf(self, "%jd", STRACE_SIGN_EXTEND_UNSIGNED_TO_IMAX(value))
