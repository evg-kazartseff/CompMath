# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/evgenii/app/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/evgenii/app/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/evgenii/git/CompMath/simple_iterations

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evgenii/git/CompMath/simple_iterations/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/simple_iterations.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simple_iterations.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simple_iterations.dir/flags.make

CMakeFiles/simple_iterations.dir/main.cpp.o: CMakeFiles/simple_iterations.dir/flags.make
CMakeFiles/simple_iterations.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/evgenii/git/CompMath/simple_iterations/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simple_iterations.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simple_iterations.dir/main.cpp.o -c /home/evgenii/git/CompMath/simple_iterations/main.cpp

CMakeFiles/simple_iterations.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simple_iterations.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evgenii/git/CompMath/simple_iterations/main.cpp > CMakeFiles/simple_iterations.dir/main.cpp.i

CMakeFiles/simple_iterations.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simple_iterations.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evgenii/git/CompMath/simple_iterations/main.cpp -o CMakeFiles/simple_iterations.dir/main.cpp.s

CMakeFiles/simple_iterations.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/simple_iterations.dir/main.cpp.o.requires

CMakeFiles/simple_iterations.dir/main.cpp.o.provides: CMakeFiles/simple_iterations.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/simple_iterations.dir/build.make CMakeFiles/simple_iterations.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/simple_iterations.dir/main.cpp.o.provides

CMakeFiles/simple_iterations.dir/main.cpp.o.provides.build: CMakeFiles/simple_iterations.dir/main.cpp.o


# Object files for target simple_iterations
simple_iterations_OBJECTS = \
"CMakeFiles/simple_iterations.dir/main.cpp.o"

# External object files for target simple_iterations
simple_iterations_EXTERNAL_OBJECTS =

simple_iterations: CMakeFiles/simple_iterations.dir/main.cpp.o
simple_iterations: CMakeFiles/simple_iterations.dir/build.make
simple_iterations: CMakeFiles/simple_iterations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/evgenii/git/CompMath/simple_iterations/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simple_iterations"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simple_iterations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simple_iterations.dir/build: simple_iterations

.PHONY : CMakeFiles/simple_iterations.dir/build

CMakeFiles/simple_iterations.dir/requires: CMakeFiles/simple_iterations.dir/main.cpp.o.requires

.PHONY : CMakeFiles/simple_iterations.dir/requires

CMakeFiles/simple_iterations.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simple_iterations.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simple_iterations.dir/clean

CMakeFiles/simple_iterations.dir/depend:
	cd /home/evgenii/git/CompMath/simple_iterations/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evgenii/git/CompMath/simple_iterations /home/evgenii/git/CompMath/simple_iterations /home/evgenii/git/CompMath/simple_iterations/cmake-build-debug /home/evgenii/git/CompMath/simple_iterations/cmake-build-debug /home/evgenii/git/CompMath/simple_iterations/cmake-build-debug/CMakeFiles/simple_iterations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simple_iterations.dir/depend

