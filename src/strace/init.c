/*
** EPITECH PROJECT, 2022
** strace
** File description:
** Defines init
*/

#include "init.h"
#include "init_part2.h"
#include "start_child.h"
#include "init_do_attach.h"
#include "print_error_message/and_die.h"
#include "print_error_message/help_and_die.h"
#include "process/add.h"
#include "standard_fds/check_open.h"
#include <unistd.h>
#include <getopt.h>

static const char STRACE_DEFAULT_NAME[] = "strace";
static const struct option STRACE_OPTIONS[] = {
    {"help", no_argument, NULL, 'h'},
    {"attach", required_argument, NULL, 'p'},
    {"pretty-print", no_argument, NULL, 's'},
    {NULL, 0, NULL, '\0'},
};

// We accept spaces, newlines, tabs and commas as separators
static void do_attach_list(struct strace *self, char *attach_list)
{
    pid_t pid;
    char *delimiter;
    char current_char;

    while (*attach_list != '\0') {
        do_attach_list_loop_start(attach_list, &delimiter, &current_char, &pid);
        if (pid <= 0)
            strace_print_error_message_and_die(
                self, "Invalid process id: '%s'", attach_list);
        if (pid == self->tracer_pid)
            strace_print_error_message_and_die(
                self, "I'm sorry, I can't let you do that, Dave.");
        *delimiter = current_char;
        strace_process_add(self, pid);
        if (current_char == '\0')
            break;
        attach_list = delimiter + 1;
    }
}

static void si_part3(struct strace *self, int argc, char **argv)
{
    argv += optind;
    argc -= optind;
    if (argc < 0 || (!self->has_traced_process && argc == 0))
        strace_print_error_message_help_and_die(
            self, "must have PROG [ARGS] or -p PID");
    sigaction(SIGCHLD, &((struct sigaction){.sa_handler = SIG_DFL}),
        &self->traced_process_params.sigchld_sigaction);
    self->traced_process_uid = getuid();
    strace_standard_fds_check_open(self);
    if (argc != 0)
        strace_start_child(self, argv);
    if (self->has_traced_process)
        strace_init_do_attach(self);
}

static void si_part2(struct strace *self, int argc, char **argv)
{
    int current_character;

    while (true) {
        current_character =
            getopt_long(argc, argv, "+hp:s", STRACE_OPTIONS, NULL);
        if (current_character == EOF)
            break;
        switch (current_character) {
        case 'h':
            usage(self);
            break;
        case 's':
            self->print_raw_arguments = false;
            break;
        case 'p':
            do_attach_list(self, optarg);
            break;
        }
    }
    si_part3(self, argc, argv);
}

void strace_init(struct strace *self, int argc, char **argv)
{
    memset(self, 0, sizeof(*self));
    self->print_raw_arguments = true;
    self->gne_pending_procs = (struct strace_list_item){
        &self->gne_pending_procs, &self->gne_pending_procs
    };
    self->x86_io.iov_base = &self->x86_regs;
    self->program_invocation_name = (argc > 0 && argv[0] != NULL && *argv[0] !=
        '\0') ? argv[0] : STRACE_DEFAULT_NAME;
    self->tracer_pid = getpid();
    si_part2(self, argc, argv);
}
