/*
** EPITECH PROJECT, 2022
** B-NWP-400-STG-4-1-myteams-jeffrey.winkler
** File description:
** safe_malloc
*/

#include <stdlib.h>
#include <stdio.h>

void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);

    if (!ptr) {
        puts("Could not allocate memory !");
        exit(84);
    }
    return ptr;
}
