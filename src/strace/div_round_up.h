/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines DIV_ROUND_UP
*/

#pragma once

#define STRACE_DIV_ROUND_UP(dividend, divisor) (((dividend) + (divisor) - 1) \
    / (divisor))
