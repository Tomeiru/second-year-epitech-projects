/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Declares limits-related entities
*/

#pragma once

#include <limits.h>

#define MY_NUMERIC_LIMITS_MAX(type_t) ((type_t)-1 > 0 ? (sizeof(type_t) == \
    sizeof(unsigned char) ? \
    ((type_t)2 == 1 ? 1 : UCHAR_MAX) : \
    sizeof(type_t) == sizeof(unsigned short) ? USHRT_MAX : \
    sizeof(type_t) == sizeof(unsigned int) ? UINT_MAX : \
    sizeof(type_t) == sizeof(unsigned long) ? ULONG_MAX : \
    sizeof(type_t) == sizeof(unsigned long long) ? ULLONG_MAX : 0 \
    ) : (sizeof(type_t) == sizeof(signed char) ? SCHAR_MAX : \
    sizeof(type_t) == sizeof(short) ? SHRT_MAX : \
    sizeof(type_t) == sizeof(int) ? INT_MAX : \
    sizeof(type_t) == sizeof(long) ? LONG_MAX : \
    sizeof(type_t) == sizeof(long long) ? LLONG_MAX : 0))
