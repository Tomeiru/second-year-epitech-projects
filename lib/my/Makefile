##
## EPITECH PROJECT, 2020
## libmy
## File description:
## Makefile for libmy
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

# We need GNU functions
override CFLAGS += -D_GNU_SOURCE

.PHONY: all clean fclean

.PREVIOUS: obj/%.o

HEADER_FILES := my/features.h my/macros.h my/stdio.h my/stdlib.h my/string.h
HEADER_FILES += my/my_string.h my/my_vector_type_template.txt

HEADER_FILES += my/cpp-like/algorithm.h my/cpp-like/iterator.h
HEADER_FILES += my/cpp-like/limits.h my/cpp-like/utility.h

HEADER_FILES := $(addprefix ../../include/, $(HEADER_FILES))

all: ../libmy.a $(HEADER_FILES)

# The sources for libmy
# Stuff related to stdio.h
SOURCE_FILES += stdio/xasprintf stdio/xvasprintf stdio/xfopen stdio/xfclose

# Stuff related to stdlib.h
SOURCE_FILES += stdlib/xmalloc stdlib/xcalloc stdlib/xrealloc
SOURCE_FILES += stdlib/xmalloc_out_of_memory

# Stuff related to string.h
SOURCE_FILES += string/xstrdup string/xstrndup

# Stuff related to my_string
SOURCE_FILES += my_string/new_from_string my_string/new_from_filename
SOURCE_FILES += my_string/new my_string/assign my_string/guarantee_can_expand
SOURCE_FILES += my_string/append my_string/append_vprintf my_string/insert
SOURCE_FILES += my_string/erase my_string/resize my_string/free

OBJECT_FILES := $(addprefix obj/src/, $(addsuffix .o, $(SOURCE_FILES)))

# r is for inserting with replacement
# c is for creating the archive without a warning when it doesn't exist
# s is for writing an index into the archive
../libmy.a: $(OBJECT_FILES)
> $(AR) rcs $@ $^

../../include/%.h: include/%.h
> @mkdir --parents ../../include/my/cpp-like
> flock $@ cp $< $@

../../include/%.txt: include/%.txt
> @mkdir --parents ../../include/my/cpp-like
> flock $@ cp $< $@

obj/%.o: %.c
> @mkdir --parents obj/src/stdio
> @mkdir --parents obj/src/stdlib
> @mkdir --parents obj/src/string
> @mkdir --parents obj/src/my_string
> $(CC) -c $< -o $@ $(CFLAGS)

# Include dependencies
include $(shell [ -d obj ] && find obj/ -type f -name '*.d')

# Remove all object files
clean:
> rm --recursive --force obj

# Remove all object, binary and other produced files
fclean: clean
> rm --recursive --force ../libmy.a $(HEADER_FILES)
