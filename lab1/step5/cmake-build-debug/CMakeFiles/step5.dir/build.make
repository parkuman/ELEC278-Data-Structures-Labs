# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Programming\CLion\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Programming\CLion\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/step5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/step5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/step5.dir/flags.make

CMakeFiles/step5.dir/main.c.obj: CMakeFiles/step5.dir/flags.make
CMakeFiles/step5.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/step5.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\step5.dir\main.c.obj   -c "C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5\main.c"

CMakeFiles/step5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/step5.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5\main.c" > CMakeFiles\step5.dir\main.c.i

CMakeFiles/step5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/step5.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5\main.c" -o CMakeFiles\step5.dir\main.c.s

# Object files for target step5
step5_OBJECTS = \
"CMakeFiles/step5.dir/main.c.obj"

# External object files for target step5
step5_EXTERNAL_OBJECTS =

step5.exe: CMakeFiles/step5.dir/main.c.obj
step5.exe: CMakeFiles/step5.dir/build.make
step5.exe: CMakeFiles/step5.dir/linklibs.rsp
step5.exe: CMakeFiles/step5.dir/objects1.rsp
step5.exe: CMakeFiles/step5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable step5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\step5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/step5.dir/build: step5.exe

.PHONY : CMakeFiles/step5.dir/build

CMakeFiles/step5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\step5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/step5.dir/clean

CMakeFiles/step5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5" "C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5" "C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5\cmake-build-debug" "C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5\cmake-build-debug" "C:\Users\Parker\Documents\Queens\! Year 2\ELEC 278\lab1\step5\cmake-build-debug\CMakeFiles\step5.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/step5.dir/depend
