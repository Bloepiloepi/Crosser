# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/arnedalhuisen/CLionProjects/Crosser

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/arnedalhuisen/CLionProjects/Crosser/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Crosser.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Crosser.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Crosser.dir/flags.make

CMakeFiles/Crosser.dir/main.cpp.o: CMakeFiles/Crosser.dir/flags.make
CMakeFiles/Crosser.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arnedalhuisen/CLionProjects/Crosser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Crosser.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Crosser.dir/main.cpp.o -c /Users/arnedalhuisen/CLionProjects/Crosser/main.cpp

CMakeFiles/Crosser.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Crosser.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arnedalhuisen/CLionProjects/Crosser/main.cpp > CMakeFiles/Crosser.dir/main.cpp.i

CMakeFiles/Crosser.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Crosser.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arnedalhuisen/CLionProjects/Crosser/main.cpp -o CMakeFiles/Crosser.dir/main.cpp.s

CMakeFiles/Crosser.dir/game.cpp.o: CMakeFiles/Crosser.dir/flags.make
CMakeFiles/Crosser.dir/game.cpp.o: ../game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arnedalhuisen/CLionProjects/Crosser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Crosser.dir/game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Crosser.dir/game.cpp.o -c /Users/arnedalhuisen/CLionProjects/Crosser/game.cpp

CMakeFiles/Crosser.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Crosser.dir/game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arnedalhuisen/CLionProjects/Crosser/game.cpp > CMakeFiles/Crosser.dir/game.cpp.i

CMakeFiles/Crosser.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Crosser.dir/game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arnedalhuisen/CLionProjects/Crosser/game.cpp -o CMakeFiles/Crosser.dir/game.cpp.s

CMakeFiles/Crosser.dir/utils.cpp.o: CMakeFiles/Crosser.dir/flags.make
CMakeFiles/Crosser.dir/utils.cpp.o: ../utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arnedalhuisen/CLionProjects/Crosser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Crosser.dir/utils.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Crosser.dir/utils.cpp.o -c /Users/arnedalhuisen/CLionProjects/Crosser/utils.cpp

CMakeFiles/Crosser.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Crosser.dir/utils.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arnedalhuisen/CLionProjects/Crosser/utils.cpp > CMakeFiles/Crosser.dir/utils.cpp.i

CMakeFiles/Crosser.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Crosser.dir/utils.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arnedalhuisen/CLionProjects/Crosser/utils.cpp -o CMakeFiles/Crosser.dir/utils.cpp.s

CMakeFiles/Crosser.dir/tile.cpp.o: CMakeFiles/Crosser.dir/flags.make
CMakeFiles/Crosser.dir/tile.cpp.o: ../tile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/arnedalhuisen/CLionProjects/Crosser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Crosser.dir/tile.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Crosser.dir/tile.cpp.o -c /Users/arnedalhuisen/CLionProjects/Crosser/tile.cpp

CMakeFiles/Crosser.dir/tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Crosser.dir/tile.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/arnedalhuisen/CLionProjects/Crosser/tile.cpp > CMakeFiles/Crosser.dir/tile.cpp.i

CMakeFiles/Crosser.dir/tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Crosser.dir/tile.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/arnedalhuisen/CLionProjects/Crosser/tile.cpp -o CMakeFiles/Crosser.dir/tile.cpp.s

# Object files for target Crosser
Crosser_OBJECTS = \
"CMakeFiles/Crosser.dir/main.cpp.o" \
"CMakeFiles/Crosser.dir/game.cpp.o" \
"CMakeFiles/Crosser.dir/utils.cpp.o" \
"CMakeFiles/Crosser.dir/tile.cpp.o"

# External object files for target Crosser
Crosser_EXTERNAL_OBJECTS =

Crosser: CMakeFiles/Crosser.dir/main.cpp.o
Crosser: CMakeFiles/Crosser.dir/game.cpp.o
Crosser: CMakeFiles/Crosser.dir/utils.cpp.o
Crosser: CMakeFiles/Crosser.dir/tile.cpp.o
Crosser: CMakeFiles/Crosser.dir/build.make
Crosser: /usr/local/lib/libsfml-graphics.2.5.1.dylib
Crosser: /usr/local/lib/libsfml-window.2.5.1.dylib
Crosser: /usr/local/lib/libsfml-system.2.5.1.dylib
Crosser: CMakeFiles/Crosser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/arnedalhuisen/CLionProjects/Crosser/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Crosser"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Crosser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Crosser.dir/build: Crosser

.PHONY : CMakeFiles/Crosser.dir/build

CMakeFiles/Crosser.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Crosser.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Crosser.dir/clean

CMakeFiles/Crosser.dir/depend:
	cd /Users/arnedalhuisen/CLionProjects/Crosser/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/arnedalhuisen/CLionProjects/Crosser /Users/arnedalhuisen/CLionProjects/Crosser /Users/arnedalhuisen/CLionProjects/Crosser/cmake-build-debug /Users/arnedalhuisen/CLionProjects/Crosser/cmake-build-debug /Users/arnedalhuisen/CLionProjects/Crosser/cmake-build-debug/CMakeFiles/Crosser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Crosser.dir/depend

