/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines sign_extend_unsigned_to_imax
*/

#pragma once

#include <stdint.h>

#define STRACE_SIGN_EXTEND_UNSIGNED_TO_IMAX(value) (sizeof(value) == \
    sizeof(int8_t) ? (intmax_t)(int8_t)(value) : \
    sizeof(value) == sizeof(int16_t) ? (intmax_t)(int16_t)(value) : \
    sizeof(value) == sizeof(int32_t) ? (intmax_t)(int32_t)(value) : \
    sizeof(value) == sizeof(int64_t) ? (intmax_t)(int64_t)(value) : \
    (intmax_t)(value))
