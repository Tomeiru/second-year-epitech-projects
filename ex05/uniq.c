/*
** EPITECH PROJECT, 2022
** AM
** File description:
** uniq
*/

#include <stdlib.h>
#include <string.h>

int *uniq_int_array_scd(int *array, size_t *nmenb, int i, int *j)
{
    if (array[i] == array[*j]) {
        for (int k = *j + 1; k < *nmenb; k++)
            array[k - 1] = array[k];
        *nmenb = *nmenb - 1;
        *j = *j - 1;
    }
    return (array);
}

size_t uniq_int_array(int *array, size_t nmenb)
{
    for (int i = 0; i < nmenb; i++)
        for (int j = i + 1; j < nmenb; j++)
            array = uniq_int_array_scd(array, &nmenb, i, &j);
    return (nmenb);
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