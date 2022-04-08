/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares print_rlim_t
*/

#include "../../strace.h"
#include <sys/resource.h>

void strace_syscall_print_rlim_t(struct strace *self, rlim_t rlim);
