/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares stdlib-related entities
*/

#pragma once

#include "features.h"
#include <stdlib.h>
#include <stddef.h>

// Version of malloc that either succeeds or doesn't return
void *my_xmalloc(size_t size) MY_ATTR_NOTHROW MY_ATTR_MALLOC
    MY_ATTR_ALLOC_SIZE((1)) MY_ATTR_WARN_UNUSED_RESULT;

// Version of calloc that either succeeds or doesn't return
void *my_xcalloc(size_t num_members, size_t size) MY_ATTR_NOTHROW MY_ATTR_MALLOC
    MY_ATTR_ALLOC_SIZE((1, 2)) MY_ATTR_WARN_UNUSED_RESULT;

// Version of realloc that either succeeds or doesn't return
void *my_xrealloc(void *ptr, size_t size) MY_ATTR_NOTHROW
    MY_ATTR_ALLOC_SIZE((2)) MY_ATTR_WARN_UNUSED_RESULT;

static inline void my_free_ptr(void *ptr)
{
    free(*(void **)ptr);
}

#define MY_CLEANUP_FREE __attribute__((cleanup(my_free_ptr)))
