/*
** EPITECH PROJECT, 2022
** objdump
** File description:
** create_sort_list
*/

#include "nm_func.h"

symbol_ttwo_t *create_node_ttwo(char *name, Elf32_Sym sym, Elf32_Shdr *secs)
{
    symbol_ttwo_t *node = malloc(sizeof(symbol_ttwo_t));

    node->name = strdup(name + sym.st_name);
    node->value = sym.st_value;
    node->bind = ELF32_ST_BIND(sym.st_info);
    node->type = ELF32_ST_TYPE(sym.st_info);
    node->section_index = sym.st_shndx;
    node->section_type = secs[sym.st_shndx].sh_type;
    node->section_flag = secs[sym.st_shndx].sh_flags;
    node->flag = 'U';
    node->next = NULL;
    return (node);
}

int find_placement_ttwo(symbol_ttwo_t **list, symbol_ttwo_t *node)
{
    char *node_cname = clear_name(node->name);
    char *temp_cname;
    int ret = 0;

    for (symbol_ttwo_t *temp = *list; temp != NULL; temp = temp->next) {
        temp_cname = clear_name(temp->name);
        if (strcasecmp(temp_cname, node_cname) < 0) {
            ret++;
            continue;
        }if (strcasecmp(temp_cname, node_cname) > 0)
            return (ret);
        ret += temp->value < node->value ? 1 : 0;
        if (temp->value < node->value)
            continue;
        return (ret);
    }
    return (ret);
}

void add_to_sorted_list_ttwo(symbol_ttwo_t **list, symbol_ttwo_t *node)
{
    int idx = 0;
    symbol_ttwo_t *temp = *list;
    symbol_ttwo_t *prev = NULL;

    if (*list == NULL) {
        *list = node;
        return;
    }
    idx = find_placement_ttwo(list, node);
    for (int i = 0; i < idx; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        node->next = temp;
        temp = node;
        return;
    }prev->next = node;
    node->next = temp;
}