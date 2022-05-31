/*
** EPITECH PROJECT, 2022
** teams
** File description:
** utils
*/

#include <ctype.h>
#include <string.h>

int is_not_number(char *s)
{
    for (int i = 0; s[i]!= '\0'; i++) {
        if (isdigit(s[i]) == 0)
            return (1);
    }
    return (0);
}

int get_len_array(void *arr, size_t size)
{
    int len = 0;

    while(((int *)(arr))[0]) {
        len++;
        arr += size;
    }
    return (len);
}
