/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Declares list_get_element
*/

#pragma once

#include <stdint.h>
#include <stddef.h>

#define STRACE_LIST_PTR_TYPE_CAST(type, ptr) \
    ((type)(uintptr_t)(const volatile void *)(ptr))

#define STRACE_LIST_GET_ELEMENT(list, element_struct, element_field) \
    STRACE_LIST_PTR_TYPE_CAST(element_struct *, \
        (const volatile char *)(list)-offsetof(element_struct, element_field))
