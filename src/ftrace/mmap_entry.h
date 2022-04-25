/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines mmap_entry
*/

#pragma once

#include <stdint.h>

struct ftrace_mmap_entry {
    uintmax_t address_start;
    uintmax_t address_end;
    uintmax_t mmap_offset;
    unsigned long major;
    unsigned long minor;
    char *binary_filename;
};
