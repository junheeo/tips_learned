# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.29.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.29.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/out/build

# Include any dependencies generated for this target.
include CMakeFiles/OURPROJECT.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OURPROJECT.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OURPROJECT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OURPROJECT.dir/flags.make

CMakeFiles/OURPROJECT.dir/main.cpp.o: CMakeFiles/OURPROJECT.dir/flags.make
CMakeFiles/OURPROJECT.dir/main.cpp.o: /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/main.cpp
CMakeFiles/OURPROJECT.dir/main.cpp.o: CMakeFiles/OURPROJECT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OURPROJECT.dir/main.cpp.o"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OURPROJECT.dir/main.cpp.o -MF CMakeFiles/OURPROJECT.dir/main.cpp.o.d -o CMakeFiles/OURPROJECT.dir/main.cpp.o -c /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/main.cpp

CMakeFiles/OURPROJECT.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OURPROJECT.dir/main.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/main.cpp > CMakeFiles/OURPROJECT.dir/main.cpp.i

CMakeFiles/OURPROJECT.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OURPROJECT.dir/main.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/main.cpp -o CMakeFiles/OURPROJECT.dir/main.cpp.s

CMakeFiles/OURPROJECT.dir/a.cpp.o: CMakeFiles/OURPROJECT.dir/flags.make
CMakeFiles/OURPROJECT.dir/a.cpp.o: /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/a.cpp
CMakeFiles/OURPROJECT.dir/a.cpp.o: CMakeFiles/OURPROJECT.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OURPROJECT.dir/a.cpp.o"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OURPROJECT.dir/a.cpp.o -MF CMakeFiles/OURPROJECT.dir/a.cpp.o.d -o CMakeFiles/OURPROJECT.dir/a.cpp.o -c /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/a.cpp

CMakeFiles/OURPROJECT.dir/a.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/OURPROJECT.dir/a.cpp.i"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/a.cpp > CMakeFiles/OURPROJECT.dir/a.cpp.i

CMakeFiles/OURPROJECT.dir/a.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/OURPROJECT.dir/a.cpp.s"
	/usr/local/opt/llvm/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/a.cpp -o CMakeFiles/OURPROJECT.dir/a.cpp.s

# Object files for target OURPROJECT
OURPROJECT_OBJECTS = \
"CMakeFiles/OURPROJECT.dir/main.cpp.o" \
"CMakeFiles/OURPROJECT.dir/a.cpp.o"

# External object files for target OURPROJECT
OURPROJECT_EXTERNAL_OBJECTS =

OURPROJECT: CMakeFiles/OURPROJECT.dir/main.cpp.o
OURPROJECT: CMakeFiles/OURPROJECT.dir/a.cpp.o
OURPROJECT: CMakeFiles/OURPROJECT.dir/build.make
OURPROJECT: Lv1b/libB_LIBRARY.a
OURPROJECT: Lv1c/Lv2c/libC_LIBRARY.a
OURPROJECT: CMakeFiles/OURPROJECT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OURPROJECT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OURPROJECT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OURPROJECT.dir/build: OURPROJECT
.PHONY : CMakeFiles/OURPROJECT.dir/build

CMakeFiles/OURPROJECT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OURPROJECT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OURPROJECT.dir/clean

CMakeFiles/OURPROJECT.dir/depend:
	cd /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/out/build /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/out/build /Users/junheeoh/Code/cpp_tutorial/TestCmakeDir/out/build/CMakeFiles/OURPROJECT.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/OURPROJECT.dir/depend

