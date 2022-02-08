/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** test_adress
*/

#include <stdio.h>
#include <dlfcn.h>
#include <string.h>

int main(void)
{
    int kekw = 3;
    char *allo = "toto";
    printf("%p\n", &main);
    printf("%p\n", &dlopen);
    printf("%p\n", &strdup);
    printf("%p\n", &kekw);
    printf("%p\n", &allo);
}