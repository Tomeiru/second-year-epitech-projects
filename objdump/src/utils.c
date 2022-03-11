/*
** EPITECH PROJECT, 2022
** objdump
** File description:
** utils
*/

#include "objdump.h"

void apply_flag(char **flags, char *flag, int idx, char value)
{
    int len = strlen(*flags);
    int size = (len > 13) ? len + strlen(flag) + 3 : len + strlen(flag) + 1;
    char *bef = NULL;

    (*flags)[idx] = value;
    *flags = realloc(*flags, sizeof(char) * size);
    if (len > 13) {
        bef = malloc(sizeof(char) * (3 + strlen(flag)));
        bef[0] = ',';
        bef[1] = ' ';
        bef[2] = '\0';
        strcat(bef, flag);
        strcat(*flags, bef);
        free(bef);
        return;
    }
    strcat(*flags, flag);
}