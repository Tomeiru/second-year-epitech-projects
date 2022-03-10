/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
    #define OBJDUMP_H_

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

#endif /* !OBJDUMP_H_ */
