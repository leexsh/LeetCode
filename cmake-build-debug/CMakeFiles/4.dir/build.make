# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = D:\software\CLion2019\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\software\CLion2019\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code\LeetCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\LeetCode\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/4.dir/flags.make

CMakeFiles/4.dir/hard/4-MedianofTwoSortedArrays.cpp.obj: CMakeFiles/4.dir/flags.make
CMakeFiles/4.dir/hard/4-MedianofTwoSortedArrays.cpp.obj: ../hard/4-MedianofTwoSortedArrays.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code\LeetCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/4.dir/hard/4-MedianofTwoSortedArrays.cpp.obj"
	D:\software\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\4.dir\hard\4-MedianofTwoSortedArrays.cpp.obj -c D:\Code\LeetCode\hard\4-MedianofTwoSortedArrays.cpp

CMakeFiles/4.dir/hard/4-MedianofTwoSortedArrays.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/4.dir/hard/4-MedianofTwoSortedArrays.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\LeetCode\hard\4-MedianofTwoSortedArrays.cpp > CMakeFiles\4.dir\hard\4-MedianofTwoSortedArrays.cpp.i

CMakeFiles/4.dir/hard/4-MedianofTwoSortedArrays.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/4.dir/hard/4-MedianofTwoSortedArrays.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\LeetCode\hard\4-MedianofTwoSortedArrays.cpp -o CMakeFiles\4.dir\hard\4-MedianofTwoSortedArrays.cpp.s

# Object files for target 4
4_OBJECTS = \
"CMakeFiles/4.dir/hard/4-MedianofTwoSortedArrays.cpp.obj"

# External object files for target 4
4_EXTERNAL_OBJECTS =

4.exe: CMakeFiles/4.dir/hard/4-MedianofTwoSortedArrays.cpp.obj
4.exe: CMakeFiles/4.dir/build.make
4.exe: CMakeFiles/4.dir/linklibs.rsp
4.exe: CMakeFiles/4.dir/objects1.rsp
4.exe: CMakeFiles/4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code\LeetCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/4.dir/build: 4.exe

.PHONY : CMakeFiles/4.dir/build

CMakeFiles/4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/4.dir/clean

CMakeFiles/4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\LeetCode D:\Code\LeetCode D:\Code\LeetCode\cmake-build-debug D:\Code\LeetCode\cmake-build-debug D:\Code\LeetCode\cmake-build-debug\CMakeFiles\4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/4.dir/depend

