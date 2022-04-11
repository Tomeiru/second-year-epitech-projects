/*
** EPITECH PROJECT, 2022
** ftrace
** File description:
** Defines main
*/

#include "ftrace.h"
#include "ftrace/init.h"
#include "ftrace/get_next_event.h"
#include "ftrace/do_event.h"
#include "ftrace/exit.h"
#include "ftrace/print_error_message/and_die.h"

int main(int argc, char **argv)
{
    static struct ftrace self = {};

    ftrace_init(&self, argc, argv);
    self.exit_status = !self.has_traced_process;
    while (ftrace_do_event(&self, ftrace_get_next_event(&self)))
        continue;
    ftrace_exit(&self);
    ftrace_print_error_message_and_die(&self, "ftrace_exit did not exit");
}
