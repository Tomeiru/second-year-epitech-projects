/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines basic_defs
*/

#pragma once

#include <linux/errno.h>

#ifndef ERESTARTSYS
    #define ERESTARTSYS 512
#endif
#ifndef ERESTARTNOINTR
    #define ERESTARTNOINTR 513
#endif
#ifndef ERESTARTNOHAND
    #define ERESTARTNOHAND 514
#endif
#ifndef ERESTART_RESTARTBLOCK
    #define ERESTART_RESTARTBLOCK 516
#endif
