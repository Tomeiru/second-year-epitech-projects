/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string
*/

#ifndef STRING_H_
#define STRING_H_

#include <stdlib.h>
#include <string.h>

typedef struct string_s {
    char *str;
    void (*assign_s)(struct string_s *this, const struct string_s *str);
    void (*assign_c)(struct string_s *this, const char *s);
    void (*append_s)(struct string_s *this, const struct string_s *ap);
    void (*append_c)(struct string_s *this, const char *ap);
    char (*at)(const struct string_s *this, size_t pos);
    void (*clear)(struct string_s *this);
    int (*length)(const struct string_s *this);
    int (*compare_s)(const struct string_s *this, const struct string_s *str);
    int (*compare_c)(const struct string_s *this, const char *str);
    size_t (*copy)(const struct string_s *this, char *s, size_t n, size_t pos);
    const char *(*c_str)(const struct string_s *this);
} string_t;


void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int length(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);

#endif /* !STRING_H_ */