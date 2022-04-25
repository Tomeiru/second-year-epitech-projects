/*
** EPITECH PROJECT, 2021
** libmy
** File description:
** Defines new_from_filename
*/

#include "my/my_string.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

struct my_string *my_string_new_from_filename(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    struct my_string *result;
    struct stat stat_buffer;

    if (fd < 0)
        return (NULL);
    if (fstat(fd, &stat_buffer) < 0 || stat_buffer.st_size < 0) {
        close(fd);
        return (NULL);
    }
    result = my_string_new();
    my_string_resize(result, stat_buffer.st_size);
    if (read(fd, result->string, result->length) < (ssize_t)result->length) {
        close(fd);
        my_string_free(result);
        return (NULL);
    }
    close(fd);
    return (result);
}
