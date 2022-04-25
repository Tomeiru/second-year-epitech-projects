/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Defines xfclose
*/

#include "my/stdio.h"
#include <stdlib.h>

void my_xfclose(FILE *fp)
{
    if (ferror(fp)) {
        fputs("Tried to close file with pending errors\n", stderr);
        exit(84);
    }
    if (fflush(fp) != 0) {
        fputs("fflush failed\n", stderr);
        exit(84);
    }
    if (fclose(fp) != 0) {
        fputs("fclose failed\n", stderr);
        exit(84);
    }
}
