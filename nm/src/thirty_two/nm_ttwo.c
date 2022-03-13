/*
** EPITECH PROJECT, 2022
** objdump
** File description:
** nm_ttwo
*/

#include "nm_func.h"

Elf32_Shdr get_symtab_section_ttwo(Elf32_Ehdr *elf)
{
    Elf32_Shdr *sections = (Elf32_Shdr *)((void *) elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++)
        if (sections[i].sh_type == SHT_SYMTAB) {
            return (sections[i]);
        }
    return (sections[0]);
}

symbol_ttwo_t *create_list_no_lib_ttwo(char *symbol_names, Elf32_Sym *symtab,
Elf32_Shdr *sections, int count)
{
    symbol_ttwo_t *node = NULL;
    symbol_ttwo_t *list = NULL;

    for (int i = 0; i < count; i++) {
        if (symtab[i].st_info != 4) {
            node = create_node_ttwo(symbol_names, symtab[i], sections);
            determine_flag_ttwo(&node);
            add_to_sorted_list_ttwo(&list, node);
        }
    }
    return (list);
}

symbol_ttwo_t *create_list_lib_ttwo(char *symbol_names, Elf32_Sym *symtab,
Elf32_Shdr *sections, int count)
{
    symbol_ttwo_t *node = NULL;
    symbol_ttwo_t *list = NULL;

    for (int i = 0; i < count; i++) {
        if (symtab[i].st_shndx != SHN_ABS) {
            node = create_node_ttwo(symbol_names, symtab[i], sections);
            determine_flag_ttwo(&node);
            add_to_sorted_list_ttwo(&list, node);
        }
    }
    return (list);
}

symbol_ttwo_t *create_list_ttwo(Elf32_Ehdr *elf, int lib)
{
    Elf32_Shdr *sections = (Elf32_Shdr *)((void *) elf + elf->e_shoff);
    Elf32_Shdr symtab_sec = get_symtab_section_ttwo(elf);
    Elf32_Sym *symtab = (Elf32_Sym *)((void *) elf + symtab_sec.sh_offset);
    int count = symtab_sec.sh_size / symtab_sec.sh_entsize;
    char *symbol_names = (char *)((void *)elf +
    sections[symtab_sec.sh_link].sh_offset);

    return (lib == 0 ?
    create_list_lib_ttwo(symbol_names, symtab, sections, count) :
    create_list_no_lib_ttwo(symbol_names, symtab, sections, count));
}

int nm_ttwo(Elf32_Ehdr *elf, int lib)
{
    symbol_ttwo_t *list = create_list_ttwo(elf, lib);

    for (symbol_ttwo_t *temp = list; temp != NULL; temp = temp->next) {
        if (strlen(temp->name) == 0)
            continue;
        if (temp->value != 0 || temp->flag == 't')
            printf("%08x %c %s\n", temp->value, temp->flag, temp->name);
        else
            printf("         %c %s\n", temp->flag, temp->name);
    }return (0);
}