/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
    #define OBJDUMP_H_

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

// PROTOTYPES
int objdump(int ac, char **av);
int objdump_sfour(char *filepath, Elf64_Ehdr *elf);
int objdump_ttwo(char *filepath, Elf32_Ehdr *elf);
void apply_flag(char **flags, char *flag, int idx, char value);
void bfd_flags_sfour(Elf64_Ehdr *elf);
void bfd_flags_ttwo(Elf32_Ehdr *elf);

#endif /* !OBJDUMP_H_ */
