/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines enum_prot
*/

#pragma once

#include "../../ftrace.h"
#include <sys/mman.h>

static const struct ftrace_enum_data STRACE_SYSCALL_ENUM_PROT_DATA[] = {
    {PROT_NONE, "PROT_NONE"},
    {PROT_READ, "PROT_READ"},
    {PROT_WRITE, "PROT_WRITE"},
    {PROT_EXEC, "PROT_EXEC"},
    {PROT_GROWSDOWN, "PROT_GROWSDOWN"},
    {PROT_GROWSUP, "PROT_GROWSUP"},
};

static const struct ftrace_enum STRACE_SYSCALL_ENUM_PROT = {
    .data = STRACE_SYSCALL_ENUM_PROT_DATA,
    .size = sizeof(STRACE_SYSCALL_ENUM_PROT_DATA) /
        sizeof(STRACE_SYSCALL_ENUM_PROT_DATA[0]),
};
