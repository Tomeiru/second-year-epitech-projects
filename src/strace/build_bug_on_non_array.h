/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines build_bug_on_non_array
*/

#pragma once

#include "build_bug_on_non_zero.h"
#include "is_same_type.h"

// Fails to compile if the passed expression is not an array
#define STRACE_BUILD_BUG_ON_NON_ARRAY(array) \
    STRACE_BUILD_BUG_ON_NON_ZERO(STRACE_IS_SAME_TYPE((array), &(array)[0]))
