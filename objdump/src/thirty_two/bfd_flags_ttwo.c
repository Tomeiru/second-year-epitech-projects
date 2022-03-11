/*
** EPITECH PROJECT, 2022
** objdump
** File description:
** bfd_flags_ttwo
*/

#include "objdump.h"

static int check_sym_table_ttwo(Elf32_Ehdr *elf)
{
    Elf32_Shdr *sections = (Elf32_Shdr *)((void *)elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++)
        if (sections[i].sh_type == SHT_SYMTAB)
            return (0);
    return (1);
}

static int check_dyn_table_ttwo(Elf32_Ehdr *elf)
{
    Elf32_Shdr *sections = (Elf32_Shdr *)((void *)elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++)
        if (sections[i].sh_type == SHT_DYNAMIC)
            return (0);
    return (1);
}

void bfd_flags_ttwo(Elf32_Ehdr *elf)
{
    char *flags = strdup("0x00000000:\n");
    int value = 0;

    if (elf->e_type == 1)
        apply_flag(&flags, "HAS_RELOC", 9, '1');
    if (elf->e_type == 2)
        apply_flag(&flags, "EXEC_P", 9, '2');
    value = !check_sym_table_ttwo(elf);
    if (value)
        apply_flag(&flags, "HAS_SYMS", 8, '1');
    if (elf->e_type == 3)
        apply_flag(&flags, "DYNAMIC", 8, '5');
    value = !check_dyn_table_ttwo(elf);
    if (value)
        apply_flag(&flags, "D_PAGED", 7, '1');
    printf("%s\n", flags);
    free(flags);
}