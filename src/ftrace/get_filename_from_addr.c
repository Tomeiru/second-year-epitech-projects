/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines get_filename_from_addr
*/

#include "get_filename_from_addr.h"
#include "process/update_proc_maps.h"

const char *ftrace_get_filename_from_addr(struct ftrace *self,
    struct ftrace_process *proc, void *address)
{
    uintptr_t addr_i = (uintptr_t)address;

    if (!proc->proc_maps_up_to_date)
        ftrace_process_update_proc_maps(self, proc);
    for (size_t i = 0; i < proc->mmap_entries->size; ++i)
        if (addr_i > proc->mmap_entries->data[i].address_start &&
            addr_i < proc->mmap_entries->data[i].address_end)
            return (proc->mmap_entries->data[i].binary_filename);
    return ("unknown");
}
