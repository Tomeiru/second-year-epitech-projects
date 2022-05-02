/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines DIV_ROUND_UP
*/

#pragma once

// dend = dividend
// dsor = disivor
#define STRACE_DIV_ROUND_UP(dend, dsor) (((dend) + (dsor) - 1) / (dsor))
