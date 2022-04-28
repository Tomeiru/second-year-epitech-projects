/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares process_do_post_attach
*/

#pragma once

#include "../../ftrace.h"

void ftrace_process_do_post_attach(struct ftrace *self,
    struct ftrace_process *process, unsigned flags);
