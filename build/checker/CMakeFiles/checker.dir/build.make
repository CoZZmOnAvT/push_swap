# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/phrytsenko/fun_staff/push_swap

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/phrytsenko/fun_staff/push_swap/build

# Include any dependencies generated for this target.
include checker/CMakeFiles/checker.dir/depend.make

# Include the progress variables for this target.
include checker/CMakeFiles/checker.dir/progress.make

# Include the compile flags for this target's objects.
include checker/CMakeFiles/checker.dir/flags.make

checker/CMakeFiles/checker.dir/src/main.c.o: checker/CMakeFiles/checker.dir/flags.make
checker/CMakeFiles/checker.dir/src/main.c.o: ../checker/src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phrytsenko/fun_staff/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object checker/CMakeFiles/checker.dir/src/main.c.o"
	cd /home/phrytsenko/fun_staff/push_swap/build/checker && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/checker.dir/src/main.c.o   -c /home/phrytsenko/fun_staff/push_swap/checker/src/main.c

checker/CMakeFiles/checker.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/checker.dir/src/main.c.i"
	cd /home/phrytsenko/fun_staff/push_swap/build/checker && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/phrytsenko/fun_staff/push_swap/checker/src/main.c > CMakeFiles/checker.dir/src/main.c.i

checker/CMakeFiles/checker.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/checker.dir/src/main.c.s"
	cd /home/phrytsenko/fun_staff/push_swap/build/checker && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/phrytsenko/fun_staff/push_swap/checker/src/main.c -o CMakeFiles/checker.dir/src/main.c.s

checker/CMakeFiles/checker.dir/src/main.c.o.requires:

.PHONY : checker/CMakeFiles/checker.dir/src/main.c.o.requires

checker/CMakeFiles/checker.dir/src/main.c.o.provides: checker/CMakeFiles/checker.dir/src/main.c.o.requires
	$(MAKE) -f checker/CMakeFiles/checker.dir/build.make checker/CMakeFiles/checker.dir/src/main.c.o.provides.build
.PHONY : checker/CMakeFiles/checker.dir/src/main.c.o.provides

checker/CMakeFiles/checker.dir/src/main.c.o.provides.build: checker/CMakeFiles/checker.dir/src/main.c.o


# Object files for target checker
checker_OBJECTS = \
"CMakeFiles/checker.dir/src/main.c.o"

# External object files for target checker
checker_EXTERNAL_OBJECTS =

checker/checker: checker/CMakeFiles/checker.dir/src/main.c.o
checker/checker: checker/CMakeFiles/checker.dir/build.make
checker/checker: libft/libft.a
checker/checker: checker/CMakeFiles/checker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/phrytsenko/fun_staff/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable checker"
	cd /home/phrytsenko/fun_staff/push_swap/build/checker && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/checker.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
checker/CMakeFiles/checker.dir/build: checker/checker

.PHONY : checker/CMakeFiles/checker.dir/build

checker/CMakeFiles/checker.dir/requires: checker/CMakeFiles/checker.dir/src/main.c.o.requires

.PHONY : checker/CMakeFiles/checker.dir/requires

checker/CMakeFiles/checker.dir/clean:
	cd /home/phrytsenko/fun_staff/push_swap/build/checker && $(CMAKE_COMMAND) -P CMakeFiles/checker.dir/cmake_clean.cmake
.PHONY : checker/CMakeFiles/checker.dir/clean

checker/CMakeFiles/checker.dir/depend:
	cd /home/phrytsenko/fun_staff/push_swap/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phrytsenko/fun_staff/push_swap /home/phrytsenko/fun_staff/push_swap/checker /home/phrytsenko/fun_staff/push_swap/build /home/phrytsenko/fun_staff/push_swap/build/checker /home/phrytsenko/fun_staff/push_swap/build/checker/CMakeFiles/checker.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : checker/CMakeFiles/checker.dir/depend

