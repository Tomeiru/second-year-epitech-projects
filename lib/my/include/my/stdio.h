/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares stdio-related entities
*/

#pragma once

#include "features.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

/// Version of vasprintf that either succeeds or doesn't return
int my_xvasprintf(char **MY_RESTRICT result_string_ptr,
    const char *MY_RESTRICT format, va_list arguments)
    MY_ATTR_FORMAT(printf, 2, 0);

/// Version of asprintf that either succeeds or doesn't return
int my_xasprintf(char **MY_RESTRICT result_string_ptr,
    const char *MY_RESTRICT format, ...) MY_ATTR_FORMAT(printf, 2, 3);

/// Version of fopen that either succeeds or doesn't return
FILE *my_xfopen(const char *MY_RESTRICT filename,
    const char *MY_RESTRICT mode) MY_ATTR_WARN_UNUSED_RESULT;

/// Checks for error, flushes and closes the file and does not return if any of
/// those fail
void my_xfclose(FILE *fp);

static inline void my_fclose_ptr(FILE **ptr)
{
    if (*ptr)
        fclose(*ptr);
}

#define MY_CLEANUP_FCLOSE __attribute__((cleanup(my_fclose_ptr)))
