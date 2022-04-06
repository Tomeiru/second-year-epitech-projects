/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares get_signal_name
*/

#pragma once

#include "../strace.h"

const char *strace_get_signal_name(struct strace *self, unsigned signal);
