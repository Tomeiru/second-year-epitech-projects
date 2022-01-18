/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_copy
*/

#include "string.h"

static size_t det_len_s(const char *str, size_t n, size_t pos)
{
    int i = 0;

    for (; str[pos + i] != '\0' && i < n; i++);
    if (str[pos + i] == '\0')
        return (i + 1);
    return (i);
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t ret = 0;

    if (this == NULL)
        return (0);
    ret = det_len_s(this->str, n, pos);
    strncpy(s, this->str + pos, n);
    return (ret);
}
