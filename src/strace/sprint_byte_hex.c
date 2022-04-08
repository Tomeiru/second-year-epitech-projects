/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines sprint_byte_hex
*/

#include "sprint_byte_hex.h"

static const char CHARACTERS_HEX[16] = "0123456789abcdef";

char *strace_sprint_byte_hex(char *buffer, uint8_t value)
{
    *buffer++ = CHARACTERS_HEX[value >> 4];
    *buffer++ = CHARACTERS_HEX[value & 0xF];
    return (buffer);
}
