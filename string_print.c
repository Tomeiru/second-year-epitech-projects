/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_print
*/

#include "string.h"

void print(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return;
    write(1, this->str, strlen(this->str));
}