/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines build_bug_on_non_zero
*/

#pragma once

// Produces a build error if expression is non-zero, but still allows usage in
// constant expressions
#define STRACE_BUILD_BUG_ON_NON_ZERO(expression) \
    ((int)(__extension__ sizeof(struct { int : (-!!(expression)); })))
