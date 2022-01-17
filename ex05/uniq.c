/*
** EPITECH PROJECT, 2022
** AM
** File description:
** uniq
*/

#include <stdlib.h>

size_t uniq_int_array(int *array, size_t nmenb)
{
    for (int i = 0; i < nmenb; i++) {
        for (int j = i + 1; j < nmenb; j++) {
            if (array[i] == array[j]) {
                for (int k = j + 1; k < nmenb; k++)
                    array[k - 1] = array[k];
                nmenb--;
                j--;
            }
        }
    }return (nmenb);
}

size_t uniq_array(void *array, size_t nmenb, size_t size, int (*compar)
(const void*, const void*))
{
    return (nmenb);
}