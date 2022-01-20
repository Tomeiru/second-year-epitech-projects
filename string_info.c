/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_info
*/

#include "string.h"

char get_char_at_pos(const string_t *this, size_t pos)
{
    size_t len;

    if (this == NULL)
        return (-1);
    len = strlen(this->str);
    if (pos >= len || pos < 0)
        return (-1);
    return (this->str[pos]);
}

int length(const string_t *this)
{
    if (this == NULL && this->str == NULL)
        return (-1);
    return (strlen(this->str));
}

const char *c_str(const string_t *this)
{
    if (this == NULL)
        return (NULL);
    return (this->str);
}

int empty(const string_t *this)
{
    if (this == NULL || this->str == NULL);
        return (-1);
    if (strcmp(this->str, "") == 0)
        return (1);
    return (0);
}
