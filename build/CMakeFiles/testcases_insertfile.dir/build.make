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
include CMakeFiles/testcases_insertfile.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testcases_insertfile.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testcases_insertfile.dir/flags.make

CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.o: CMakeFiles/testcases_insertfile.dir/flags.make
CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.o: ../unit_test/testcases_insertfile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.o   -c /home/ndp/Documents/FileHandler/unit_test/testcases_insertfile.c

CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/unit_test/testcases_insertfile.c > CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.i

CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/unit_test/testcases_insertfile.c -o CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.s

CMakeFiles/testcases_insertfile.dir/src/file_utils.c.o: CMakeFiles/testcases_insertfile.dir/flags.make
CMakeFiles/testcases_insertfile.dir/src/file_utils.c.o: ../src/file_utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/testcases_insertfile.dir/src/file_utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testcases_insertfile.dir/src/file_utils.c.o   -c /home/ndp/Documents/FileHandler/src/file_utils.c

CMakeFiles/testcases_insertfile.dir/src/file_utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testcases_insertfile.dir/src/file_utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/src/file_utils.c > CMakeFiles/testcases_insertfile.dir/src/file_utils.c.i

CMakeFiles/testcases_insertfile.dir/src/file_utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testcases_insertfile.dir/src/file_utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/src/file_utils.c -o CMakeFiles/testcases_insertfile.dir/src/file_utils.c.s

CMakeFiles/testcases_insertfile.dir/src/unity.c.o: CMakeFiles/testcases_insertfile.dir/flags.make
CMakeFiles/testcases_insertfile.dir/src/unity.c.o: ../src/unity.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/testcases_insertfile.dir/src/unity.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/testcases_insertfile.dir/src/unity.c.o   -c /home/ndp/Documents/FileHandler/src/unity.c

CMakeFiles/testcases_insertfile.dir/src/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/testcases_insertfile.dir/src/unity.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/src/unity.c > CMakeFiles/testcases_insertfile.dir/src/unity.c.i

CMakeFiles/testcases_insertfile.dir/src/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/testcases_insertfile.dir/src/unity.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/src/unity.c -o CMakeFiles/testcases_insertfile.dir/src/unity.c.s

# Object files for target testcases_insertfile
testcases_insertfile_OBJECTS = \
"CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.o" \
"CMakeFiles/testcases_insertfile.dir/src/file_utils.c.o" \
"CMakeFiles/testcases_insertfile.dir/src/unity.c.o"

# External object files for target testcases_insertfile
testcases_insertfile_EXTERNAL_OBJECTS =

testcases_insertfile: CMakeFiles/testcases_insertfile.dir/unit_test/testcases_insertfile.c.o
testcases_insertfile: CMakeFiles/testcases_insertfile.dir/src/file_utils.c.o
testcases_insertfile: CMakeFiles/testcases_insertfile.dir/src/unity.c.o
testcases_insertfile: CMakeFiles/testcases_insertfile.dir/build.make
testcases_insertfile: CMakeFiles/testcases_insertfile.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable testcases_insertfile"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testcases_insertfile.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testcases_insertfile.dir/build: testcases_insertfile

.PHONY : CMakeFiles/testcases_insertfile.dir/build

CMakeFiles/testcases_insertfile.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testcases_insertfile.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testcases_insertfile.dir/clean

CMakeFiles/testcases_insertfile.dir/depend:
	cd /home/ndp/Documents/FileHandler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ndp/Documents/FileHandler /home/ndp/Documents/FileHandler /home/ndp/Documents/FileHandler/build /home/ndp/Documents/FileHandler/build /home/ndp/Documents/FileHandler/build/CMakeFiles/testcases_insertfile.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testcases_insertfile.dir/depend

