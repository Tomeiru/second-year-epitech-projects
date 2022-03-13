/*
** EPITECH PROJECT, 2022
** objdump
** File description:
** determine_flag_sfour
*/

#include "nm_func.h"

void determine_flag_sfour_fot(symbol_sfour_t **node, int toggle)
{
    symbol_sfour_t *temp = *node;

    if (temp->section_type == SHT_PROGBITS
    && temp->section_flag == (SHF_ALLOC | SHF_WRITE) && toggle == 0) {
        (*node)->flag = 'D';
        toggle = 1;
    }
    if (temp->section_type == SHT_PROGBITS
    && temp->section_flag == (SHF_ALLOC | SHF_EXECINSTR) && toggle == 0) {
        (*node)->flag = 'T';
        toggle = 1;
    }
    if (toggle == 0)
        (*node)->flag = 'd';
    (*node)->flag += (temp->bind == STB_LOCAL && (*node)->flag != 'd' ? 32 : 0);

}

void determine_flag_sfour_thd(symbol_sfour_t **node, int toggle)
{
    symbol_sfour_t *temp = *node;

    if (temp->section_type == SHT_NOBITS
    && temp->section_flag == (SHF_ALLOC | SHF_WRITE) && toggle == 0) {
        (*node)->flag = 'B';
        toggle = 1;
    }if ((temp->section_type == SHT_PROGBITS || temp->section_type == SHT_NOTE)
    && temp->section_flag == SHF_ALLOC) {
        (*node)->flag = 'R';
        toggle = 1;
    }
    if (temp->section_type == SHT_DYNAMIC) {
        (*node)->flag = 'D';
        toggle = 1;
    }
    determine_flag_sfour_fot(node, toggle);

}

void determine_flag_sfour_snd(symbol_sfour_t **node, int toggle)
{
    symbol_sfour_t *temp = *node;

    if (temp->section_index == SHN_UNDEF && toggle == 0) {
        (*node)->flag = 'U';
        toggle = 1;
    }if (temp->section_index == SHN_ABS && toggle == 0) {
        (*node)->flag = 'A';
        toggle = 1;
    }if (temp->section_index == SHN_COMMON && toggle == 0) {
        (*node)->flag = 'C';
        toggle = 1;
    }
    determine_flag_sfour_thd(node, toggle);
}

void determine_flag_sfour(symbol_sfour_t **node)
{
    symbol_sfour_t *temp = *node;
    int toggle = 0;

    if (temp->bind == STB_GNU_UNIQUE) {
        (*node)->flag = 'u';
        toggle = 1;
    }if (temp->bind == STB_WEAK && toggle == 0) {
        (*node)->flag = (temp->section_index == SHN_UNDEF) ? 'w' : 'W';
        toggle = 1;
    }if (temp->bind == STB_WEAK && temp->type == STT_OBJECT && toggle == 0) {
        (*node)->flag = (temp->section_index == SHN_UNDEF) ? 'v' : 'V';
        toggle = 1;
    }
    determine_flag_sfour_snd(node, toggle);
}