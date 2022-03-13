/*
** EPITECH PROJECT, 2022
** objdump
** File description:
** create_sort_list
*/

#include "nm_func.h"

symbol_sfour_t *create_node_sfour(char *name, Elf64_Sym sym, Elf64_Shdr *secs)
{
    symbol_sfour_t *node = malloc(sizeof(symbol_sfour_t));

    node->name = strdup(name + sym.st_name);
    node->value = sym.st_value;
    node->bind = ELF64_ST_BIND(sym.st_info);
    node->type = ELF64_ST_TYPE(sym.st_info);
    node->section_index = sym.st_shndx;
    node->section_type = secs[sym.st_shndx].sh_type;
    node->section_flag = secs[sym.st_shndx].sh_flags;
    node->flag = 'U';
    node->next = NULL;
    return (node);
}

int find_placement_sfour(symbol_sfour_t **list, symbol_sfour_t *node)
{
    char *node_cname = clear_name(node->name);
    char *temp_cname;
    int ret = 0;

    for (symbol_sfour_t *temp = *list; temp != NULL; temp = temp->next) {
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

void add_to_sorted_list_sfour(symbol_sfour_t **list, symbol_sfour_t *node)
{
    int idx = 0;
    symbol_sfour_t *temp = *list;
    symbol_sfour_t *prev = NULL;

    if (*list == NULL) {
        *list = node;
        return;
    }
    idx = find_placement_sfour(list, node);
    for (int i = 0; i < idx; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        node->next = temp;
        temp = node;
    }prev->next = node;
    node->next = temp;
}