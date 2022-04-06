/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines get_errno_name
*/

#include "get_errno_name.h"
#include "errnostrs.h"

const char *strace_get_errno_name(uint64_t err_number)
{
    return (err_number < STRACE_ERRNOSTRS_COUNT ?
        STRACE_ERRNOSTRS[err_number] : NULL);
}
