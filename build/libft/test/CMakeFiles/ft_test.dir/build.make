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
include libft/test/CMakeFiles/ft_test.dir/depend.make

# Include the progress variables for this target.
include libft/test/CMakeFiles/ft_test.dir/progress.make

# Include the compile flags for this target's objects.
include libft/test/CMakeFiles/ft_test.dir/flags.make

libft/test/CMakeFiles/ft_test.dir/src/main.c.o: libft/test/CMakeFiles/ft_test.dir/flags.make
libft/test/CMakeFiles/ft_test.dir/src/main.c.o: ../libft/test/src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/phrytsenko/fun_staff/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libft/test/CMakeFiles/ft_test.dir/src/main.c.o"
	cd /home/phrytsenko/fun_staff/push_swap/build/libft/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ft_test.dir/src/main.c.o   -c /home/phrytsenko/fun_staff/push_swap/libft/test/src/main.c

libft/test/CMakeFiles/ft_test.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ft_test.dir/src/main.c.i"
	cd /home/phrytsenko/fun_staff/push_swap/build/libft/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/phrytsenko/fun_staff/push_swap/libft/test/src/main.c > CMakeFiles/ft_test.dir/src/main.c.i

libft/test/CMakeFiles/ft_test.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ft_test.dir/src/main.c.s"
	cd /home/phrytsenko/fun_staff/push_swap/build/libft/test && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/phrytsenko/fun_staff/push_swap/libft/test/src/main.c -o CMakeFiles/ft_test.dir/src/main.c.s

libft/test/CMakeFiles/ft_test.dir/src/main.c.o.requires:

.PHONY : libft/test/CMakeFiles/ft_test.dir/src/main.c.o.requires

libft/test/CMakeFiles/ft_test.dir/src/main.c.o.provides: libft/test/CMakeFiles/ft_test.dir/src/main.c.o.requires
	$(MAKE) -f libft/test/CMakeFiles/ft_test.dir/build.make libft/test/CMakeFiles/ft_test.dir/src/main.c.o.provides.build
.PHONY : libft/test/CMakeFiles/ft_test.dir/src/main.c.o.provides

libft/test/CMakeFiles/ft_test.dir/src/main.c.o.provides.build: libft/test/CMakeFiles/ft_test.dir/src/main.c.o


# Object files for target ft_test
ft_test_OBJECTS = \
"CMakeFiles/ft_test.dir/src/main.c.o"

# External object files for target ft_test
ft_test_EXTERNAL_OBJECTS =

libft/test/ft_test: libft/test/CMakeFiles/ft_test.dir/src/main.c.o
libft/test/ft_test: libft/test/CMakeFiles/ft_test.dir/build.make
libft/test/ft_test: libft/libft.a
libft/test/ft_test: unity_test_framework/libunity.a
libft/test/ft_test: libft/test/CMakeFiles/ft_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/phrytsenko/fun_staff/push_swap/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ft_test"
	cd /home/phrytsenko/fun_staff/push_swap/build/libft/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ft_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libft/test/CMakeFiles/ft_test.dir/build: libft/test/ft_test

.PHONY : libft/test/CMakeFiles/ft_test.dir/build

libft/test/CMakeFiles/ft_test.dir/requires: libft/test/CMakeFiles/ft_test.dir/src/main.c.o.requires

.PHONY : libft/test/CMakeFiles/ft_test.dir/requires

libft/test/CMakeFiles/ft_test.dir/clean:
	cd /home/phrytsenko/fun_staff/push_swap/build/libft/test && $(CMAKE_COMMAND) -P CMakeFiles/ft_test.dir/cmake_clean.cmake
.PHONY : libft/test/CMakeFiles/ft_test.dir/clean

libft/test/CMakeFiles/ft_test.dir/depend:
	cd /home/phrytsenko/fun_staff/push_swap/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/phrytsenko/fun_staff/push_swap /home/phrytsenko/fun_staff/push_swap/libft/test /home/phrytsenko/fun_staff/push_swap/build /home/phrytsenko/fun_staff/push_swap/build/libft/test /home/phrytsenko/fun_staff/push_swap/build/libft/test/CMakeFiles/ft_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libft/test/CMakeFiles/ft_test.dir/depend

