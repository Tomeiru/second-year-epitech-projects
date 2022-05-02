##
## EPITECH PROJECT, 2022
## ftrace
## File description:
## Makefile for ftrace
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

# We need to be able to include the libmy include files
override CFLAGS += -Iinclude

# LDFLAGS should contain CFLAGS (seperate so command-line can add to it, and
# to correspond to usual practice)
override LDFLAGS += $(CFLAGS)

# We need to be able to link to libmy, and link to it
override LDFLAGS += -Llib

.PHONY: all clean fclean re libmy

.PREVIOUS: obj/%.o

BINARY_NAME := ftrace

all: $(BINARY_NAME)

# Program sources files
SOURCE_FILES := main ftrace/get_next_event ftrace/do_event ftrace/exit
SOURCE_FILES += ftrace/print_error_message/and_die ftrace/init
SOURCE_FILES += ftrace/process/startup ftrace/set_current_process
SOURCE_FILES += ftrace/list/head_remove ftrace/event_table_size_check
SOURCE_FILES += ftrace/print_error_message/errno_and_die
SOURCE_FILES += ftrace/process/get_from_pid
SOURCE_FILES += ftrace/print_error_message/print_error_message
SOURCE_FILES += ftrace/list/is_empty ftrace/list/append
SOURCE_FILES += ftrace/print_signal_stop ftrace/print_signalled
SOURCE_FILES += ftrace/process/drop ftrace/print_exited
SOURCE_FILES += ftrace/do_ptrace_restart ftrace/cleanup
SOURCE_FILES += ftrace/vprint_error_message ftrace/do_trace_syscall
SOURCE_FILES += ftrace/print_event_exit_stopped ftrace/die/die
SOURCE_FILES += ftrace/cstr_to_uint ftrace/process/add
SOURCE_FILES += ftrace/print_error_message/help_and_die
SOURCE_FILES += ftrace/standard_fds/check_open ftrace/start_child
SOURCE_FILES += ftrace/init_do_attach ftrace/syscall/get_number
SOURCE_FILES += ftrace/list/remove ftrace/grow_array
SOURCE_FILES += ftrace/syscall/print_leader ftrace/sprint_signal_name
SOURCE_FILES += ftrace/printf ftrace/syscall/print_line_ended
SOURCE_FILES += ftrace/process/free_private_data
SOURCE_FILES += ftrace/print_error_message/errno ftrace/process/detach
SOURCE_FILES += ftrace/syscall/enter_decode ftrace/syscall/enter_trace
SOURCE_FILES += ftrace/syscall/enter_finish ftrace/syscall/exit_decode
SOURCE_FILES += ftrace/syscall/exit_trace ftrace/syscall/exit_finish
SOURCE_FILES += ftrace/syscall/print_resume ftrace/syscall/print_tab
SOURCE_FILES += ftrace/fd/open_dummy ftrace/do_exec ftrace/save_errno_kill
SOURCE_FILES += ftrace/do_ptrace_seize ftrace/process/do_post_attach
SOURCE_FILES += ftrace/standard_fds/redirect ftrace/process/attach
SOURCE_FILES += ftrace/syscall/number_is_valid ftrace/get_regs ftrace/zalloc
SOURCE_FILES += ftrace/syscall/print_raw_arguments ftrace/snprintf
SOURCE_FILES += ftrace/syscall/entry_buffer_free
SOURCE_FILES += ftrace/process/set_private_data ftrace/die/oom
SOURCE_FILES += ftrace/reallocarray ftrace/get_signal_name ftrace/vprintf
SOURCE_FILES += ftrace/syscall/get_arguments ftrace/process/get_syscall_entry
SOURCE_FILES += ftrace/syscall/print_start_arguments
SOURCE_FILES += ftrace/syscall/get_result ftrace/syscall/print_end_arguments
SOURCE_FILES += ftrace/syscall/print_error_return ftrace/fd/set_cloexec
SOURCE_FILES += ftrace/syscall/number_is_in_range
SOURCE_FILES += ftrace/syscall/print_next_argument ftrace/calloc
SOURCE_FILES += ftrace/syscall/get_error ftrace/get_errno_name
SOURCE_FILES += ftrace/copy_mem_from_pid
SOURCE_FILES += ftrace/copy_str_from_pid
SOURCE_FILES += ftrace/is_printable
SOURCE_FILES += ftrace/sprint_byte_octal
SOURCE_FILES += ftrace/appendf_string_get_position_difference
SOURCE_FILES += ftrace/sprint_byte_hex ftrace/do_trace_call ftrace/call/do_exit
SOURCE_FILES += ftrace/get_symbol_from_addr ftrace/get_filename_from_addr
SOURCE_FILES += ftrace/process/update_proc_maps ftrace/do_trace_ret
SOURCE_FILES += ftrace/call/print_symbol ftrace/translate_symbol_name

OBJECT_FILES := $(addprefix obj/src/, $(addsuffix .o, $(SOURCE_FILES)))

$(BINARY_NAME): $(OBJECT_FILES) libmy
> $(CC) $(LDFLAGS) -o $@ $(OBJECT_FILES) -lmy -lelf

obj/src/%.o: src/%.c libmy
> @mkdir --parents obj/src/ftrace/print_error_message
> @mkdir --parents obj/src/ftrace/process
> @mkdir --parents obj/src/ftrace/list
> @mkdir --parents obj/src/ftrace/die
> @mkdir --parents obj/src/ftrace/standard_fds
> @mkdir --parents obj/src/ftrace/syscall/print_sys
> @mkdir --parents obj/src/ftrace/fd
> @mkdir --parents obj/src/ftrace/call
> $(CC) -c $< -o $@ $(CFLAGS) -D_GNU_SOURCE

# Just build libmy when we need these headers
libmy:
> $(MAKE) --directory=lib/my

# Include dependencies for the object files
include $(shell [ -d obj ] && find obj/ -type f -name '*.d')

# Remove all object files
clean:
> rm --recursive --force obj
> $(MAKE) --directory=lib/my clean

# Remove all object, binary and other produced files
fclean: clean
> rm --recursive --force $(BINARY_NAME)
> $(MAKE) --directory=lib/my fclean

# "Remakes" the project.
re:
> $(MAKE) clean
> $(MAKE) all
