/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines is_same_type
*/

#pragma once

// Determines whether two expressions have the same type, though it does not
// determine whether they have different qualifiers
#define STRACE_IS_SAME_TYPE(a, b) \
    __builtin_types_compatible_p(__typeof__(a), __typeof__(b))
