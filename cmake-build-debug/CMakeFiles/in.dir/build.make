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
include CMakeFiles/in.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/in.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/in.dir/flags.make

CMakeFiles/in.dir/easily/28-ImplementstrStr.cpp.obj: CMakeFiles/in.dir/flags.make
CMakeFiles/in.dir/easily/28-ImplementstrStr.cpp.obj: ../easily/28-ImplementstrStr.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code\LeetCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/in.dir/easily/28-ImplementstrStr.cpp.obj"
	D:\software\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\in.dir\easily\28-ImplementstrStr.cpp.obj -c D:\Code\LeetCode\easily\28-ImplementstrStr.cpp

CMakeFiles/in.dir/easily/28-ImplementstrStr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/in.dir/easily/28-ImplementstrStr.cpp.i"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\LeetCode\easily\28-ImplementstrStr.cpp > CMakeFiles\in.dir\easily\28-ImplementstrStr.cpp.i

CMakeFiles/in.dir/easily/28-ImplementstrStr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/in.dir/easily/28-ImplementstrStr.cpp.s"
	D:\software\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\LeetCode\easily\28-ImplementstrStr.cpp -o CMakeFiles\in.dir\easily\28-ImplementstrStr.cpp.s

# Object files for target in
in_OBJECTS = \
"CMakeFiles/in.dir/easily/28-ImplementstrStr.cpp.obj"

# External object files for target in
in_EXTERNAL_OBJECTS =

in.exe: CMakeFiles/in.dir/easily/28-ImplementstrStr.cpp.obj
in.exe: CMakeFiles/in.dir/build.make
in.exe: CMakeFiles/in.dir/linklibs.rsp
in.exe: CMakeFiles/in.dir/objects1.rsp
in.exe: CMakeFiles/in.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code\LeetCode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable in.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\in.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/in.dir/build: in.exe

.PHONY : CMakeFiles/in.dir/build

CMakeFiles/in.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\in.dir\cmake_clean.cmake
.PHONY : CMakeFiles/in.dir/clean

CMakeFiles/in.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\LeetCode D:\Code\LeetCode D:\Code\LeetCode\cmake-build-debug D:\Code\LeetCode\cmake-build-debug D:\Code\LeetCode\cmake-build-debug\CMakeFiles\in.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/in.dir/depend

