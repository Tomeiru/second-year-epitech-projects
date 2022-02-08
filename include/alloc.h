/*
** EPITECH PROJECT, 2022
** malloc
** File description:
** alloc
*/

#ifndef ALLOC_H_
    #define ALLOC_H_

// MACROS
    #define UNUSED(x) (void)(x)

// INCLUDES
    #include <stdio.h>
    #include <unistd.h>

// STRUCT
typedef struct metadata_s {
    size_t size;
    int free;
    struct metadata_s *next;
} metadata_t;

// DECLARATION
void *malloc(size_t size);

#endif /* !ALLOC_H_ */
