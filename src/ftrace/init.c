/*
** EPITECH PROJECT, 2022
** ftrace
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

static const char STRACE_DEFAULT_NAME[] = "ftrace";
static const struct option STRACE_OPTIONS[] = {
    {"help", no_argument, NULL, 'h'},
    {"attach", required_argument, NULL, 'p'},
    {NULL, 0, NULL, '\0'},
};

// We accept spaces, newlines, tabs and commas as separators
static void do_attach_list(struct ftrace *self, char *attach_list)
{
    pid_t pid;
    char *delimiter;
    char current_char;

    while (*attach_list != '\0') {
        do_attach_list_loop_start(attach_list, &delimiter, &current_char, &pid);
        if (pid <= 0)
            ftrace_print_error_message_and_die(self, "Invalid process id: '%s'",
                attach_list);
        if (pid == self->tracer_pid)
            ftrace_print_error_message_and_die(self,
                "I'm sorry, I can't let you do that, Dave.");
        *delimiter = current_char;
        ftrace_process_add(self, pid);
        if (current_char == '\0')
            break;
        attach_list = delimiter + 1;
    }
}

static void si_part3(struct ftrace *self, int argc, char **argv)
{
    argv += optind;
    argc -= optind;
    if (argc < 0 || (!self->has_traced_process && argc == 0))
        ftrace_print_error_message_help_and_die(self,
            "must have PROG [ARGS] or -p PID");
    sigaction(SIGCHLD, &((struct sigaction){.sa_handler = SIG_DFL}),
        &self->traced_process_params.sigchld_sigaction);
    self->traced_process_uid = getuid();
    ftrace_standard_fds_check_open(self);
    if (argc != 0)
        ftrace_start_child(self, argv);
    if (self->has_traced_process)
        ftrace_init_do_attach(self);
}

static void si_part2(struct ftrace *self, int argc, char **argv)
{
    int current_character;

    while (true) {
        current_character =
            getopt_long(argc, argv, "+hp:", STRACE_OPTIONS, NULL);
        if (current_character == EOF)
            break;
        switch (current_character) {
        case 'h':
            usage(self);
            break;
        case 'p':
            do_attach_list(self, optarg);
            break;
        }
    }
    si_part3(self, argc, argv);
}

void ftrace_init(struct ftrace *self, int argc, char **argv)
{
    memset(self, 0, sizeof(*self));
    self->gne_pending_procs = (struct ftrace_list_item){
        &self->gne_pending_procs, &self->gne_pending_procs
    };
    self->x86_io.iov_base = &self->x86_regs;
    self->program_invocation_name = (argc > 0 && argv[0] != NULL && *argv[0] !=
        '\0') ? argv[0] : STRACE_DEFAULT_NAME;
    self->tracer_pid = getpid();
    si_part2(self, argc, argv);
}
