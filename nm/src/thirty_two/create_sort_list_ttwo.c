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

void add_to_sorted_list_ttwo(symbol_ttwo_t **list, symbol_ttwo_t *node)
{
    symbol_ttwo_t *prev = NULL;
    char *temp_cname;
    char *node_cname;

    if (*list == NULL) {
        *list = node;
        return;
    }node_cname = clear_name(node->name);
    for (symbol_ttwo_t *temp = *list; temp != NULL; temp = temp->next) {
        temp_cname = clear_name(temp->name);
        if (strcasecmp(temp_cname, node_cname) < 0) {
            prev = temp;
            continue;
        }
        if (strcasecmp(temp_cname, node_cname) > 0) {
            if (prev == NULL) {
                node->next = temp;
                temp = node;
                return;
            }
            prev->next = node;
            node->next = temp;
            return;
        }
        if (temp->value < node->value)  {
            prev = temp;
            continue;
        }
        if (prev == NULL) {
            node->next = temp;
            temp = node;
            return;
        }
        prev->next = node;
        node->next = temp;
        return;
    }
    prev->next = node;
}