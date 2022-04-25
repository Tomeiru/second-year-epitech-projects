/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Declares internal stuff for stdlib.h
*/

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

// Called when one of the xmalloc-like functions fail to allocate
_Noreturn void my_xmalloc_out_of_memory(size_t allocated_bytes);
