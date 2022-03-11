/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** objdump
*/

#include "objdump.h"

int check_elf(unsigned char *elf, int *archi, unsigned short type, int len)
{
    if (len < 52)
        return (1);
    if (elf[EI_MAG0] != ELFMAG0 || elf[EI_MAG1] != ELFMAG1 ||
    elf[EI_MAG2] != ELFMAG2 || elf[EI_MAG3] != ELFMAG3)
        return (1);
    *archi = elf[EI_CLASS];
    if (*archi == 0 || elf[EI_VERSION] != EV_CURRENT || type < 1 || type > 3)
        return (1);
    return (0);
}

int check_trunc(Elf64_Ehdr *elf, long unsigned len)
{
    Elf32_Ehdr *elf_tt;

    if (elf->e_ident[EI_CLASS] == ELFCLASS32) {
        elf_tt = (Elf32_Ehdr*) elf;
        if (len != elf_tt->e_shoff + elf_tt->e_shnum * elf_tt->e_shentsize)
            return (1);
        return (0);
    }
    if (len != elf->e_shoff + elf->e_shnum * elf->e_shentsize)
        return (1);
    return (0);
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

int single_file(char *filepath)
{
    int len = 0;
    Elf64_Ehdr *elf = elf_reader(filepath, &len);
    int archi = 0;

    if (!elf) {
        write(2, "my_objdump: '", 12);
        write(2, filepath, strlen(filepath));
        write(2, "': No such file\n", 16);
        return (84);
    }
    if (check_elf(elf->e_ident, &archi, elf->e_type, len) ||
    check_trunc(elf, len)) {
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