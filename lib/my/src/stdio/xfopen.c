/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Defines xfopen
*/

#include "my/stdio.h"
#include <stdlib.h>

FILE *my_xfopen(const char *filename, const char *mode)
{
    FILE *result = fopen(filename, mode);

    if (result == NULL) {
        fprintf(stderr, "Could not open '%s' (mode '%s')\n", filename, mode);
        fflush(stderr);
        exit(84);
    }
    return result;
}
