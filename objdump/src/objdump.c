/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** objdump
*/

#include "objdump.h"

int check_elf(unsigned char *elf, int *architecture, unsigned short type, int len)
{
    if (len < 452)
        return (0);
    if (elf[EI_MAG0] != ELFMAG0 || elf[EI_MAG1] != ELFMAG1 ||
    elf[EI_MAG2] != ELFMAG2 || elf[EI_MAG3] != ELFMAG3)
        return (0);
    *architecture = elf[EI_CLASS];
    if (*architecture == 0 || elf[EI_VERSION] != EV_CURRENT || type < 1 ||
    type > 3)
        return (0);
    return (1);
}

Elf64_Ehdr *elf_reader(char *filepath, int *len)
{
    int fd = open(filepath, O_RDONLY);
    struct stat stats;
    Elf64_Ehdr *elf;

    if (fd == -1 || stat(filepath, &stats) || !stats.st_size)
        return (NULL);
    elf = mmap(NULL, stats.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (elf == (void *)-1)
        return (NULL);
    *len = stats.st_size;
    close(fd);
    return (elf);
}

int check_sym_table_sfour(Elf64_Ehdr *elf)
{
    Elf64_Shdr *sections = (Elf64_Shdr *)((void *)elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++)
        if (sections[i].sh_type == SHT_SYMTAB)
            return (0);
    return (1);
}

int check_dyn_table_sfour(Elf64_Ehdr *elf)
{
    Elf64_Shdr *sections = (Elf64_Shdr *)((void *)elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++)
        if (sections[i].sh_type == SHT_DYNAMIC)
            return (0);
    return (1);
}

int check_sym_table_ttwo(Elf32_Ehdr *elf)
{
    Elf32_Shdr *sections = (Elf32_Shdr *)((void *)elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++)
        if (sections[i].sh_type == SHT_SYMTAB)
            return (0);
    return (1);
}

int check_dyn_table_ttwo(Elf32_Ehdr *elf)
{
    Elf32_Shdr *sections = (Elf32_Shdr *)((void *)elf + elf->e_shoff);

    for (int i = 0; i < elf->e_shnum; i++)
        if (sections[i].sh_type == SHT_DYNAMIC)
            return (0);
    return (1);
}

void bfd_flags_sfour(Elf64_Ehdr *elf)
{
    char *flags = strdup("0x00000000:\n");

    if (elf->e_type == 1) {
        flags[9] = '1';
        flags = realloc(flags, strlen(flags) + 10);
        strcat(flags, "HAS_RELOC");
    }
    if (elf->e_type == 2) {
        flags[9] = '2';
        flags = realloc(flags, strlen(flags) + 7);
        strcat(flags, "EXEC_P");
    }
    if (!check_sym_table_sfour(elf)) {
        flags[8] = '1';
        if (strlen(flags) > 13) {
            flags = realloc(flags, strlen(flags) + 11);
            strcat(flags, ", HAS_SYMS");
        }
        else {
            flags = realloc(flags, strlen(flags) + 9);
            strcat(flags, "HAS_SYMS");
        }
    }
    if (elf->e_type == 3) {
        flags[8] = '5';
        if (strlen(flags) > 13) {
            flags = realloc(flags, strlen(flags) + 10);
            strcat(flags, ", DYNAMIC");
        }
        else {
            flags = realloc(flags, strlen(flags) + 8);
            strcat(flags, "DYNAMIC");
        }
    }
    if (!check_dyn_table_sfour(elf)) {
        flags[7] = '1';
        if (strlen(flags) > 13) {
            flags = realloc(flags, strlen(flags) + 10);
            strcat(flags, ", D_PAGED");
        }
        else {
            flags = realloc(flags, strlen(flags) + 8);
            strcat(flags, "D_PAGED");
        }
    }
    printf("%s\n", flags);
    free(flags);
}

void bfd_flags_ttwo(Elf32_Ehdr *elf)
{
    char *flags = strdup("0x00000000:\n");

    if (elf->e_type == 1) {
        flags[9] = '1';
        flags = realloc(flags, strlen(flags) + 10);
        strcat(flags, "HAS_RELOC");
    }
    if (elf->e_type == 2) {
        flags[9] = '2';
        flags = realloc(flags, strlen(flags) + 7);
        strcat(flags, "EXEC_P");
    }
    if (!check_sym_table_ttwo(elf)) {
        flags[8] = '1';
        if (strlen(flags) > 13) {
            flags = realloc(flags, strlen(flags) + 11);
            strcat(flags, ", HAS_SYMS");
        }
        else {
            flags = realloc(flags, strlen(flags) + 9);
            strcat(flags, "HAS_SYMS");
        }
    }
    if (elf->e_type == 3) {
        flags[8] = '5';
        if (strlen(flags) > 13) {
            flags = realloc(flags, strlen(flags) + 10);
            strcat(flags, ", DYNAMIC");
        }
        else {
            flags = realloc(flags, strlen(flags) + 8);
            strcat(flags, "DYNAMIC");
        }
    }
    if (!check_dyn_table_ttwo(elf)) {
        flags[7] = '1';
        if (strlen(flags) > 13) {
            flags = realloc(flags, strlen(flags) + 10);
            strcat(flags, ", D_PAGED");
        }
        else {
            flags = realloc(flags, strlen(flags) + 8);
            strcat(flags, "D_PAGED");
        }
    }
    printf("%s\n", flags);
    free(flags);
}

void print_fflag_sfour(char *filepath, Elf64_Ehdr *elf)
{
    printf("\n%s:     file format elf64-x86-64\n", filepath);
    printf("architecture: i386:x86-64, flags ");
    bfd_flags_sfour(elf);
    printf("start address 0x%016lx", elf->e_entry);
    printf("\n\n");
}

void print_fflag_ttwo(char *filepath, Elf32_Ehdr *elf)
{
    printf("\n%s:     file format elf32-i386\n", filepath);
    printf("architecture: i386, flags ");
    bfd_flags_ttwo(elf);
    printf("start address 0x%08x", elf->e_entry);
    printf("\n\n");
}

void print_line_sfour(Elf64_Shdr section, unsigned char *str, unsigned int i)
{
    int toggle = 0;
    unsigned int index = i;

    printf(" %04lx ", section.sh_addr + i);
    for (unsigned int y = 0; y < 19; y++) {
        if ((y + 1) % 5 == 0 && toggle == 0 && !(i < section.sh_size)) {
            printf(" ");
            toggle = 1;
        }
        else if ((y + 1) % 5 == 0)
            printf(" ");
        else if (toggle == 1)
            printf("  ");
        else if (i < section.sh_size) {
            printf("%02hhx", str[i++]);
        }
        else {
            printf("  ");
        }
    }
    i = index;
    printf("  ");
    for (unsigned int y = 0; y++ < 16; i++) {
        if (i >= section.sh_size)
            printf(" ");
        else if (isprint(str[i]))
            printf("%c", str[i]);
        else
            printf(".");
    }
    printf("\n");
}

void print_content_sfour(Elf64_Ehdr *elf, Elf64_Shdr section)
{
    unsigned char *str = (unsigned char *)elf + section.sh_offset;

    for (unsigned int i = 0; i < section.sh_size; i += 16)
        print_line_sfour(section, str, i);
}

void print_shname_sfour(Elf64_Ehdr *elf)
{
    Elf64_Shdr *sections = (Elf64_Shdr *)((void *)elf + elf->e_shoff);
    Elf64_Shdr *str_table = &sections[elf->e_shstrndx];
    char *str = (void *)elf + str_table->sh_offset;
    char *name = NULL;

    for (int i = 0; i < elf->e_shnum; i++) {
        name = str + sections[i].sh_name;
        if (sections[i].sh_type != SHT_NOBITS && sections[i].sh_size > 0 &&
        strcmp(name, ".symtab") && strcmp(name, ".strtab") &&
        strcmp(name, ".shstrtab") && strcmp(name, ".rela.text")
        && strcmp(name, ".rela.debug_info") && strcmp(name, ".rela.debug_line")
        && strcmp(name, ".rela.debug_aranges")
        && strcmp(name, ".rela.eh_frame")) {
            printf("Contents of section %s:\n", name);
            print_content_sfour(elf, sections[i]);
        }
    }
}

void print_line_ttwo(Elf32_Shdr section, unsigned char *str, unsigned int i)
{
    int toggle = 0;
    unsigned int index = i;

    printf(" %04x ", section.sh_addr + i);
    for (unsigned int y = 0; y < 19; y++) {
        if ((y + 1) % 5 == 0 && toggle == 0 && !(i < section.sh_size)) {
            printf(" ");
            toggle = 1;
        }
        else if ((y + 1) % 5 == 0)
            printf(" ");
        else if (toggle == 1)
            printf("  ");
        else if (i < section.sh_size) {
            printf("%02hhx", str[i++]);
        }
        else {
            printf("  ");
        }
    }
    i = index;
    printf("  ");
    for (unsigned int y = 0; y++ < 16; i++) {
        if (i >= section.sh_size)
            printf(" ");
        else if (isprint(str[i]))
            printf("%c", str[i]);
        else
            printf(".");
    }
    printf("\n");
}

void print_content_ttwo(Elf32_Ehdr *elf, Elf32_Shdr section)
{
    unsigned char *str = (unsigned char *)elf + section.sh_offset;

    for (unsigned int i = 0; i < section.sh_size; i += 16)
        print_line_ttwo(section, str, i);
}

void print_shname_ttwo(Elf32_Ehdr *elf)
{
    Elf32_Shdr *sections = (Elf32_Shdr *)((void *)elf + elf->e_shoff);
    Elf32_Shdr *str_table = &sections[elf->e_shstrndx];
    char *str = (void *)elf + str_table->sh_offset;
    char *name = NULL;

    for (int i = 0; i < elf->e_shnum; i++) {
        name = str + sections[i].sh_name;
        if (sections[i].sh_type != SHT_NOBITS && sections[i].sh_size > 0 &&
        strcmp(name, ".symtab") && strcmp(name, ".strtab") &&
        strcmp(name, ".shstrtab")) {
            printf("Contents of section %s:\n", name);
            print_content_ttwo(elf, sections[i]);
        }
    }
}

void print_sflag_sfour(Elf64_Ehdr *elf)
{
    print_shname_sfour(elf);
}

void print_sflag_ttwo(Elf32_Ehdr *elf)
{
    print_shname_ttwo(elf);
}

int objdump_sfour(char *filepath, Elf64_Ehdr *elf)
{
    print_fflag_sfour(filepath, elf);
    print_sflag_sfour(elf);
    return (0);
}

int objdump_ttwo(char *filepath, Elf32_Ehdr *elf)
{
    print_fflag_ttwo(filepath, elf);
    print_sflag_ttwo(elf);
    return (0);
}

int single_file(char *filepath)
{
    int len = 0;
    Elf64_Ehdr *elf = elf_reader(filepath, &len);
    int archi = 0;

    if (!elf) {
        if (!strcmp("a.out", filepath))
            write(2, "my_objdump: 'a.out': No such file\n", 34);
        else {
            write(2, "my_objdump: '", 12);
            write(2, filepath, strlen(filepath));
            write(2, "': No such file\n", 16);
        }
        return (84);
    }
    if (!check_elf(elf->e_ident, &archi, elf->e_type, len)) {
        write(2, "my_objdump: ", 12);
        write(2, filepath, strlen(filepath));
        write(2, ": file format not recognized\n", 30);
        return (84);
    }
    return (archi == ELFCLASS32 ? objdump_ttwo(filepath, (Elf32_Ehdr *) elf) :
    objdump_sfour(filepath, elf));
}

int objdump(int ac, char **av)
{
    int status = 0;

    UNUSED(av);
    if (ac == 1)
        return (single_file("a.out"));
    for (int i = 1; i < ac; i++) {
        if (status == 0)
            status = single_file(av[i]);
        else
            single_file(av[i]);
    }
    return (status);
}