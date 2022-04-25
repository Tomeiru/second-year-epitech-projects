/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares string-related entities
*/

#pragma once

#include "features.h"
#include <stddef.h>

/// Version of strdup that either succeeds or doesn't return
char *my_xstrdup(const char *string) MY_ATTR_NOTHROW MY_ATTR_WARN_UNUSED_RESULT
    MY_ATTR_MALLOC MY_ATTR_NONNULL((1)) MY_ATTR_ACCESS((read_only, 1));

/// Version of strndup that either succeeds or doesn't return
char *my_xstrndup(const char *string, size_t length) MY_ATTR_NOTHROW
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_MALLOC MY_ATTR_NONNULL((1))
    MY_ATTR_ACCESS((read_only, 1, 2));
