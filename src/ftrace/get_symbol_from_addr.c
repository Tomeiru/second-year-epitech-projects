/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines get_symbol_from_addr
*/

#include "get_symbol_from_addr.h"
#include "process/update_proc_maps.h"

struct ftrace_symbol *ftrace_get_symbol_from_addr(struct ftrace *self,
    struct ftrace_process *proc, void *address)
{
    if (!proc->proc_maps_up_to_date)
        ftrace_process_update_proc_maps(self, proc);
    for (size_t i = 0; i < proc->retrieved_symbols->size; ++i)
        if ((uintptr_t)address ==
            proc->retrieved_symbols->data[i].symbol.st_value)
            return (&proc->retrieved_symbols->data[i]);
    return (NULL);
}
