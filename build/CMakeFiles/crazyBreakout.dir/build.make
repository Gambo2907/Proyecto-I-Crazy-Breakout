# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/build

# Include any dependencies generated for this target.
include CMakeFiles/crazyBreakout.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/crazyBreakout.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/crazyBreakout.dir/flags.make

CMakeFiles/crazyBreakout.dir/Breakout.cpp.o: CMakeFiles/crazyBreakout.dir/flags.make
CMakeFiles/crazyBreakout.dir/Breakout.cpp.o: ../Breakout.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/crazyBreakout.dir/Breakout.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crazyBreakout.dir/Breakout.cpp.o -c /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/Breakout.cpp

CMakeFiles/crazyBreakout.dir/Breakout.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crazyBreakout.dir/Breakout.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/Breakout.cpp > CMakeFiles/crazyBreakout.dir/Breakout.cpp.i

CMakeFiles/crazyBreakout.dir/Breakout.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crazyBreakout.dir/Breakout.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/Breakout.cpp -o CMakeFiles/crazyBreakout.dir/Breakout.cpp.s

CMakeFiles/crazyBreakout.dir/main.cpp.o: CMakeFiles/crazyBreakout.dir/flags.make
CMakeFiles/crazyBreakout.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/crazyBreakout.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/crazyBreakout.dir/main.cpp.o -c /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/main.cpp

CMakeFiles/crazyBreakout.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/crazyBreakout.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/main.cpp > CMakeFiles/crazyBreakout.dir/main.cpp.i

CMakeFiles/crazyBreakout.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/crazyBreakout.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/main.cpp -o CMakeFiles/crazyBreakout.dir/main.cpp.s

# Object files for target crazyBreakout
crazyBreakout_OBJECTS = \
"CMakeFiles/crazyBreakout.dir/Breakout.cpp.o" \
"CMakeFiles/crazyBreakout.dir/main.cpp.o"

# External object files for target crazyBreakout
crazyBreakout_EXTERNAL_OBJECTS =

crazyBreakout: CMakeFiles/crazyBreakout.dir/Breakout.cpp.o
crazyBreakout: CMakeFiles/crazyBreakout.dir/main.cpp.o
crazyBreakout: CMakeFiles/crazyBreakout.dir/build.make
crazyBreakout: /usr/lib/x86_64-linux-gnu/libGL.so
crazyBreakout: /usr/lib/x86_64-linux-gnu/libGLU.so
crazyBreakout: /usr/lib/x86_64-linux-gnu/libglut.so
crazyBreakout: /usr/lib/x86_64-linux-gnu/libXmu.so
crazyBreakout: /usr/lib/x86_64-linux-gnu/libXi.so
crazyBreakout: CMakeFiles/crazyBreakout.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable crazyBreakout"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/crazyBreakout.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/crazyBreakout.dir/build: crazyBreakout

.PHONY : CMakeFiles/crazyBreakout.dir/build

CMakeFiles/crazyBreakout.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/crazyBreakout.dir/cmake_clean.cmake
.PHONY : CMakeFiles/crazyBreakout.dir/clean

CMakeFiles/crazyBreakout.dir/depend:
	cd /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/build /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/build /home/gustavo/Documentos/GitHub/Proyecto-I-Crazy-Breakout/build/CMakeFiles/crazyBreakout.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/crazyBreakout.dir/depend
