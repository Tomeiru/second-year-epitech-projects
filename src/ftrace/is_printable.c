/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines is_printable
*/

#include "is_printable.h"

bool ftrace_is_printable(uint8_t ch)
{
    return ((ch >= ' ') && (ch < 0x7F));
}
