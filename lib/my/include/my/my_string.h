/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares my_string-related entities
*/

#pragma once

#include "features.h"
#include "my/stdlib.h"
#include <string.h>
#include <stdarg.h>
#include <stddef.h>

/// This contains a null-terminated string (for easy usage with C APIs), but can
/// still contain embedded NULs if you want
struct my_string {
    size_t length;
    size_t allocated_size;
    char *string;
};

/// Creates a new, empty, my_string
struct my_string *my_string_new(void) MY_ATTR_WARN_UNUSED_RESULT;

/// Creates a new my_string from the first size bytes of string
struct my_string *my_string_new_from_string(const char *string, size_t length)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_ACCESS((read_only, 1, 2));

/// Creates a new my_string from the file given (by reading that entire file)
struct my_string *my_string_new_from_filename(const char *filename)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_ACCESS((read_only, 1));

/// Copies source into self
struct my_string *my_string_assign(struct my_string *self,
    const struct my_string *source);

/// Inserts length bytes from string to self at pos. A precondition is that
/// string is not a substring of self (i.e. directly located within
/// self->string)
struct my_string *my_string_insert(struct my_string *self, const char *string,
    size_t length, size_t position);

/// Same as insert, but for a single character
static inline struct my_string *my_string_insert_char(struct my_string *self,
    char character, size_t position)
{
    return (my_string_insert(self, &character, 1, position));
}

/// Appends length bytes from string to self
struct my_string *my_string_append(struct my_string *self, const char *string,
    size_t length);

/// Same as append, but for a single character
static inline struct my_string *my_string_append_char(struct my_string *self,
    char character)
{
    return (my_string_append(self, &character, 1));
}

/// Same as append, but for a C string
static inline struct my_string *my_string_append_cstr(struct my_string *self,
    const char *c_string)
{
    return (my_string_append(self, c_string, strlen(c_string)));
}

/// Appends a formatted string to self
struct my_string *my_string_append_vprintf(struct my_string *self,
    const char *format, va_list arguments) __attribute__((format(printf, 2,
    0)));

/// Same as above, but takes ... instead of va_list
__attribute__((format(printf, 2, 3)))
static inline struct my_string *
    my_string_append_printf(struct my_string *self, const char *format, ...)
{
    va_list arguments;

    va_start(arguments, format);
    my_string_append_vprintf(self, format, arguments);
    va_end(arguments);
    return (self);
}

/// Removes count characters starting at index
struct my_string *my_string_erase(struct my_string *self, size_t index,
    size_t count);

/// Resizes the string to contain count characters. If the current size is less
/// than count, the string becomes bigger, but has undefined contents after the
/// current size. If the current size is greater than count, the string is
/// reduced to its first count elements
struct my_string *my_string_resize(struct my_string *self, size_t count);

/// Removes all the characters from the string, as if by executing
/// my_string_resize(self, 0)
static inline struct my_string *my_string_clear(struct my_string *self)
{
    return my_string_resize(self, 0);
}

/// Destructs the passed string and the associated data. If you instead want to
/// free the my_string but gain ownership of self->string, use
/// my_string_move_buffer
void my_string_free(struct my_string *self);

/// Destructs the passed my_string but returns the underlying buffer
static inline char *my_string_move_buffer(struct my_string *self)
{
    char *result = self->string;

    free(self);
    return result;
}
