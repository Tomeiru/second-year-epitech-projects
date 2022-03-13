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

void add_to_sorted_list_sfour(symbol_sfour_t **list, symbol_sfour_t *node)
{
    symbol_sfour_t *prev = NULL;
    char *temp_cname;
    char *node_cname;

    if (*list == NULL) {
        *list = node;
        return;
    }node_cname = clear_name(node->name);
    for (symbol_sfour_t *temp = *list; temp != NULL; temp = temp->next) {
        temp_cname = clear_name(temp->name);
        if (strcasecmp(temp_cname, node_cname) < 0) {
            prev = temp;
            continue;
        }if (strcasecmp(temp_cname, node_cname) > 0) {
            if (prev == NULL) {
                node->next = temp;
                temp = node;
                return;
            }
            prev->next = node;
            node->next = temp;
            return;
        }if (temp->value < node->value)  {
            prev = temp;
            continue;
        }if (prev == NULL) {
            node->next = temp;
            temp = node;
            return;
        }prev->next = node;
        node->next = temp;
        return;
    }prev->next = node;
}