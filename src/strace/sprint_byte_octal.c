/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines sprint_byte_occtal
*/

#include "sprint_byte_octal.h"

char *strace_sprint_byte_octal(char *string, uint8_t ch, bool unabbreviated)
{
    if (unabbreviated) {
        *string++ = '0' + ((ch >> 6) & 0x7);
        *string++ = '0' + ((ch >> 3) & 0x7);
    } else {
        if ((ch >> 3) != 0) {
            if ((ch >> 6) != 0)
                *string++ = '0' + ((ch >> 6) & 0x7);
            *string++ = '0' + ((ch >> 3) & 0x7);
        }
    }
    *string++ = '0' + (ch & 0x7);
    return (string);
}
