/*
** EPITECH PROJECT, 2022
** AM
** File description:
** sort
*/

#include <stdlib.h>

int comparator(const void *first, const void *second)
{
    return (*(int *)first - *(int *)second);
}

void sort_int_array(int *array, size_t nmemb)
{
    qsort(array, nmemb, sizeof(int), comparator);
}

void sort_array(void *array, size_t nmemb, size_t size, int (*compar)
(const void*, const void *))
{
    qsort(array, nmemb, size, compar);
}
