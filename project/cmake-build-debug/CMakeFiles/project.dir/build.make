# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/brentvw/Projects/ugent/da3/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brentvw/Projects/ugent/da3/project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project.dir/flags.make

CMakeFiles/project.dir/main.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/project.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/main.c.o   -c /Users/brentvw/Projects/ugent/da3/project/main.c

CMakeFiles/project.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/main.c > CMakeFiles/project.dir/main.c.i

CMakeFiles/project.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/main.c -o CMakeFiles/project.dir/main.c.s

CMakeFiles/project.dir/main.c.o.requires:

.PHONY : CMakeFiles/project.dir/main.c.o.requires

CMakeFiles/project.dir/main.c.o.provides: CMakeFiles/project.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/main.c.o.provides.build
.PHONY : CMakeFiles/project.dir/main.c.o.provides

CMakeFiles/project.dir/main.c.o.provides.build: CMakeFiles/project.dir/main.c.o


CMakeFiles/project.dir/huffman/huffman.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/huffman/huffman.c.o: ../huffman/huffman.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/project.dir/huffman/huffman.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/huffman/huffman.c.o   -c /Users/brentvw/Projects/ugent/da3/project/huffman/huffman.c

CMakeFiles/project.dir/huffman/huffman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/huffman/huffman.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/huffman/huffman.c > CMakeFiles/project.dir/huffman/huffman.c.i

CMakeFiles/project.dir/huffman/huffman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/huffman/huffman.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/huffman/huffman.c -o CMakeFiles/project.dir/huffman/huffman.c.s

CMakeFiles/project.dir/huffman/huffman.c.o.requires:

.PHONY : CMakeFiles/project.dir/huffman/huffman.c.o.requires

CMakeFiles/project.dir/huffman/huffman.c.o.provides: CMakeFiles/project.dir/huffman/huffman.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/huffman/huffman.c.o.provides.build
.PHONY : CMakeFiles/project.dir/huffman/huffman.c.o.provides

CMakeFiles/project.dir/huffman/huffman.c.o.provides.build: CMakeFiles/project.dir/huffman/huffman.c.o


CMakeFiles/project.dir/datastructures/input.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/datastructures/input.c.o: ../datastructures/input.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/project.dir/datastructures/input.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/datastructures/input.c.o   -c /Users/brentvw/Projects/ugent/da3/project/datastructures/input.c

CMakeFiles/project.dir/datastructures/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/datastructures/input.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/datastructures/input.c > CMakeFiles/project.dir/datastructures/input.c.i

CMakeFiles/project.dir/datastructures/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/datastructures/input.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/datastructures/input.c -o CMakeFiles/project.dir/datastructures/input.c.s

CMakeFiles/project.dir/datastructures/input.c.o.requires:

.PHONY : CMakeFiles/project.dir/datastructures/input.c.o.requires

CMakeFiles/project.dir/datastructures/input.c.o.provides: CMakeFiles/project.dir/datastructures/input.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/datastructures/input.c.o.provides.build
.PHONY : CMakeFiles/project.dir/datastructures/input.c.o.provides

CMakeFiles/project.dir/datastructures/input.c.o.provides.build: CMakeFiles/project.dir/datastructures/input.c.o


CMakeFiles/project.dir/datastructures/stack.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/datastructures/stack.c.o: ../datastructures/stack.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/project.dir/datastructures/stack.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/datastructures/stack.c.o   -c /Users/brentvw/Projects/ugent/da3/project/datastructures/stack.c

CMakeFiles/project.dir/datastructures/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/datastructures/stack.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/datastructures/stack.c > CMakeFiles/project.dir/datastructures/stack.c.i

CMakeFiles/project.dir/datastructures/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/datastructures/stack.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/datastructures/stack.c -o CMakeFiles/project.dir/datastructures/stack.c.s

CMakeFiles/project.dir/datastructures/stack.c.o.requires:

.PHONY : CMakeFiles/project.dir/datastructures/stack.c.o.requires

CMakeFiles/project.dir/datastructures/stack.c.o.provides: CMakeFiles/project.dir/datastructures/stack.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/datastructures/stack.c.o.provides.build
.PHONY : CMakeFiles/project.dir/datastructures/stack.c.o.provides

CMakeFiles/project.dir/datastructures/stack.c.o.provides.build: CMakeFiles/project.dir/datastructures/stack.c.o


CMakeFiles/project.dir/adaptive/adaptive.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/adaptive/adaptive.c.o: ../adaptive/adaptive.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/project.dir/adaptive/adaptive.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/adaptive/adaptive.c.o   -c /Users/brentvw/Projects/ugent/da3/project/adaptive/adaptive.c

CMakeFiles/project.dir/adaptive/adaptive.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/adaptive/adaptive.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/adaptive/adaptive.c > CMakeFiles/project.dir/adaptive/adaptive.c.i

CMakeFiles/project.dir/adaptive/adaptive.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/adaptive/adaptive.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/adaptive/adaptive.c -o CMakeFiles/project.dir/adaptive/adaptive.c.s

CMakeFiles/project.dir/adaptive/adaptive.c.o.requires:

.PHONY : CMakeFiles/project.dir/adaptive/adaptive.c.o.requires

CMakeFiles/project.dir/adaptive/adaptive.c.o.provides: CMakeFiles/project.dir/adaptive/adaptive.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/adaptive/adaptive.c.o.provides.build
.PHONY : CMakeFiles/project.dir/adaptive/adaptive.c.o.provides

CMakeFiles/project.dir/adaptive/adaptive.c.o.provides.build: CMakeFiles/project.dir/adaptive/adaptive.c.o


CMakeFiles/project.dir/datastructures/huff_node.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/datastructures/huff_node.c.o: ../datastructures/huff_node.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/project.dir/datastructures/huff_node.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/datastructures/huff_node.c.o   -c /Users/brentvw/Projects/ugent/da3/project/datastructures/huff_node.c

CMakeFiles/project.dir/datastructures/huff_node.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/datastructures/huff_node.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/datastructures/huff_node.c > CMakeFiles/project.dir/datastructures/huff_node.c.i

CMakeFiles/project.dir/datastructures/huff_node.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/datastructures/huff_node.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/datastructures/huff_node.c -o CMakeFiles/project.dir/datastructures/huff_node.c.s

CMakeFiles/project.dir/datastructures/huff_node.c.o.requires:

.PHONY : CMakeFiles/project.dir/datastructures/huff_node.c.o.requires

CMakeFiles/project.dir/datastructures/huff_node.c.o.provides: CMakeFiles/project.dir/datastructures/huff_node.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/datastructures/huff_node.c.o.provides.build
.PHONY : CMakeFiles/project.dir/datastructures/huff_node.c.o.provides

CMakeFiles/project.dir/datastructures/huff_node.c.o.provides.build: CMakeFiles/project.dir/datastructures/huff_node.c.o


CMakeFiles/project.dir/datastructures/order_list.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/datastructures/order_list.c.o: ../datastructures/order_list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/project.dir/datastructures/order_list.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/datastructures/order_list.c.o   -c /Users/brentvw/Projects/ugent/da3/project/datastructures/order_list.c

CMakeFiles/project.dir/datastructures/order_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/datastructures/order_list.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/datastructures/order_list.c > CMakeFiles/project.dir/datastructures/order_list.c.i

CMakeFiles/project.dir/datastructures/order_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/datastructures/order_list.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/datastructures/order_list.c -o CMakeFiles/project.dir/datastructures/order_list.c.s

CMakeFiles/project.dir/datastructures/order_list.c.o.requires:

.PHONY : CMakeFiles/project.dir/datastructures/order_list.c.o.requires

CMakeFiles/project.dir/datastructures/order_list.c.o.provides: CMakeFiles/project.dir/datastructures/order_list.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/datastructures/order_list.c.o.provides.build
.PHONY : CMakeFiles/project.dir/datastructures/order_list.c.o.provides

CMakeFiles/project.dir/datastructures/order_list.c.o.provides.build: CMakeFiles/project.dir/datastructures/order_list.c.o


CMakeFiles/project.dir/sliding/sliding.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/sliding/sliding.c.o: ../sliding/sliding.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/project.dir/sliding/sliding.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/sliding/sliding.c.o   -c /Users/brentvw/Projects/ugent/da3/project/sliding/sliding.c

CMakeFiles/project.dir/sliding/sliding.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/sliding/sliding.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/sliding/sliding.c > CMakeFiles/project.dir/sliding/sliding.c.i

CMakeFiles/project.dir/sliding/sliding.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/sliding/sliding.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/sliding/sliding.c -o CMakeFiles/project.dir/sliding/sliding.c.s

CMakeFiles/project.dir/sliding/sliding.c.o.requires:

.PHONY : CMakeFiles/project.dir/sliding/sliding.c.o.requires

CMakeFiles/project.dir/sliding/sliding.c.o.provides: CMakeFiles/project.dir/sliding/sliding.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/sliding/sliding.c.o.provides.build
.PHONY : CMakeFiles/project.dir/sliding/sliding.c.o.provides

CMakeFiles/project.dir/sliding/sliding.c.o.provides.build: CMakeFiles/project.dir/sliding/sliding.c.o


CMakeFiles/project.dir/adaptive/encode.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/adaptive/encode.c.o: ../adaptive/encode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/project.dir/adaptive/encode.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/adaptive/encode.c.o   -c /Users/brentvw/Projects/ugent/da3/project/adaptive/encode.c

CMakeFiles/project.dir/adaptive/encode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/adaptive/encode.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/adaptive/encode.c > CMakeFiles/project.dir/adaptive/encode.c.i

CMakeFiles/project.dir/adaptive/encode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/adaptive/encode.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/adaptive/encode.c -o CMakeFiles/project.dir/adaptive/encode.c.s

CMakeFiles/project.dir/adaptive/encode.c.o.requires:

.PHONY : CMakeFiles/project.dir/adaptive/encode.c.o.requires

CMakeFiles/project.dir/adaptive/encode.c.o.provides: CMakeFiles/project.dir/adaptive/encode.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/adaptive/encode.c.o.provides.build
.PHONY : CMakeFiles/project.dir/adaptive/encode.c.o.provides

CMakeFiles/project.dir/adaptive/encode.c.o.provides.build: CMakeFiles/project.dir/adaptive/encode.c.o


CMakeFiles/project.dir/adaptive/decode.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/adaptive/decode.c.o: ../adaptive/decode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/project.dir/adaptive/decode.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/adaptive/decode.c.o   -c /Users/brentvw/Projects/ugent/da3/project/adaptive/decode.c

CMakeFiles/project.dir/adaptive/decode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/adaptive/decode.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/adaptive/decode.c > CMakeFiles/project.dir/adaptive/decode.c.i

CMakeFiles/project.dir/adaptive/decode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/adaptive/decode.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/adaptive/decode.c -o CMakeFiles/project.dir/adaptive/decode.c.s

CMakeFiles/project.dir/adaptive/decode.c.o.requires:

.PHONY : CMakeFiles/project.dir/adaptive/decode.c.o.requires

CMakeFiles/project.dir/adaptive/decode.c.o.provides: CMakeFiles/project.dir/adaptive/decode.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/adaptive/decode.c.o.provides.build
.PHONY : CMakeFiles/project.dir/adaptive/decode.c.o.provides

CMakeFiles/project.dir/adaptive/decode.c.o.provides.build: CMakeFiles/project.dir/adaptive/decode.c.o


CMakeFiles/project.dir/sliding/encode.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/sliding/encode.c.o: ../sliding/encode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/project.dir/sliding/encode.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/sliding/encode.c.o   -c /Users/brentvw/Projects/ugent/da3/project/sliding/encode.c

CMakeFiles/project.dir/sliding/encode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/sliding/encode.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/sliding/encode.c > CMakeFiles/project.dir/sliding/encode.c.i

CMakeFiles/project.dir/sliding/encode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/sliding/encode.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/sliding/encode.c -o CMakeFiles/project.dir/sliding/encode.c.s

CMakeFiles/project.dir/sliding/encode.c.o.requires:

.PHONY : CMakeFiles/project.dir/sliding/encode.c.o.requires

CMakeFiles/project.dir/sliding/encode.c.o.provides: CMakeFiles/project.dir/sliding/encode.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/sliding/encode.c.o.provides.build
.PHONY : CMakeFiles/project.dir/sliding/encode.c.o.provides

CMakeFiles/project.dir/sliding/encode.c.o.provides.build: CMakeFiles/project.dir/sliding/encode.c.o


CMakeFiles/project.dir/sliding/decode.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/sliding/decode.c.o: ../sliding/decode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/project.dir/sliding/decode.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/sliding/decode.c.o   -c /Users/brentvw/Projects/ugent/da3/project/sliding/decode.c

CMakeFiles/project.dir/sliding/decode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/sliding/decode.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/sliding/decode.c > CMakeFiles/project.dir/sliding/decode.c.i

CMakeFiles/project.dir/sliding/decode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/sliding/decode.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/sliding/decode.c -o CMakeFiles/project.dir/sliding/decode.c.s

CMakeFiles/project.dir/sliding/decode.c.o.requires:

.PHONY : CMakeFiles/project.dir/sliding/decode.c.o.requires

CMakeFiles/project.dir/sliding/decode.c.o.provides: CMakeFiles/project.dir/sliding/decode.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/sliding/decode.c.o.provides.build
.PHONY : CMakeFiles/project.dir/sliding/decode.c.o.provides

CMakeFiles/project.dir/sliding/decode.c.o.provides.build: CMakeFiles/project.dir/sliding/decode.c.o


CMakeFiles/project.dir/twopass/twopass.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/twopass/twopass.c.o: ../twopass/twopass.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/project.dir/twopass/twopass.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/twopass/twopass.c.o   -c /Users/brentvw/Projects/ugent/da3/project/twopass/twopass.c

CMakeFiles/project.dir/twopass/twopass.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/twopass/twopass.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/twopass/twopass.c > CMakeFiles/project.dir/twopass/twopass.c.i

CMakeFiles/project.dir/twopass/twopass.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/twopass/twopass.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/twopass/twopass.c -o CMakeFiles/project.dir/twopass/twopass.c.s

CMakeFiles/project.dir/twopass/twopass.c.o.requires:

.PHONY : CMakeFiles/project.dir/twopass/twopass.c.o.requires

CMakeFiles/project.dir/twopass/twopass.c.o.provides: CMakeFiles/project.dir/twopass/twopass.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/twopass/twopass.c.o.provides.build
.PHONY : CMakeFiles/project.dir/twopass/twopass.c.o.provides

CMakeFiles/project.dir/twopass/twopass.c.o.provides.build: CMakeFiles/project.dir/twopass/twopass.c.o


CMakeFiles/project.dir/twopass/encode.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/twopass/encode.c.o: ../twopass/encode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/project.dir/twopass/encode.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/twopass/encode.c.o   -c /Users/brentvw/Projects/ugent/da3/project/twopass/encode.c

CMakeFiles/project.dir/twopass/encode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/twopass/encode.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/twopass/encode.c > CMakeFiles/project.dir/twopass/encode.c.i

CMakeFiles/project.dir/twopass/encode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/twopass/encode.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/twopass/encode.c -o CMakeFiles/project.dir/twopass/encode.c.s

CMakeFiles/project.dir/twopass/encode.c.o.requires:

.PHONY : CMakeFiles/project.dir/twopass/encode.c.o.requires

CMakeFiles/project.dir/twopass/encode.c.o.provides: CMakeFiles/project.dir/twopass/encode.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/twopass/encode.c.o.provides.build
.PHONY : CMakeFiles/project.dir/twopass/encode.c.o.provides

CMakeFiles/project.dir/twopass/encode.c.o.provides.build: CMakeFiles/project.dir/twopass/encode.c.o


CMakeFiles/project.dir/twopass/decode.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/twopass/decode.c.o: ../twopass/decode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/project.dir/twopass/decode.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/twopass/decode.c.o   -c /Users/brentvw/Projects/ugent/da3/project/twopass/decode.c

CMakeFiles/project.dir/twopass/decode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/twopass/decode.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/twopass/decode.c > CMakeFiles/project.dir/twopass/decode.c.i

CMakeFiles/project.dir/twopass/decode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/twopass/decode.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/twopass/decode.c -o CMakeFiles/project.dir/twopass/decode.c.s

CMakeFiles/project.dir/twopass/decode.c.o.requires:

.PHONY : CMakeFiles/project.dir/twopass/decode.c.o.requires

CMakeFiles/project.dir/twopass/decode.c.o.provides: CMakeFiles/project.dir/twopass/decode.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/twopass/decode.c.o.provides.build
.PHONY : CMakeFiles/project.dir/twopass/decode.c.o.provides

CMakeFiles/project.dir/twopass/decode.c.o.provides.build: CMakeFiles/project.dir/twopass/decode.c.o


CMakeFiles/project.dir/block/block.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/block/block.c.o: ../block/block.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/project.dir/block/block.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/block/block.c.o   -c /Users/brentvw/Projects/ugent/da3/project/block/block.c

CMakeFiles/project.dir/block/block.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/block/block.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/block/block.c > CMakeFiles/project.dir/block/block.c.i

CMakeFiles/project.dir/block/block.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/block/block.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/block/block.c -o CMakeFiles/project.dir/block/block.c.s

CMakeFiles/project.dir/block/block.c.o.requires:

.PHONY : CMakeFiles/project.dir/block/block.c.o.requires

CMakeFiles/project.dir/block/block.c.o.provides: CMakeFiles/project.dir/block/block.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/block/block.c.o.provides.build
.PHONY : CMakeFiles/project.dir/block/block.c.o.provides

CMakeFiles/project.dir/block/block.c.o.provides.build: CMakeFiles/project.dir/block/block.c.o


CMakeFiles/project.dir/block/encode.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/block/encode.c.o: ../block/encode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/project.dir/block/encode.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/block/encode.c.o   -c /Users/brentvw/Projects/ugent/da3/project/block/encode.c

CMakeFiles/project.dir/block/encode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/block/encode.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/block/encode.c > CMakeFiles/project.dir/block/encode.c.i

CMakeFiles/project.dir/block/encode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/block/encode.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/block/encode.c -o CMakeFiles/project.dir/block/encode.c.s

CMakeFiles/project.dir/block/encode.c.o.requires:

.PHONY : CMakeFiles/project.dir/block/encode.c.o.requires

CMakeFiles/project.dir/block/encode.c.o.provides: CMakeFiles/project.dir/block/encode.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/block/encode.c.o.provides.build
.PHONY : CMakeFiles/project.dir/block/encode.c.o.provides

CMakeFiles/project.dir/block/encode.c.o.provides.build: CMakeFiles/project.dir/block/encode.c.o


CMakeFiles/project.dir/block/decode.c.o: CMakeFiles/project.dir/flags.make
CMakeFiles/project.dir/block/decode.c.o: ../block/decode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building C object CMakeFiles/project.dir/block/decode.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/project.dir/block/decode.c.o   -c /Users/brentvw/Projects/ugent/da3/project/block/decode.c

CMakeFiles/project.dir/block/decode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/project.dir/block/decode.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/brentvw/Projects/ugent/da3/project/block/decode.c > CMakeFiles/project.dir/block/decode.c.i

CMakeFiles/project.dir/block/decode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/project.dir/block/decode.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/brentvw/Projects/ugent/da3/project/block/decode.c -o CMakeFiles/project.dir/block/decode.c.s

CMakeFiles/project.dir/block/decode.c.o.requires:

.PHONY : CMakeFiles/project.dir/block/decode.c.o.requires

CMakeFiles/project.dir/block/decode.c.o.provides: CMakeFiles/project.dir/block/decode.c.o.requires
	$(MAKE) -f CMakeFiles/project.dir/build.make CMakeFiles/project.dir/block/decode.c.o.provides.build
.PHONY : CMakeFiles/project.dir/block/decode.c.o.provides

CMakeFiles/project.dir/block/decode.c.o.provides.build: CMakeFiles/project.dir/block/decode.c.o


# Object files for target project
project_OBJECTS = \
"CMakeFiles/project.dir/main.c.o" \
"CMakeFiles/project.dir/huffman/huffman.c.o" \
"CMakeFiles/project.dir/datastructures/input.c.o" \
"CMakeFiles/project.dir/datastructures/stack.c.o" \
"CMakeFiles/project.dir/adaptive/adaptive.c.o" \
"CMakeFiles/project.dir/datastructures/huff_node.c.o" \
"CMakeFiles/project.dir/datastructures/order_list.c.o" \
"CMakeFiles/project.dir/sliding/sliding.c.o" \
"CMakeFiles/project.dir/adaptive/encode.c.o" \
"CMakeFiles/project.dir/adaptive/decode.c.o" \
"CMakeFiles/project.dir/sliding/encode.c.o" \
"CMakeFiles/project.dir/sliding/decode.c.o" \
"CMakeFiles/project.dir/twopass/twopass.c.o" \
"CMakeFiles/project.dir/twopass/encode.c.o" \
"CMakeFiles/project.dir/twopass/decode.c.o" \
"CMakeFiles/project.dir/block/block.c.o" \
"CMakeFiles/project.dir/block/encode.c.o" \
"CMakeFiles/project.dir/block/decode.c.o"

# External object files for target project
project_EXTERNAL_OBJECTS =

project: CMakeFiles/project.dir/main.c.o
project: CMakeFiles/project.dir/huffman/huffman.c.o
project: CMakeFiles/project.dir/datastructures/input.c.o
project: CMakeFiles/project.dir/datastructures/stack.c.o
project: CMakeFiles/project.dir/adaptive/adaptive.c.o
project: CMakeFiles/project.dir/datastructures/huff_node.c.o
project: CMakeFiles/project.dir/datastructures/order_list.c.o
project: CMakeFiles/project.dir/sliding/sliding.c.o
project: CMakeFiles/project.dir/adaptive/encode.c.o
project: CMakeFiles/project.dir/adaptive/decode.c.o
project: CMakeFiles/project.dir/sliding/encode.c.o
project: CMakeFiles/project.dir/sliding/decode.c.o
project: CMakeFiles/project.dir/twopass/twopass.c.o
project: CMakeFiles/project.dir/twopass/encode.c.o
project: CMakeFiles/project.dir/twopass/decode.c.o
project: CMakeFiles/project.dir/block/block.c.o
project: CMakeFiles/project.dir/block/encode.c.o
project: CMakeFiles/project.dir/block/decode.c.o
project: CMakeFiles/project.dir/build.make
project: CMakeFiles/project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking C executable project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project.dir/build: project

.PHONY : CMakeFiles/project.dir/build

CMakeFiles/project.dir/requires: CMakeFiles/project.dir/main.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/huffman/huffman.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/datastructures/input.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/datastructures/stack.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/adaptive/adaptive.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/datastructures/huff_node.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/datastructures/order_list.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/sliding/sliding.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/adaptive/encode.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/adaptive/decode.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/sliding/encode.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/sliding/decode.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/twopass/twopass.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/twopass/encode.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/twopass/decode.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/block/block.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/block/encode.c.o.requires
CMakeFiles/project.dir/requires: CMakeFiles/project.dir/block/decode.c.o.requires

.PHONY : CMakeFiles/project.dir/requires

CMakeFiles/project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project.dir/clean

CMakeFiles/project.dir/depend:
	cd /Users/brentvw/Projects/ugent/da3/project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brentvw/Projects/ugent/da3/project /Users/brentvw/Projects/ugent/da3/project /Users/brentvw/Projects/ugent/da3/project/cmake-build-debug /Users/brentvw/Projects/ugent/da3/project/cmake-build-debug /Users/brentvw/Projects/ugent/da3/project/cmake-build-debug/CMakeFiles/project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project.dir/depend

