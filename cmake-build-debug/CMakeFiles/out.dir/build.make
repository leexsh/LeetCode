# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\software\CLion2020.1\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\software\CLion2020.1\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code\LeetCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\LeetCode\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/out.dir/flags.make

CMakeFiles/out.dir/06_medium/64-MinimumPathSum.cpp.obj: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/06_medium/64-MinimumPathSum.cpp.obj: ../06_medium/64-MinimumPathSum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code\LeetCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/out.dir/06_medium/64-MinimumPathSum.cpp.obj"
	D:\software\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\out.dir\06_medium\64-MinimumPathSum.cpp.obj -c D:\Code\LeetCode\06_medium\64-MinimumPathSum.cpp

CMakeFiles/out.dir/06_medium/64-MinimumPathSum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/06_medium/64-MinimumPathSum.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\LeetCode\06_medium\64-MinimumPathSum.cpp > CMakeFiles\out.dir\06_medium\64-MinimumPathSum.cpp.i

CMakeFiles/out.dir/06_medium/64-MinimumPathSum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/06_medium/64-MinimumPathSum.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\LeetCode\06_medium\64-MinimumPathSum.cpp -o CMakeFiles\out.dir\06_medium\64-MinimumPathSum.cpp.s

# Object files for target out
out_OBJECTS = \
"CMakeFiles/out.dir/06_medium/64-MinimumPathSum.cpp.obj"

# External object files for target out
out_EXTERNAL_OBJECTS =

out.exe: CMakeFiles/out.dir/06_medium/64-MinimumPathSum.cpp.obj
out.exe: CMakeFiles/out.dir/build.make
out.exe: CMakeFiles/out.dir/linklibs.rsp
out.exe: CMakeFiles/out.dir/objects1.rsp
out.exe: CMakeFiles/out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code\LeetCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable out.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\out.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/out.dir/build: out.exe

.PHONY : CMakeFiles/out.dir/build

CMakeFiles/out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\out.dir\cmake_clean.cmake
.PHONY : CMakeFiles/out.dir/clean

CMakeFiles/out.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\LeetCode D:\Code\LeetCode D:\Code\LeetCode\cmake-build-debug D:\Code\LeetCode\cmake-build-debug D:\Code\LeetCode\cmake-build-debug\CMakeFiles\out.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/out.dir/depend

