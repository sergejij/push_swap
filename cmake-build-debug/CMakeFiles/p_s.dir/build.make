# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Users/ubartemi/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/ubartemi/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ubartemi/CLionProjects/p_s

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ubartemi/CLionProjects/p_s/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/p_s.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p_s.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p_s.dir/flags.make

CMakeFiles/p_s.dir/main.c.o: CMakeFiles/p_s.dir/flags.make
CMakeFiles/p_s.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/CLionProjects/p_s/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/p_s.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/p_s.dir/main.c.o   -c /Users/ubartemi/CLionProjects/p_s/main.c

CMakeFiles/p_s.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/p_s.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/CLionProjects/p_s/main.c > CMakeFiles/p_s.dir/main.c.i

CMakeFiles/p_s.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/p_s.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/CLionProjects/p_s/main.c -o CMakeFiles/p_s.dir/main.c.s

CMakeFiles/p_s.dir/auxiliary_functions.c.o: CMakeFiles/p_s.dir/flags.make
CMakeFiles/p_s.dir/auxiliary_functions.c.o: ../auxiliary_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ubartemi/CLionProjects/p_s/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/p_s.dir/auxiliary_functions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/p_s.dir/auxiliary_functions.c.o   -c /Users/ubartemi/CLionProjects/p_s/auxiliary_functions.c

CMakeFiles/p_s.dir/auxiliary_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/p_s.dir/auxiliary_functions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/ubartemi/CLionProjects/p_s/auxiliary_functions.c > CMakeFiles/p_s.dir/auxiliary_functions.c.i

CMakeFiles/p_s.dir/auxiliary_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/p_s.dir/auxiliary_functions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/ubartemi/CLionProjects/p_s/auxiliary_functions.c -o CMakeFiles/p_s.dir/auxiliary_functions.c.s

# Object files for target p_s
p_s_OBJECTS = \
"CMakeFiles/p_s.dir/main.c.o" \
"CMakeFiles/p_s.dir/auxiliary_functions.c.o"

# External object files for target p_s
p_s_EXTERNAL_OBJECTS =

p_s: CMakeFiles/p_s.dir/main.c.o
p_s: CMakeFiles/p_s.dir/auxiliary_functions.c.o
p_s: CMakeFiles/p_s.dir/build.make
p_s: ../libft/libft.a
p_s: CMakeFiles/p_s.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ubartemi/CLionProjects/p_s/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable p_s"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p_s.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p_s.dir/build: p_s

.PHONY : CMakeFiles/p_s.dir/build

CMakeFiles/p_s.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p_s.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p_s.dir/clean

CMakeFiles/p_s.dir/depend:
	cd /Users/ubartemi/CLionProjects/p_s/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ubartemi/CLionProjects/p_s /Users/ubartemi/CLionProjects/p_s /Users/ubartemi/CLionProjects/p_s/cmake-build-debug /Users/ubartemi/CLionProjects/p_s/cmake-build-debug /Users/ubartemi/CLionProjects/p_s/cmake-build-debug/CMakeFiles/p_s.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p_s.dir/depend

