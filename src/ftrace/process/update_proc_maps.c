/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines update_proc_maps
*/

#include "update_proc_maps.h"
#include "update_proc_maps_part2.h"
#include "../arr_sprintf.h"
#include "../print_error_message/errno.h"
#include <fcntl.h>

static void do_one_entry(fpupm_state_t *s,
    struct ftrace_mmap_entry *entry)
{
    s->fd = open(entry->binary_filename, O_RDONLY);
    s->section = NULL;
    s->found_section = NULL;
    s->shdr = NULL;
    s->new_symbol = (struct ftrace_symbol){};
    if (s->fd < 0)
        return;
    s->elf_handle = elf_begin(s->fd, ELF_C_READ_MMAP, NULL);
    if (s->elf_handle == NULL)
        return;
    do_one_entry_part2(s, entry);
}

static void do_symbols(fpupm_state_t *s)
{
    if (s->self->retrieved_symbols == NULL)
        s->self->retrieved_symbols = my_ftrace_symbol_vector_new();
    for (size_t i = 0; i < s->self->retrieved_symbols->size; ++i)
        free(s->self->retrieved_symbols->data[i].name);
    my_ftrace_symbol_vector_resize(s->self->retrieved_symbols, 0);
    for (size_t i = 0; i < s->self->mmap_entries->size; ++i)
        do_one_entry(s, &s->self->mmap_entries->data[i]);
}

void fpupm_part2(fpupm_state_t *s)
{
    STRACE_ARR_SPRINTF(s->st, s->filename, "/proc/%ju/maps",
        (uintmax_t)s->self->pid);
    s->file = fopen(s->filename, "r");
    if (s->file == NULL) {
        ftrace_print_error_message_errno(s->st, "fopen: %s", s->filename);
        return;
    }
    if (s->self->mmap_entries == NULL)
        s->self->mmap_entries = my_ftrace_mmap_entry_vector_new();
    for (size_t i = 0; i < s->self->mmap_entries->size; ++i)
        free(s->self->mmap_entries->data[i].binary_filename);
    my_ftrace_mmap_entry_vector_resize(s->self->mmap_entries, 0);
    do_loop(s);
    do_symbols(s);
    s->self->proc_maps_up_to_date = true;
}

void ftrace_process_update_proc_maps(struct ftrace *st,
    struct ftrace_process *self)
{
    fpupm_state_t state = {
        .st = st,
        .self = self,
    };

    fpupm_part2(&state);
}
