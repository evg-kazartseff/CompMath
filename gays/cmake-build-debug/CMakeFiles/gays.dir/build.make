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
CMAKE_SOURCE_DIR = /home/evgenii/git/CompMath/gays

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/evgenii/git/CompMath/gays/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gays.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gays.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gays.dir/flags.make

CMakeFiles/gays.dir/main.cpp.o: CMakeFiles/gays.dir/flags.make
CMakeFiles/gays.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/evgenii/git/CompMath/gays/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gays.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gays.dir/main.cpp.o -c /home/evgenii/git/CompMath/gays/main.cpp

CMakeFiles/gays.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gays.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/evgenii/git/CompMath/gays/main.cpp > CMakeFiles/gays.dir/main.cpp.i

CMakeFiles/gays.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gays.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/evgenii/git/CompMath/gays/main.cpp -o CMakeFiles/gays.dir/main.cpp.s

CMakeFiles/gays.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/gays.dir/main.cpp.o.requires

CMakeFiles/gays.dir/main.cpp.o.provides: CMakeFiles/gays.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/gays.dir/build.make CMakeFiles/gays.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/gays.dir/main.cpp.o.provides

CMakeFiles/gays.dir/main.cpp.o.provides.build: CMakeFiles/gays.dir/main.cpp.o


# Object files for target gays
gays_OBJECTS = \
"CMakeFiles/gays.dir/main.cpp.o"

# External object files for target gays
gays_EXTERNAL_OBJECTS =

gays: CMakeFiles/gays.dir/main.cpp.o
gays: CMakeFiles/gays.dir/build.make
gays: CMakeFiles/gays.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/evgenii/git/CompMath/gays/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable gays"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gays.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gays.dir/build: gays

.PHONY : CMakeFiles/gays.dir/build

CMakeFiles/gays.dir/requires: CMakeFiles/gays.dir/main.cpp.o.requires

.PHONY : CMakeFiles/gays.dir/requires

CMakeFiles/gays.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gays.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gays.dir/clean

CMakeFiles/gays.dir/depend:
	cd /home/evgenii/git/CompMath/gays/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/evgenii/git/CompMath/gays /home/evgenii/git/CompMath/gays /home/evgenii/git/CompMath/gays/cmake-build-debug /home/evgenii/git/CompMath/gays/cmake-build-debug /home/evgenii/git/CompMath/gays/cmake-build-debug/CMakeFiles/gays.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gays.dir/depend

