/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Part 2 of update_proc_maps
*/

#pragma once

#include "update_proc_maps.h"
#include "my/string.h"
#include <stdio.h>
#include <limits.h>

typedef struct fpupm_state {
    struct ftrace *st;
    struct ftrace_process *self;
    char filename[sizeof("/proc/340282366920938463463374607431768211456/maps")];
    FILE *file;
    char buffer[PATH_MAX + 800];
    char binary_path[PATH_MAX + 800];
    struct ftrace_mmap_entry entry;
    int fd;
    Elf *elf_handle;
    Elf_Scn *section;
    Elf_Scn *found_section;
    GElf_Shdr *shdr;
    GElf_Shdr shdr_stack;
    Elf_Data *sym_data;
    size_t symbol_count;
    struct ftrace_symbol new_symbol;
} fpupm_state_t;

static void do_loop(fpupm_state_t *s)
{
    while (fgets(s->buffer, sizeof(s->buffer), s->file) != NULL) {
        if (sscanf(s->buffer, "%jx-%jx %*c%*c%*c%*c %jx %jx:%jx %*d %[^\n]",
            &s->entry.address_start, &s->entry.address_end,
            &s->entry.mmap_offset, &s->entry.major, &s->entry.minor,
            s->binary_path) != 6 || (s->entry.address_end <
            s->entry.address_start))
            continue;
        s->entry.binary_filename = my_xstrdup(s->binary_path);
        my_ftrace_mmap_entry_vector_append_single(s->self->mmap_entries,
            s->entry);
    }
    fclose(s->file);
}

static void do_one_entry_loop_it(fpupm_state_t *s,
    struct ftrace_mmap_entry *entry, size_t i)
{
    if (gelf_getsym(s->sym_data, i, &s->new_symbol.symbol) == NULL)
        return;
    free(s->new_symbol.name);
    s->new_symbol.name = my_xstrdup(elf_strptr(s->elf_handle, s->shdr->sh_link,
        s->new_symbol.symbol.st_name));
    if (s->new_symbol.name == NULL || (s->new_symbol.name[0] == '\0'))
        return;
    if (s->new_symbol.symbol.st_value < (entry->mmap_offset) ||
        s->new_symbol.symbol.st_value > (entry->mmap_offset +
       (entry->address_end - entry->address_start)))
        return;
    s->new_symbol.symbol.st_value += entry->address_start -
        entry->mmap_offset;
    my_ftrace_symbol_vector_append_single(s->self->retrieved_symbols,
        s->new_symbol);
    s->new_symbol.name = NULL;
}

static void do_one_entry_part3(fpupm_state_t *s,
    struct ftrace_mmap_entry *entry)
{
    s->symbol_count = (s->shdr->sh_size / gelf_fsize(s->elf_handle, ELF_T_SYM,
        1, s->sym_data->d_version));
    for (size_t i = 0; i < s->symbol_count; ++i)
        do_one_entry_loop_it(s, entry, i);
    free(s->new_symbol.name);
    elf_end(s->elf_handle);
}

static void do_one_entry_part2(fpupm_state_t *s,
    struct ftrace_mmap_entry *entry)
{
    while (true) {
        s->section = elf_nextscn(s->elf_handle, s->section);
        if (s->section == NULL)
            break;
        s->shdr = gelf_getshdr(s->section, &s->shdr_stack);
        if (s->shdr == NULL)
            continue;
        if (s->shdr->sh_type == SHT_SYMTAB)
            s->found_section = s->section;
        if (s->shdr->sh_type == SHT_DYNSYM && s->found_section == NULL)
            s->found_section = s->section;
    }
    if (s->found_section == NULL)
        return ((void)elf_end(s->elf_handle));
    s->shdr = gelf_getshdr(s->found_section, &s->shdr_stack);
    s->sym_data = elf_getdata(s->found_section, NULL);
    if (s->sym_data == NULL)
        return ((void)elf_end(s->elf_handle));
    do_one_entry_part3(s, entry);
}
