/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines zalloc
*/

#include "zalloc.h"
#include "calloc.h"

void *strace_zalloc(struct strace *self, size_t size)
{
    return (strace_calloc(self, size, 1));
}
