/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** utils
*/

#include "myftp.h"

int print_error(char *err)
{
    fprintf(stderr, "myftp: %s\n", err);
    return (84);
}