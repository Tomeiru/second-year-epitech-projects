/*
** EPITECH PROJECT, 2022
** strace
** File description:
** printer
*/

#include "strace.h"

char *get_str_from_reg(pid_t pid, unsigned long long reg)
{
    UNUSED(table);
    long *reg_addr = (long *)reg;
    long ret = ptrace(PTRACE_PEEKDATA, pid, (reg_addr++), NULL);
    unsigned long long size = sizeof(long) * 2 + 2;
    long *str = malloc(size);
    int i = 0;

    str[i++] = ret;
    while (ret != -1 && ret) {
        ret = ptrace(PTRACE_PEEKDATA, pid, (reg_addr++), NULL);
        size += sizeof(long);
        str = realloc(str, size);
        str[i++] = ret;
    }
    str[i] = 0;
    return ((char *)str);
}

void print_good_type_ret(long rax, int type, pid_t pid)
{
    char *str;

    if (type == NUM) {
        fprintf(stderr, ") = %d\n", (int)rax);
        return;
    }
    if (type == STRING) {
        fprintf(stderr, ") = \"%s\"\n", (str = get_str_from_reg
        (pid, rax)));
        free(str);
        return;
    }
    if (type == STRUCT_STAT_P) {
        fprintf(stderr, ") = %s\n", "{st_mode=");
        return;
    }
    fprintf(stderr, ") = %#lx\n", rax);
}

void print_good_type(unsigned long long reg, int type, int is_end, pid_t pid)
{
    char *str;

    if (type == NUM) {
        fprintf(stderr, is_end ? "%d" : "%d, ", (int)reg);
        return;
    }
    if (type == STRING) {
        fprintf(stderr, is_end ? "\"%s\"" : "\"%s\", ", (str = get_str_from_reg
        (pid, reg)));
        free(str);
        return;
    }
    if (type == STRUCT_STAT_P) {
        fprintf(stderr, is_end ? "%s" : "%s, ", "{st_mode=");
        return;
    }
    fprintf(stderr, is_end ? "%#llx" : "%#llx, ", reg);
}

void print_com(struct user_regs_struct regs, long rax, pid_t pid, int details)
{
    unsigned long long paramArray[] = {regs.rdi, regs.rsi,
    regs.rdx, regs.r10, regs.r8, regs.r9};
    short args[] = {table[regs.rax].first_arg, table[regs.rax].second_arg,
    table[regs.rax].third_arg, table[regs.rax].fourth_arg,
    table[regs.rax].fifth_arg, table[regs.rax].sixth_arg};

    fprintf(stderr, "%s(", table[regs.rax].name);
    for (int i = 0; i < table[regs.rax].nb_arg; i++)
        details == 1 ? print_good_type(paramArray[i],
        args[i], i == table[regs.rax].nb_arg - 1, pid) :
        fprintf(stderr, i == table[regs.rax].nb_arg - 1 ?
        "%#llx" : "%#llx, ", paramArray[i]);
    details == 1 ? print_good_type_ret(rax, table[regs.rax].return_type, pid) :
    fprintf(stderr, ") = %#lx\n", rax);
}