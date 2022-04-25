/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** Defines xmalloc_out_of_memory
*/

#include "my/internal/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void my_xmalloc_out_of_memory(size_t allocation_attempt_size)
{
    if (allocation_attempt_size != (size_t)-1)
        fprintf(stderr, "Out of memory while trying to allocate %zu "
            "bytes\n", allocation_attempt_size);
    else
        fputs("Out of memory\n", stderr);
    fflush(stderr);
    exit(84);
}
