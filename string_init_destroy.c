/*
** EPITECH PROJECT, 2022
** Day5
** File description:
** string_init_destroy
*/

#include "string.h"

static void string_init_follow_up(string_t *this)
{
    this->split_c = &split_c;
    this->print = &print;
    this->join_s = &join_s;
    this->join_c = &join_c;
}

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &get_char_at_pos;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_s = &insert_s;
    this->insert_c = &insert_c;
    this->to_int = &to_int;
    this->split_s = &split_s;
    string_init_follow_up(this);
}

void string_destroy(string_t *this)
{
    if (this == NULL)
        return;
    free(this->str);
    this = NULL;
}
