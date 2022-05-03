/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines sprint_byte_occtal
*/

#include "sprint_byte_octal.h"

char *abbreviated(char *string, uint8_t ch)
{
    if ((ch >> 3) != 0) {
        if ((ch >> 6) != 0)
            *string++ = '0' + ((ch >> 6) & 0x7);
        *string++ = '0' + ((ch >> 3) & 0x7);
    }
    return (string);
}

char *ftrace_sprint_byte_octal(char *string, uint8_t ch, bool unabbreviated)
{
    if (unabbreviated) {
        *string++ = '0' + ((ch >> 6) & 0x7);
        *string++ = '0' + ((ch >> 3) & 0x7);
    } else
        string = abbreviated(string, ch);
    *string++ = '0' + (ch & 0x7);
    return (string);
}
