/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines is_printable
*/

#include "is_printable.h"

bool strace_is_printable(uint8_t ch)
{
    return ((ch >= ' ') && (ch < 0x7F));
}
