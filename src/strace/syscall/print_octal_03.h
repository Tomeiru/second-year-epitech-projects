/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines print_octal_03
*/

#include "../printf.h"
#include "../zero_extend_signed_to_umax.h"

#define STRACE_SYSCALL_PRINT_OCTAL_03(self, value) \
    strace_printf((self), "%03jo", STRACE_ZERO_EXTEND_SIGNED_TO_UMAX(value))
