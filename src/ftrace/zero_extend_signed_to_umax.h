/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines zero_extend_signed_to_umax
*/

#pragma once

#include <stdint.h>

#define STRACE_ZERO_EXTEND_SIGNED_TO_UMAX(value) \
    (sizeof(value) == sizeof(int8_t) ? (uintmax_t)(uint8_t)(value) : \
    sizeof(value) == sizeof(int16_t) ? (uintmax_t)(uint16_t)(value) : \
    sizeof(value) == sizeof(int32_t) ? (uintmax_t)(uint32_t)(value) : \
    sizeof(value) == sizeof(int64_t) ? (uintmax_t)(uint64_t)(value) : \
    (uintmax_t)(value))
