/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines main
*/

#include "strace.h"
#include "strace/init.h"
#include "strace/get_next_event.h"
#include "strace/do_event.h"
#include "strace/exit.h"
#include "strace/print_error_message/and_die.h"

int main(int argc, char **argv)
{
    static struct strace self = {};

    strace_init(&self, argc, argv);
    self.exit_status = !self.has_traced_process;
    while (strace_do_event(&self, strace_get_next_event(&self)))
        continue;
    strace_exit(&self);
    strace_print_error_message_and_die(&self, "strace_exit did not exit");
}
