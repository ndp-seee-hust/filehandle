# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/ndp/Documents/FileHandler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ndp/Documents/FileHandler/build

# Include any dependencies generated for this target.
include CMakeFiles/test_remove.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_remove.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_remove.dir/flags.make

CMakeFiles/test_remove.dir/test/test_remove.c.o: CMakeFiles/test_remove.dir/flags.make
CMakeFiles/test_remove.dir/test/test_remove.c.o: ../test/test_remove.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_remove.dir/test/test_remove.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_remove.dir/test/test_remove.c.o   -c /home/ndp/Documents/FileHandler/test/test_remove.c

CMakeFiles/test_remove.dir/test/test_remove.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_remove.dir/test/test_remove.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/test/test_remove.c > CMakeFiles/test_remove.dir/test/test_remove.c.i

CMakeFiles/test_remove.dir/test/test_remove.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_remove.dir/test/test_remove.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/test/test_remove.c -o CMakeFiles/test_remove.dir/test/test_remove.c.s

CMakeFiles/test_remove.dir/src/file_utils.c.o: CMakeFiles/test_remove.dir/flags.make
CMakeFiles/test_remove.dir/src/file_utils.c.o: ../src/file_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_remove.dir/src/file_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_remove.dir/src/file_utils.c.o   -c /home/ndp/Documents/FileHandler/src/file_utils.c

CMakeFiles/test_remove.dir/src/file_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_remove.dir/src/file_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/src/file_utils.c > CMakeFiles/test_remove.dir/src/file_utils.c.i

CMakeFiles/test_remove.dir/src/file_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_remove.dir/src/file_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/src/file_utils.c -o CMakeFiles/test_remove.dir/src/file_utils.c.s

# Object files for target test_remove
test_remove_OBJECTS = \
"CMakeFiles/test_remove.dir/test/test_remove.c.o" \
"CMakeFiles/test_remove.dir/src/file_utils.c.o"

# External object files for target test_remove
test_remove_EXTERNAL_OBJECTS =

test_remove: CMakeFiles/test_remove.dir/test/test_remove.c.o
test_remove: CMakeFiles/test_remove.dir/src/file_utils.c.o
test_remove: CMakeFiles/test_remove.dir/build.make
test_remove: CMakeFiles/test_remove.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable test_remove"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_remove.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_remove.dir/build: test_remove

.PHONY : CMakeFiles/test_remove.dir/build

CMakeFiles/test_remove.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_remove.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_remove.dir/clean

CMakeFiles/test_remove.dir/depend:
	cd /home/ndp/Documents/FileHandler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ndp/Documents/FileHandler /home/ndp/Documents/FileHandler /home/ndp/Documents/FileHandler/build /home/ndp/Documents/FileHandler/build /home/ndp/Documents/FileHandler/build/CMakeFiles/test_remove.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_remove.dir/depend

