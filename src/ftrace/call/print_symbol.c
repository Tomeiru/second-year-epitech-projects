/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines print_symbol
*/

#include "print_symbol.h"
#include "../get_filename_from_addr.h"
#include "../printf.h"
#include "../translate_symbol_name.h"

void ftrace_call_print_symbol(struct ftrace *self, struct ftrace_process *proc,
    struct ftrace_symbol *symbol, void *address)
{
    if (symbol != NULL)
        ftrace_printf(self, "function %s", ftrace_translate_symbol_name(
            symbol->name));
    else
        ftrace_printf(self, "func_%p@%s", address,
            ftrace_get_filename_from_addr(self, proc, address));
}
