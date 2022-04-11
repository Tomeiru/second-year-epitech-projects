/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines zalloc
*/

#include "zalloc.h"
#include "calloc.h"

void *ftrace_zalloc(struct ftrace *self, size_t size)
{
    return (ftrace_calloc(self, size, 1));
}
