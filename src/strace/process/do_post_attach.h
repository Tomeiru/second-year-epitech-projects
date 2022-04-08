/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares process_do_post_attach
*/

#pragma once

#include "../../strace.h"

void strace_process_do_post_attach(
    struct strace *self, struct strace_process *process, unsigned flags);
