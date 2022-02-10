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
    #define ALIGN(x) ((((x-1)/4)*4)+4)

// INCLUDES
    #include <stdio.h>
    #include <unistd.h>

// STRUCT
typedef struct metadata_s {
    size_t size;
    int free;
    struct metadata_s *next;
    struct metadata_s *prev;
    char magic[1];
} metadata_t;

// DECLARATION
void *malloc(size_t size);
void free(void *ptr);

#endif /* !ALLOC_H_ */
