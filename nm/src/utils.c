/*
** EPITECH PROJECT, 2022
** objdump
** File description:
** utils
*/

#include "nm_func.h"

static int get_clear_len(char *name)
{
    int ret = 0;

    for (int i = 0; name[i]; i++)
        if (isalnum(name[i]))
            ret++;
    return (ret);
}

char *clear_name(char *name)
{
    int len = get_clear_len(name);
    char *ret = malloc(sizeof(char) * (len + 1));
    int ii = 0;

    for (int i = 0; name[i]; i++) {
        if (isalnum(name[i]))
            ret[ii++] = name[i];
    }
    ret[ii] = '\0';
    return (ret);
}