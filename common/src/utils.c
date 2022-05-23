/*
** EPITECH PROJECT, 2022
** teams
** File description:
** utils
*/

#include <ctype.h>

int is_not_number(char *s)
{
    for (int i = 0; s[i]!= '\0'; i++) {
        if (isdigit(s[i]) == 0)
            return (1);
    }
    return (0);
}
