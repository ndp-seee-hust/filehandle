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
include CMakeFiles/test_fix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_fix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_fix.dir/flags.make

CMakeFiles/test_fix.dir/unit_test/test_fix.c.o: CMakeFiles/test_fix.dir/flags.make
CMakeFiles/test_fix.dir/unit_test/test_fix.c.o: ../unit_test/test_fix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_fix.dir/unit_test/test_fix.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_fix.dir/unit_test/test_fix.c.o   -c /home/ndp/Documents/FileHandler/unit_test/test_fix.c

CMakeFiles/test_fix.dir/unit_test/test_fix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_fix.dir/unit_test/test_fix.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/unit_test/test_fix.c > CMakeFiles/test_fix.dir/unit_test/test_fix.c.i

CMakeFiles/test_fix.dir/unit_test/test_fix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_fix.dir/unit_test/test_fix.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/unit_test/test_fix.c -o CMakeFiles/test_fix.dir/unit_test/test_fix.c.s

CMakeFiles/test_fix.dir/src/filehandle.c.o: CMakeFiles/test_fix.dir/flags.make
CMakeFiles/test_fix.dir/src/filehandle.c.o: ../src/filehandle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_fix.dir/src/filehandle.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_fix.dir/src/filehandle.c.o   -c /home/ndp/Documents/FileHandler/src/filehandle.c

CMakeFiles/test_fix.dir/src/filehandle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_fix.dir/src/filehandle.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/src/filehandle.c > CMakeFiles/test_fix.dir/src/filehandle.c.i

CMakeFiles/test_fix.dir/src/filehandle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_fix.dir/src/filehandle.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/src/filehandle.c -o CMakeFiles/test_fix.dir/src/filehandle.c.s

CMakeFiles/test_fix.dir/src/unity.c.o: CMakeFiles/test_fix.dir/flags.make
CMakeFiles/test_fix.dir/src/unity.c.o: ../src/unity.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test_fix.dir/src/unity.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_fix.dir/src/unity.c.o   -c /home/ndp/Documents/FileHandler/src/unity.c

CMakeFiles/test_fix.dir/src/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_fix.dir/src/unity.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ndp/Documents/FileHandler/src/unity.c > CMakeFiles/test_fix.dir/src/unity.c.i

CMakeFiles/test_fix.dir/src/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_fix.dir/src/unity.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ndp/Documents/FileHandler/src/unity.c -o CMakeFiles/test_fix.dir/src/unity.c.s

# Object files for target test_fix
test_fix_OBJECTS = \
"CMakeFiles/test_fix.dir/unit_test/test_fix.c.o" \
"CMakeFiles/test_fix.dir/src/filehandle.c.o" \
"CMakeFiles/test_fix.dir/src/unity.c.o"

# External object files for target test_fix
test_fix_EXTERNAL_OBJECTS =

test_fix: CMakeFiles/test_fix.dir/unit_test/test_fix.c.o
test_fix: CMakeFiles/test_fix.dir/src/filehandle.c.o
test_fix: CMakeFiles/test_fix.dir/src/unity.c.o
test_fix: CMakeFiles/test_fix.dir/build.make
test_fix: CMakeFiles/test_fix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ndp/Documents/FileHandler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable test_fix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_fix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_fix.dir/build: test_fix

.PHONY : CMakeFiles/test_fix.dir/build

CMakeFiles/test_fix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_fix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_fix.dir/clean

CMakeFiles/test_fix.dir/depend:
	cd /home/ndp/Documents/FileHandler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ndp/Documents/FileHandler /home/ndp/Documents/FileHandler /home/ndp/Documents/FileHandler/build /home/ndp/Documents/FileHandler/build /home/ndp/Documents/FileHandler/build/CMakeFiles/test_fix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_fix.dir/depend

