# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /Volumes/cmake-3.3.2-Darwin-x86_64/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Volumes/cmake-3.3.2-Darwin-x86_64/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Prachi/Documents/kunal_wrk/fbPerformance

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Prachi/Documents/kunal_wrk/fbPerformance

# Include any dependencies generated for this target.
include CMakeFiles/fbExample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fbExample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fbExample.dir/flags.make

CMakeFiles/fbExample.dir/FbExample.o: CMakeFiles/fbExample.dir/flags.make
CMakeFiles/fbExample.dir/FbExample.o: FbExample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Prachi/Documents/kunal_wrk/fbPerformance/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fbExample.dir/FbExample.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/fbExample.dir/FbExample.o -c /Users/Prachi/Documents/kunal_wrk/fbPerformance/FbExample.cpp

CMakeFiles/fbExample.dir/FbExample.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fbExample.dir/FbExample.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/Prachi/Documents/kunal_wrk/fbPerformance/FbExample.cpp > CMakeFiles/fbExample.dir/FbExample.i

CMakeFiles/fbExample.dir/FbExample.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fbExample.dir/FbExample.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/Prachi/Documents/kunal_wrk/fbPerformance/FbExample.cpp -o CMakeFiles/fbExample.dir/FbExample.s

CMakeFiles/fbExample.dir/FbExample.o.requires:

.PHONY : CMakeFiles/fbExample.dir/FbExample.o.requires

CMakeFiles/fbExample.dir/FbExample.o.provides: CMakeFiles/fbExample.dir/FbExample.o.requires
	$(MAKE) -f CMakeFiles/fbExample.dir/build.make CMakeFiles/fbExample.dir/FbExample.o.provides.build
.PHONY : CMakeFiles/fbExample.dir/FbExample.o.provides

CMakeFiles/fbExample.dir/FbExample.o.provides.build: CMakeFiles/fbExample.dir/FbExample.o


# Object files for target fbExample
fbExample_OBJECTS = \
"CMakeFiles/fbExample.dir/FbExample.o"

# External object files for target fbExample
fbExample_EXTERNAL_OBJECTS =

fbExample: CMakeFiles/fbExample.dir/FbExample.o
fbExample: CMakeFiles/fbExample.dir/build.make
fbExample: CMakeFiles/fbExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Prachi/Documents/kunal_wrk/fbPerformance/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable fbExample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fbExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fbExample.dir/build: fbExample

.PHONY : CMakeFiles/fbExample.dir/build

CMakeFiles/fbExample.dir/requires: CMakeFiles/fbExample.dir/FbExample.o.requires

.PHONY : CMakeFiles/fbExample.dir/requires

CMakeFiles/fbExample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fbExample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fbExample.dir/clean

CMakeFiles/fbExample.dir/depend:
	cd /Users/Prachi/Documents/kunal_wrk/fbPerformance && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Prachi/Documents/kunal_wrk/fbPerformance /Users/Prachi/Documents/kunal_wrk/fbPerformance /Users/Prachi/Documents/kunal_wrk/fbPerformance /Users/Prachi/Documents/kunal_wrk/fbPerformance /Users/Prachi/Documents/kunal_wrk/fbPerformance/CMakeFiles/fbExample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fbExample.dir/depend
