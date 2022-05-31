/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** utils_my_str_to_super_array
*/

#include <string.h>

int is_sep(char c, char *sep)
{
    if (c == 0)
        return (0);
    for (int i = 0; sep[i]; i++)
        if (c == sep[i])
            return (0);
    return (1);
}

char *rm_sep_bef(char *str, char *sep)
{
    if (!strlen(str))
        return (str);
    for ( ; !is_sep(*str, sep); str++);
    return (str);
}

char *rm_sep_aft(char *str, char *sep)
{
    int i = strlen(str) - 1;

    for (; i > -1 && !is_sep(str[i], sep); i--);
    str[++i] = '\0';
    return (str);
}