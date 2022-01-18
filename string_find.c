/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_find
*/

#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *ptr = 0;
    int ret = 0;

    if (this == NULL || str == NULL)
        return (-1);
    ptr = strstr(this->str + pos, str->str);
    if (ptr == NULL)
        return (-1);
    ret = ptr - this->str;
    return (ret);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *ptr = 0;
    int ret = 0;

    if (this == NULL || str == NULL)
        return (-1);
    ptr = strstr(this->str + pos, str);
    if (ptr == NULL)
        return (-1);
    ret = ptr - this->str;
    return (ret);
}
