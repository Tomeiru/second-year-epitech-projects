/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Declares get_errno_name
*/

#pragma once

#include <stdint.h>

const char *strace_get_errno_name(uint64_t err_number);
