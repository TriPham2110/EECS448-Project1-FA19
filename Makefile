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
SRCDIR := ./src
INCDIR := ./inc
OBJDIR := ./obj

# --- Debugging ---
# This is here but my recommendation is not to run it. There is a lot of lazy
# memory hacking in GTK that causes Valgrind to go a little crazy. There was
# an effort to make a list of things Valgrind should ignore and not report
# since they are GTK's fault and not yours, but it was not updated for GTK as
# far as we can tell. You will know when your program has no memory errors when
# using it does not cause it to crash.
MT := valgrind
MFLAGS := --leak-check=full \
          --show-leak-kinds=all \
          --leak-resolution=high \
          --track-origins=yes \
          --log-file=vgdump

# --- Compiling ---
# CXX is typically an environment variable, but just in case it happens to be
# clang, we'll enforce g++
CXX := g++

# --- Compiliing: Detect System Type to Automatically Append Paths Later ---
SYSTYPE := $(shell uname -s)

# --- Compiling: Set Compiler Flags
# You probably don't want to change these all by hand. Changing this is even
# quicker than using sed, Vi, or C-M-%. The shell command expands to flags that
# GTK+ requires to compile.
# -g -- Generate debugging information
# -c -- Do not run the linker
# -o -- Name the output whatever comes after
# -W -- Makes the compiler complain if you go too far off-standard
# -I$(INCDIR) -- Makes the compiler search /inc for headers -- this is good
#                because errors become informative instead of being hidden
#                behind a series of recursive includes.
GENFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -Wconversion -I$(INCDIR)
GTKCXXFLAGS = $(shell pkg-config gtkmm-3.0 --cflags)
GTKLDFLAGS = $(shell pkg-config gtkmm-3.0 --libs)
CXXFLAGS = $(GENFLAGS) $(GTKCXXFLAGS) -g -c
LDFLAGS = $(GENFLAGS) $(GTKLDFLAGS) -g

# The $@ refers to the target. There's no reason to write it twice.
# $< refers to the first thing after the colon
# $^ refers to everything after the colon
# Recursively expands to target name of any rule that uses the variable.
EXPORT = -o $@

DEPENDENCIES = $(OBJDIR)/main.o $(OBJDIR)/executive.o\
               $(OBJDIR)/window.o $(OBJDIR)/gui.o\
               $(OBJDIR)/mainmenu.o $(OBJDIR)/field.o\
               $(OBJDIR)/fieldcontainer.o $(OBJDIR)/changingplayerwindow.o

# --- Phonies ---
# Phonies essentially declare a target as being unrelated to actual files in
# the project directory, and allow you to make files with the same name as
# such a target without worrying about aliasing commands.
.PHONY: clean rebuild memcheck debug $(SRCDIR) $(INCDIR) $(OBJDIR)

# --- Compilation Options ---
# By convention 'all' compiles the entire program.
all: pre-build $(DEPENDENCIES)
	$(CXX) $(DEPENDENCIES) $(LDFLAGS) -o $(FILENAME)

# install: all
# By convention this should place the executable in a standard location, either
# in /usr/bin or /usr/local/bin
pre-build:
# Set up MacOS Environment
ifeq ($(SYSTYPE),Darwin)
	MAC_LIBFFI=/usr/local/opt/libffi/lib/pkgconfig/
	PKG_CONFIG_PATH=${MAC_LIBFFI}:${PKG_CONFIG_PATH}
endif
# Set up Linux Environment
#ifeq ($(SYSTYPE),Linux)
#endif

# --- Source Files ---
# TODO: Reduce this to one automatic line.
$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CXX) $(CXXFLAGS) $< $(EXPORT)

$(OBJDIR)/executive.o: $(SRCDIR)/executive.cpp
	$(CXX) $(CXXFLAGS) $< $(EXPORT)

$(OBJDIR)/window.o: $(SRCDIR)/window.cpp
	$(CXX) $(CXXFLAGS) $< $(EXPORT)

$(OBJDIR)/gui.o: $(SRCDIR)/gui.cpp
	$(CXX) $(CXXFLAGS) $< $(EXPORT)

$(OBJDIR)/mainmenu.o: $(SRCDIR)/mainmenu.cpp
	$(CXX) $(CXXFLAGS) $< $(EXPORT)

$(OBJDIR)/fieldcontainer.o: $(SRCDIR)/fieldcontainer.cpp
	$(CXX) $(CXXFLAGS) $< $(EXPORT)

$(OBJDIR)/field.o: $(SRCDIR)/field.cpp
	$(CXX) $(CXXFLAGS) $< $(EXPORT)

$(OBJDIR)/changingplayerwindow.o: $(SRCDIR)/changingplayerwindow.cpp
	$(CXX) $(CXXFLAGS) $< $(EXPORT)

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
