# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wstt/working/oop/1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wstt/working/oop/1/build

# Include any dependencies generated for this target.
include task/CMakeFiles/task.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include task/CMakeFiles/task.dir/compiler_depend.make

# Include the progress variables for this target.
include task/CMakeFiles/task.dir/progress.make

# Include the compile flags for this target's objects.
include task/CMakeFiles/task.dir/flags.make

task/CMakeFiles/task.dir/from_yaml.cpp.o: task/CMakeFiles/task.dir/flags.make
task/CMakeFiles/task.dir/from_yaml.cpp.o: ../task/from_yaml.cpp
task/CMakeFiles/task.dir/from_yaml.cpp.o: task/CMakeFiles/task.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstt/working/oop/1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object task/CMakeFiles/task.dir/from_yaml.cpp.o"
	cd /home/wstt/working/oop/1/build/task && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT task/CMakeFiles/task.dir/from_yaml.cpp.o -MF CMakeFiles/task.dir/from_yaml.cpp.o.d -o CMakeFiles/task.dir/from_yaml.cpp.o -c /home/wstt/working/oop/1/task/from_yaml.cpp

task/CMakeFiles/task.dir/from_yaml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task.dir/from_yaml.cpp.i"
	cd /home/wstt/working/oop/1/build/task && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wstt/working/oop/1/task/from_yaml.cpp > CMakeFiles/task.dir/from_yaml.cpp.i

task/CMakeFiles/task.dir/from_yaml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task.dir/from_yaml.cpp.s"
	cd /home/wstt/working/oop/1/build/task && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wstt/working/oop/1/task/from_yaml.cpp -o CMakeFiles/task.dir/from_yaml.cpp.s

task/CMakeFiles/task.dir/to_yaml.cpp.o: task/CMakeFiles/task.dir/flags.make
task/CMakeFiles/task.dir/to_yaml.cpp.o: ../task/to_yaml.cpp
task/CMakeFiles/task.dir/to_yaml.cpp.o: task/CMakeFiles/task.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wstt/working/oop/1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object task/CMakeFiles/task.dir/to_yaml.cpp.o"
	cd /home/wstt/working/oop/1/build/task && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT task/CMakeFiles/task.dir/to_yaml.cpp.o -MF CMakeFiles/task.dir/to_yaml.cpp.o.d -o CMakeFiles/task.dir/to_yaml.cpp.o -c /home/wstt/working/oop/1/task/to_yaml.cpp

task/CMakeFiles/task.dir/to_yaml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/task.dir/to_yaml.cpp.i"
	cd /home/wstt/working/oop/1/build/task && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wstt/working/oop/1/task/to_yaml.cpp > CMakeFiles/task.dir/to_yaml.cpp.i

task/CMakeFiles/task.dir/to_yaml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/task.dir/to_yaml.cpp.s"
	cd /home/wstt/working/oop/1/build/task && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wstt/working/oop/1/task/to_yaml.cpp -o CMakeFiles/task.dir/to_yaml.cpp.s

# Object files for target task
task_OBJECTS = \
"CMakeFiles/task.dir/from_yaml.cpp.o" \
"CMakeFiles/task.dir/to_yaml.cpp.o"

# External object files for target task
task_EXTERNAL_OBJECTS =

task/libtask.a: task/CMakeFiles/task.dir/from_yaml.cpp.o
task/libtask.a: task/CMakeFiles/task.dir/to_yaml.cpp.o
task/libtask.a: task/CMakeFiles/task.dir/build.make
task/libtask.a: task/CMakeFiles/task.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wstt/working/oop/1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libtask.a"
	cd /home/wstt/working/oop/1/build/task && $(CMAKE_COMMAND) -P CMakeFiles/task.dir/cmake_clean_target.cmake
	cd /home/wstt/working/oop/1/build/task && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/task.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
task/CMakeFiles/task.dir/build: task/libtask.a
.PHONY : task/CMakeFiles/task.dir/build

task/CMakeFiles/task.dir/clean:
	cd /home/wstt/working/oop/1/build/task && $(CMAKE_COMMAND) -P CMakeFiles/task.dir/cmake_clean.cmake
.PHONY : task/CMakeFiles/task.dir/clean

task/CMakeFiles/task.dir/depend:
	cd /home/wstt/working/oop/1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wstt/working/oop/1 /home/wstt/working/oop/1/task /home/wstt/working/oop/1/build /home/wstt/working/oop/1/build/task /home/wstt/working/oop/1/build/task/CMakeFiles/task.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : task/CMakeFiles/task.dir/depend

