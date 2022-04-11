/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines cstr_to_uint
*/

#include "cstr_to_uint.h"
#include <inttypes.h>
#include <errno.h>

intmax_t ftrace_cstr_to_uint_up_to(const char *str, uintmax_t max_value)
{
    intmax_t result;
    char *endptr;

    if (*str == '\0')
        return (-1);
    errno = 0;
    result = strtoimax(str, &endptr, 10);
    if ((str == endptr || result < 0 || (uintmax_t)result > max_value ||
        (result == INTMAX_MAX && errno == ERANGE)) || (*endptr != '\0'))
        return (-1);
    return (result);
}
