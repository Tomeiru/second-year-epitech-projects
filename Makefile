##
## EPITECH PROJECT, 2022
## strace
## File description:
## Makefile for strace
##

# Makefiles are prettier like this
ifeq ($(origin .RECIPEPREFIX), undefined)
  $(error This Make does not support .RECIPEPREFIX. \
	Please use GNU Make 3.82 or later)
endif
.RECIPEPREFIX = >

# Use bash as the shell
SHELL := bash

# ...And use strict flags with it to make sure things fail if a step in there
# fails
.SHELLFLAGS := -eu -o pipefail -c

# Delete the target file of a Make rule if it fails - this guards against
# broken files
.DELETE_ON_ERROR:

# --warn-undefined-variables: Referencing undefined variables is probably
# wrong...
# --no-builtin-rules: I'd rather make my own rules myself, make, thanks :)
MAKEFLAGS += --warn-undefined-variables --no-builtin-rules

# We use `override` to enable setting part of CFLAGS on the command line

# This makes the compiler generate dependency files, which will solve any
# header-related dependency problems we could have had
override CFLAGS += -MMD -MP -MF $@.d

# LDFLAGS should contain CFLAGS (seperate so command-line can add to it, and
# to correspond to usual practice)
override LDFLAGS += $(CFLAGS)

.PHONY: all clean fclean re

.PREVIOUS: obj/%.o

BINARY_NAME := strace

all: $(BINARY_NAME)

# Program sources files
SOURCE_FILES := main strace/get_next_event strace/do_event strace/exit
SOURCE_FILES += strace/print_error_message/and_die strace/init
SOURCE_FILES += strace/process/startup strace/set_current_process
SOURCE_FILES += strace/list/head_remove strace/event_table_size_check
SOURCE_FILES += strace/print_error_message/errno_and_die
SOURCE_FILES += strace/process/get_from_pid
SOURCE_FILES += strace/print_error_message/print_error_message
SOURCE_FILES += strace/list/is_empty strace/list/append
SOURCE_FILES += strace/print_signal_stop strace/print_signalled
SOURCE_FILES += strace/process/drop strace/print_exited
SOURCE_FILES += strace/do_ptrace_restart strace/cleanup
SOURCE_FILES += strace/vprint_error_message strace/do_trace_syscall
SOURCE_FILES += strace/print_event_exit_stopped strace/die/die
SOURCE_FILES += strace/cstr_to_uint strace/process/add
SOURCE_FILES += strace/print_error_message/help_and_die
SOURCE_FILES += strace/standard_fds/check_open strace/start_child
SOURCE_FILES += strace/init_do_attach strace/syscall/get_number
SOURCE_FILES += strace/list/remove strace/grow_array
SOURCE_FILES += strace/syscall/print_leader strace/sprint_signal_name
SOURCE_FILES += strace/printf strace/syscall/print_line_ended
SOURCE_FILES += strace/process/free_private_data
SOURCE_FILES += strace/print_error_message/errno strace/process/detach
SOURCE_FILES += strace/syscall/enter_decode strace/syscall/enter_trace
SOURCE_FILES += strace/syscall/enter_finish strace/syscall/exit_decode
SOURCE_FILES += strace/syscall/exit_trace strace/syscall/exit_finish
SOURCE_FILES += strace/syscall/print_resume strace/syscall/print_tab
SOURCE_FILES += strace/fd/open_dummy strace/do_exec strace/save_errno_kill
SOURCE_FILES += strace/do_ptrace_seize strace/process/do_post_attach
SOURCE_FILES += strace/standard_fds/redirect strace/process/attach
SOURCE_FILES += strace/syscall/number_is_valid strace/get_regs strace/zalloc
SOURCE_FILES += strace/syscall/print_raw_arguments strace/snprintf
SOURCE_FILES += strace/syscall/entry_buffer_free
SOURCE_FILES += strace/process/set_private_data strace/die/oom
SOURCE_FILES += strace/reallocarray strace/get_signal_name strace/vprintf
SOURCE_FILES += strace/syscall/get_arguments strace/process/get_syscall_entry
SOURCE_FILES += strace/syscall/print_start_arguments strace/process/is_raw
SOURCE_FILES += strace/syscall/get_result strace/syscall/print_end_arguments
SOURCE_FILES += strace/syscall/print_error_return strace/fd/set_cloexec
SOURCE_FILES += strace/syscall/number_is_in_range
SOURCE_FILES += strace/syscall/print_next_argument strace/calloc
SOURCE_FILES += strace/syscall/get_error strace/get_errno_name
SOURCE_FILES += strace/syscall/print_sys/execve
SOURCE_FILES += strace/syscall/print_sys/do_execve strace/syscall/print_path
SOURCE_FILES += strace/syscall/print_argv strace/syscall/print_argc
SOURCE_FILES += strace/syscall/print_address strace/syscall/print_path_n
SOURCE_FILES += strace/syscall/print_array_next
SOURCE_FILES += strace/syscall/print_more_data_after_this
SOURCE_FILES += strace/syscall/print_address_comment
SOURCE_FILES += strace/syscall/print_array_begin strace/syscall/print_string
SOURCE_FILES += strace/syscall/print_array_end strace/copy_mem_from_pid
SOURCE_FILES += strace/copy_str_from_pid strace/printf_comment
SOURCE_FILES += strace/syscall/print_quoted_c_string strace/quote_string
SOURCE_FILES += strace/syscall/print_comment_begin
SOURCE_FILES += strace/syscall/print_comment_end
SOURCE_FILES += strace/syscall/print_quoted_string strace/is_printable
SOURCE_FILES += strace/sprint_byte_octal strace/syscall/print_unavailable
SOURCE_FILES += strace/syscall/print_arguments_decimal
SOURCE_FILES += strace/syscall/print_sys/write strace/syscall/print_string_n
SOURCE_FILES += strace/syscall/print_string_ex strace/syscall/print_sys/brk
SOURCE_FILES += strace/syscall/print_sys/arch_prctl
SOURCE_FILES += strace/syscall/print_enum_value strace/enum_lookup
SOURCE_FILES += strace/syscall/print_sys/access strace/syscall/print_flags
SOURCE_FILES += strace/syscall/print_sys/openat strace/sprint_flags
SOURCE_FILES += strace/syscall/print_dir_fd strace/syscall/print_umode_t
SOURCE_FILES += strace/appendf_string_get_position_difference
SOURCE_FILES += strace/syscall/print_sys/newfstatat
SOURCE_FILES += strace/syscall/do_struct_stat strace/copy_struct_stat_from_pid
SOURCE_FILES += strace/syscall/print_struct_stat
SOURCE_FILES += strace/syscall/copy_mem_or_print_address
SOURCE_FILES += strace/syscall/print_struct_start
SOURCE_FILES += strace/syscall/print_symbolic_mode_t
SOURCE_FILES += strace/syscall/print_struct_next
SOURCE_FILES += strace/syscall/print_struct_end strace/syscall/print_sys/mmap
SOURCE_FILES += strace/syscall/print_sys/close strace/syscall/print_sys/read
SOURCE_FILES += strace/syscall/print_sys/pread
SOURCE_FILES += strace/syscall/print_sys/mprotect
SOURCE_FILES += strace/syscall/print_sys/munmap
SOURCE_FILES += strace/syscall/print_sys/prlimit64 strace/syscall/print_rlimit
SOURCE_FILES += strace/syscall/print_rlim_t strace/syscall/print_sys/getrandom
SOURCE_FILES += strace/sprint_byte_hex strace/syscall/print_sys/futex

OBJECT_FILES := $(addprefix obj/src/, $(addsuffix .o, $(SOURCE_FILES)))

$(BINARY_NAME): $(OBJECT_FILES)
> $(CC) $(LDFLAGS) -o $@ $^

obj/src/%.o: src/%.c
> @mkdir --parents obj/src/strace/print_error_message
> @mkdir --parents obj/src/strace/process
> @mkdir --parents obj/src/strace/list
> @mkdir --parents obj/src/strace/die
> @mkdir --parents obj/src/strace/standard_fds
> @mkdir --parents obj/src/strace/syscall/print_sys
> @mkdir --parents obj/src/strace/fd
> $(CC) -c $< -o $@ $(CFLAGS) -D_GNU_SOURCE

# Include dependencies for the object files
include $(shell [ -d obj ] && find obj/ -type f -name '*.d')

# Remove all object files
clean:
> rm --recursive --force obj

# Remove all object, binary and other produced files
fclean: clean
> rm --recursive --force $(BINARY_NAME)

# "Remakes" the project.
re:
> $(MAKE) clean
> $(MAKE) all
