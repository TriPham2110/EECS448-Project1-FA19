# Project: EECS 448 Project 1 - Battleship
# Date:    06 September 2019

# -- General notes about Makefiles --
# Documentation:
# https://www.gnu.org/software/make/manual/html_node/index.html#SEC_Contents
#
# Highlights:
# Variables in Makefiles work like C preprocessor directives: text-based
# substitution. The names are case sensitive and cannot contain :, #, =, or
# whitespace.
#
# There are four ways to assign a variable: =, :=, ::=, and ?= but
# := and ::= are equivalent to one another. Of the two only ::= is
# POSIXLY_CORRECT.
#
# = recursively expands the variable if the definition includes other variables
#     every time the variable is substituted (used)
# := is a simply expanded variable. Its value is scanned once and any expansions
#     happen at the time of assignment.
# ?= assigns a variable if it has not yet been assigned. Be aware that an empty
#     value is still an assignment.

# --- Program Name ---
FILENAME := BattleShip

# --- Include Dirs ---
SRCDIR := src
INCDIR := inc
OBJDIR := obj

# --- Debugging ---
MT := valgrind
MFLAGS := --leak-check=full --show-leak-kinds=all --track-origins=yes

# --- Compiling ---
# CXX is typically an environment variable, but just in case it happens to be
# clang, we'll enforce g++
CXX := g++
# You probably don't want to change these all by hand. Changing this is even
# quicker than using sed, Vi, or C-M-%. The shell command expands to flags that
# GTK+ requires to compile.
CFLAGS := -std=c++11 -Wall -g
LDFLAGS := $(CFLAGS) -c
# The $@ refers to the target. There's no reason to write it twice.
# Recursively expands to target name of any rule that uses the variable.
EXPORT = -o $@
DEPENDENCIES := $(OBJDIR)/main.o

# --- Phonies ---
# Phonies essentially declare a target as being unrelated to actual files in
# the project directory, and allow you to make files with the same name as
# such a target without worrying about aliasing commands.
.PHONY: clean rebuild memcheck debug $(SRCDIR) $(INCDIR) $(OBJDIR)

# --- Compilation Options ---
# By convention 'all' compiles the entire program.
all: $(DEPENDENCIES)
	$(CXX) $(CFLAGS) $(DEPENDENCIES) -o $(FILENAME)

# install: all
# By definition this should place the executable in a standard location, either
# in /usr/bin or /usr/local/bin

# --- Source Files ---
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(LDFLAGS) $(SRCDIR)/main.cpp $(EXPORT)


# --- Housekeeping ---
# Clear out all the cobwebs and recompile everything.
rebuild: clean all

# Removes object files as well as any Emacs autosave files. "| true" (or true)
# causes rebuild to work even if there's nothing to clean. 2&>1 is a shell
# script idiom for I/O redirection. Basically, any output that would go to
# stderr (2) is redirected (>&) to stdout (1). It lets us see when rm can't find
# anything to remove. By the way, keyboard input comes through channel
# 0 (stdin)!
clean:
	rm $(OBJDIR)/*.o *.*~ \#*\# | true 2>&1

memcheck:
	$(MT) $(MFLAGS) ./$(FILENAME)
