/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** my_str_to_super_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static char **get_and_check_command(char *str, int *i)
{
    int len = 0;
    char **arr = NULL;

    if (str[*i] != '/')
        return (NULL);
    *i += 1;
    for ( ; is_sep(str[*i], " \t"); (*i)++)
        len++;
    if (len == 0)
        return (NULL);
    arr = malloc(sizeof(char *) * 1);
    arr[0] = malloc(sizeof(char) * (len + 1));
    memset(arr[0], 0, sizeof(char) * (len + 1));
    memcpy(arr[0], str + 1, len);
    return (arr);
}

static int check_arg_format(char *str)
{
    int len = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i++] != '"')
            return (-1);
        for ( ; is_sep(str[i], "\""); i++);
        if (str[i++] != '"' || (str[i] && is_sep(str[i], " \t")))
            return (-1);
        if (!str[i])
            return (++len);
        for ( ; !is_sep(str[i], " \t"); i++);
        i--;
        len++;
    }
    return (len);
}

static char **add_args_to_arr(char **arr, char *str, int nb_arg)
{
    int len = 0;

    for (int i = 0; i < nb_arg; i++) {
        str++;
        for ( ; is_sep(*str, "\""); str++)
            len++;
        arr[i + 1] = malloc(sizeof(char) * (len + 1));
        memset(arr[i + 1], 0, sizeof(char) * (len + 1));
        memcpy(arr[i + 1], str - len, len);
        str++;
        str = rm_sep_bef(str, " \t");
        len = 0;
    }arr[nb_arg + 1] = NULL;
    return (arr);
}

static char **do_it(char *str)
{
    int i = 0;
    char **arr = get_and_check_command(str, &i);
    int nb_arg = 0;

    if (arr == NULL)
        return (NULL);
    if (str[i] == '\0') {
        arr = realloc(arr, sizeof(char *) * 2);
        arr[1] = NULL;
        return (arr);
    }str = str + i;
    str = rm_sep_bef(str, " \t");
    if ((nb_arg = check_arg_format(str)) == -1) {
        free(arr[0]);
        free(arr);
        return (NULL);
    }arr = realloc(arr, sizeof(char *) * (nb_arg + 2));
    arr = add_args_to_arr(arr, str, nb_arg);
    return (arr);
}

char **teams_cl_to_arr(char *str)
{
    char **arr = NULL;
    char *malloc_str = NULL;
    char *trim = NULL;

    if (str == NULL || !strlen(str) || !(malloc_str = strdup(str)))
        return (arr);
    trim = rm_sep_aft(rm_sep_bef(malloc_str, " \t"), " \t");
    if (!strlen(trim)) {
        free(malloc_str);
        return (arr);
    }
    arr = do_it(trim);
    free(malloc_str);
    return (arr);
}