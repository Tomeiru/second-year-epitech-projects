/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** nm
*/

#ifndef NM_H_
    #define NM_H_

// MACRO
    #define UNUSED(x) (void)(x)

// INCLUDE
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <elf.h>
    #include <sys/mman.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>

typedef struct symbol_ttwo_s {
    char *name;
    Elf32_Addr value;
    char bind;
    char type;
    Elf32_Section section_index;
    Elf32_Word section_type;
    Elf32_Xword section_flag;
    char flag;
    struct symbol_ttwo_s *next;
} symbol_ttwo_t;

typedef struct symbol_sfour_s {
    char *name;
    Elf64_Addr value;
    char bind;
    char type;
    Elf64_Section section_index;
    Elf64_Word section_type;
    Elf64_Xword section_flag;
    char flag;
    struct symbol_sfour_s *next;
} symbol_sfour_t;

// PROTOTYPES
int nm_func(int ac, char **av);
int nm_sfour(Elf64_Ehdr *elf, int lib);
int nm_ttwo(Elf32_Ehdr *elf, int lib);
symbol_sfour_t *create_node_sfour(char *name, Elf64_Sym sym, Elf64_Shdr *secs);
void add_to_sorted_list_sfour(symbol_sfour_t **list, symbol_sfour_t *node);
void determine_flag_sfour(symbol_sfour_t **node);
symbol_ttwo_t *create_node_ttwo(char *name, Elf32_Sym sym, Elf32_Shdr *secs);
void add_to_sorted_list_ttwo(symbol_ttwo_t **list, symbol_ttwo_t *node);
void determine_flag_ttwo(symbol_ttwo_t **node);
char *clear_name(char *name);

#endif /* !NM_H_ */
