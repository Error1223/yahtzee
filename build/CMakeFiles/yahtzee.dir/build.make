# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/build

# Include any dependencies generated for this target.
include CMakeFiles/yahtzee.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/yahtzee.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/yahtzee.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/yahtzee.dir/flags.make

CMakeFiles/yahtzee.dir/main.cpp.o: CMakeFiles/yahtzee.dir/flags.make
CMakeFiles/yahtzee.dir/main.cpp.o: /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/main.cpp
CMakeFiles/yahtzee.dir/main.cpp.o: CMakeFiles/yahtzee.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/yahtzee.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/yahtzee.dir/main.cpp.o -MF CMakeFiles/yahtzee.dir/main.cpp.o.d -o CMakeFiles/yahtzee.dir/main.cpp.o -c /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/main.cpp

CMakeFiles/yahtzee.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/yahtzee.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/main.cpp > CMakeFiles/yahtzee.dir/main.cpp.i

CMakeFiles/yahtzee.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/yahtzee.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/main.cpp -o CMakeFiles/yahtzee.dir/main.cpp.s

# Object files for target yahtzee
yahtzee_OBJECTS = \
"CMakeFiles/yahtzee.dir/main.cpp.o"

# External object files for target yahtzee
yahtzee_EXTERNAL_OBJECTS =

yahtzee: CMakeFiles/yahtzee.dir/main.cpp.o
yahtzee: CMakeFiles/yahtzee.dir/build.make
yahtzee: CMakeFiles/yahtzee.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable yahtzee"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/yahtzee.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/yahtzee.dir/build: yahtzee
.PHONY : CMakeFiles/yahtzee.dir/build

CMakeFiles/yahtzee.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/yahtzee.dir/cmake_clean.cmake
.PHONY : CMakeFiles/yahtzee.dir/clean

CMakeFiles/yahtzee.dir/depend:
	cd /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/build /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/build /Users/hyunsulim/Documents/Software/Programming/C++/Yahtzee/build/CMakeFiles/yahtzee.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/yahtzee.dir/depend

