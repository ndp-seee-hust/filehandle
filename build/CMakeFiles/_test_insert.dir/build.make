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
include CMakeFiles/_test_insert.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/_test_insert.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/_test_insert.dir/flags.make

CMakeFiles/_test_insert.dir/unit_test/test_insert.c.o: CMakeFiles/_test_insert.dir/flags.make
CMakeFiles/_test_insert.dir/unit_test/test_insert.c.o: ../unit_test/test_insert.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/_test_insert.dir/unit_test/test_insert.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/_test_insert.dir/unit_test/test_insert.c.o   -c /home/ndp/Documents/FileHandler/unit_test/test_insert.c

CMakeFiles/_test_insert.dir/unit_test/test_insert.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_test_insert.dir/unit_test/test_insert.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/unit_test/test_insert.c > CMakeFiles/_test_insert.dir/unit_test/test_insert.c.i

CMakeFiles/_test_insert.dir/unit_test/test_insert.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_test_insert.dir/unit_test/test_insert.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/unit_test/test_insert.c -o CMakeFiles/_test_insert.dir/unit_test/test_insert.c.s

CMakeFiles/_test_insert.dir/src/filehandle.c.o: CMakeFiles/_test_insert.dir/flags.make
CMakeFiles/_test_insert.dir/src/filehandle.c.o: ../src/filehandle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/_test_insert.dir/src/filehandle.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/_test_insert.dir/src/filehandle.c.o   -c /home/ndp/Documents/FileHandler/src/filehandle.c

CMakeFiles/_test_insert.dir/src/filehandle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_test_insert.dir/src/filehandle.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/src/filehandle.c > CMakeFiles/_test_insert.dir/src/filehandle.c.i

CMakeFiles/_test_insert.dir/src/filehandle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_test_insert.dir/src/filehandle.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/src/filehandle.c -o CMakeFiles/_test_insert.dir/src/filehandle.c.s

CMakeFiles/_test_insert.dir/src/unity.c.o: CMakeFiles/_test_insert.dir/flags.make
CMakeFiles/_test_insert.dir/src/unity.c.o: ../src/unity.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/_test_insert.dir/src/unity.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/_test_insert.dir/src/unity.c.o   -c /home/ndp/Documents/FileHandler/src/unity.c

CMakeFiles/_test_insert.dir/src/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/_test_insert.dir/src/unity.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/src/unity.c > CMakeFiles/_test_insert.dir/src/unity.c.i

CMakeFiles/_test_insert.dir/src/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/_test_insert.dir/src/unity.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/src/unity.c -o CMakeFiles/_test_insert.dir/src/unity.c.s

# Object files for target _test_insert
_test_insert_OBJECTS = \
"CMakeFiles/_test_insert.dir/unit_test/test_insert.c.o" \
"CMakeFiles/_test_insert.dir/src/filehandle.c.o" \
"CMakeFiles/_test_insert.dir/src/unity.c.o"

# External object files for target _test_insert
_test_insert_EXTERNAL_OBJECTS =

_test_insert: CMakeFiles/_test_insert.dir/unit_test/test_insert.c.o
_test_insert: CMakeFiles/_test_insert.dir/src/filehandle.c.o
_test_insert: CMakeFiles/_test_insert.dir/src/unity.c.o
_test_insert: CMakeFiles/_test_insert.dir/build.make
_test_insert: CMakeFiles/_test_insert.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable _test_insert"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/_test_insert.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/_test_insert.dir/build: _test_insert

.PHONY : CMakeFiles/_test_insert.dir/build

CMakeFiles/_test_insert.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/_test_insert.dir/cmake_clean.cmake
.PHONY : CMakeFiles/_test_insert.dir/clean

CMakeFiles/_test_insert.dir/depend:
	cd /home/ndp/Documents/FileHandler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ndp/Documents/FileHandler /home/ndp/Documents/FileHandler /home/ndp/Documents/FileHandler/build /home/ndp/Documents/FileHandler/build /home/ndp/Documents/FileHandler/build/CMakeFiles/_test_insert.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/_test_insert.dir/depend

