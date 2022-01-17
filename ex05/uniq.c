/*
** EPITECH PROJECT, 2022
** AM
** File description:
** uniq
*/

#include <stdlib.h>
#include <string.h>

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
    size_t back_up = nmenb;
    char buffer[size];
    for (int i = 0; i < nmenb; i++) {
        for (int j = i + 1; j < nmenb; j++) {
            if (compar(array + (i * size), array + (j * size)) == 0) {
                for (int k = j + 1; k < nmenb; k++) {
                    memcpy(buffer, array + (k * size), size);
                    memcpy(array + ((k - 1) * size), buffer, size);
                }
                nmenb--;
                j--;
            }
        }
    }
    return (nmenb);
}