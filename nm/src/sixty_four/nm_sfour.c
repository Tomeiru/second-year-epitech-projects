/*
** EPITECH PROJECT, 2022
** objdump
** File description:
** nm_sfour
*/

#include "nm_func.h"

Elf64_Shdr get_symtab_section_sfour(Elf64_Ehdr *elf)
{
    Elf64_Shdr *sections = (Elf64_Shdr *)((void *) elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++)
        if (sections[i].sh_type == SHT_SYMTAB) {
            return (sections[i]);
        }
    return (sections[0]);
}

symbol_sfour_t *create_list_no_lib_sfour(char *symbol_names, Elf64_Sym *symtab,
Elf64_Shdr *sections, int count)
{
    symbol_sfour_t *node = NULL;
    symbol_sfour_t *list = NULL;

    for (int i = 0; i < count; i++) {
        if (symtab[i].st_info != 4) {
            node = create_node_sfour(symbol_names, symtab[i], sections);
            determine_flag_sfour(&node);
            add_to_sorted_list_sfour(&list, node);
        }
    }
    return (list);
}

symbol_sfour_t *create_list_lib_sfour(char *symbol_names, Elf64_Sym *symtab,
Elf64_Shdr *sections, int count)
{
    symbol_sfour_t *node = NULL;
    symbol_sfour_t *list = NULL;

    for (int i = 0; i < count; i++) {
        if (symtab[i].st_shndx != SHN_ABS) {
            node = create_node_sfour(symbol_names, symtab[i], sections);
            determine_flag_sfour(&node);
            add_to_sorted_list_sfour(&list, node);
        }
    }
    return (list);
}

symbol_sfour_t *create_list_sfour(Elf64_Ehdr *elf, int lib)
{
    Elf64_Shdr *sections = (Elf64_Shdr *)((void *) elf + elf->e_shoff);
    Elf64_Shdr symtab_sec = get_symtab_section_sfour(elf);
    Elf64_Sym *symtab = (Elf64_Sym *)((void *) elf + symtab_sec.sh_offset);
    int count = symtab_sec.sh_size / symtab_sec.sh_entsize;
    char *symbol_names = (char *)((void *)elf +
    sections[symtab_sec.sh_link].sh_offset);

    return (lib == 0 ?
    create_list_lib_sfour(symbol_names, symtab, sections, count) :
    create_list_no_lib_sfour(symbol_names, symtab, sections, count));
}

int nm_sfour(Elf64_Ehdr *elf, int lib)
{
    symbol_sfour_t *list = create_list_sfour(elf, lib);

    for (symbol_sfour_t *temp = list; temp != NULL; temp = temp->next) {
        if (strlen(temp->name) == 0)
            continue;
        if (temp->value != 0 || temp->flag == 't')
            printf("%016lx %c %s\n", temp->value, temp->flag, temp->name);
        else
            printf("                 %c %s\n", temp->flag, temp->name);
    }return (0);
}