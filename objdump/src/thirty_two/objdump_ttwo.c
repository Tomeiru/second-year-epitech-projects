/*
** EPITECH PROJECT, 2022
** objdump
** File description:
** objdump_two
*/

#include "objdump.h"

void print_fflag_ttwo(char *filepath, Elf32_Ehdr *elf)
{
    printf("\n%s:     file format elf32-i386\n", filepath);
    printf("architecture: i386, flags ");
    bfd_flags_ttwo(elf);
    printf("start address 0x%08x", elf->e_entry);
    printf("\n\n");
}

void print_line_ttwo(Elf32_Shdr section, unsigned char *str, unsigned int i)
{
    unsigned int index = i;

    printf(" %04x ", section.sh_addr + i);
    for (unsigned int y = 0; y < 19; y++) {
        if ((y + 1) % 5 == 0) {
            printf(" ");
            continue;
        }if (i < section.sh_size) {
            printf("%02hhx", str[i++]);
            continue;
        }printf("  ");
    }i = index;
    printf("  ");
    for (unsigned int y = 0; y++ < 16; i++) {
        if (i >= section.sh_size) {
            printf(" ");
            continue;
        }printf("%c", isprint(str[i]) ? str[i] : '.');
    }printf("\n");
}

void print_content_ttwo(Elf32_Ehdr *elf, Elf32_Shdr section)
{
    unsigned char *str = (unsigned char *)elf + section.sh_offset;

    for (unsigned int i = 0; i < section.sh_size; i += 16)
        print_line_ttwo(section, str, i);
}

void print_sflag_ttwo(Elf32_Ehdr *elf)
{
    Elf32_Shdr *sections = (Elf32_Shdr *)((void *)elf + elf->e_shoff);
    Elf32_Shdr *str_table = &sections[elf->e_shstrndx];
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
            print_content_ttwo(elf, sections[i]);
        }
    }
}

int objdump_ttwo(char *filepath, Elf32_Ehdr *elf)
{
    print_fflag_ttwo(filepath, elf);
    print_sflag_ttwo(elf);
    return (0);
}