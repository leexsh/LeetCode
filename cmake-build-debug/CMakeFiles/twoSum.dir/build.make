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
include CMakeFiles/twoSum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/twoSum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/twoSum.dir/flags.make

CMakeFiles/twoSum.dir/easily/001-twoSum.cpp.obj: CMakeFiles/twoSum.dir/flags.make
CMakeFiles/twoSum.dir/easily/001-twoSum.cpp.obj: ../easily/001-twoSum.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code\LeetCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/twoSum.dir/easily/001-twoSum.cpp.obj"
	D:\software\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\twoSum.dir\easily\001-twoSum.cpp.obj -c D:\Code\LeetCode\easily\001-twoSum.cpp

CMakeFiles/twoSum.dir/easily/001-twoSum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/twoSum.dir/easily/001-twoSum.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\LeetCode\easily\001-twoSum.cpp > CMakeFiles\twoSum.dir\easily\001-twoSum.cpp.i

CMakeFiles/twoSum.dir/easily/001-twoSum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/twoSum.dir/easily/001-twoSum.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\LeetCode\easily\001-twoSum.cpp -o CMakeFiles\twoSum.dir\easily\001-twoSum.cpp.s

# Object files for target twoSum
twoSum_OBJECTS = \
"CMakeFiles/twoSum.dir/easily/001-twoSum.cpp.obj"

# External object files for target twoSum
twoSum_EXTERNAL_OBJECTS =

twoSum.exe: CMakeFiles/twoSum.dir/easily/001-twoSum.cpp.obj
twoSum.exe: CMakeFiles/twoSum.dir/build.make
twoSum.exe: CMakeFiles/twoSum.dir/linklibs.rsp
twoSum.exe: CMakeFiles/twoSum.dir/objects1.rsp
twoSum.exe: CMakeFiles/twoSum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code\LeetCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable twoSum.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\twoSum.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/twoSum.dir/build: twoSum.exe

.PHONY : CMakeFiles/twoSum.dir/build

CMakeFiles/twoSum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\twoSum.dir\cmake_clean.cmake
.PHONY : CMakeFiles/twoSum.dir/clean

CMakeFiles/twoSum.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\LeetCode D:\Code\LeetCode D:\Code\LeetCode\cmake-build-debug D:\Code\LeetCode\cmake-build-debug D:\Code\LeetCode\cmake-build-debug\CMakeFiles\twoSum.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/twoSum.dir/depend

