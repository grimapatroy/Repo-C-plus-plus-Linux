# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/cmake/bin/cmake

# The command to remove a file.
RM = /opt/cmake/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2/build"

# Include any dependencies generated for this target.
include CMakeFiles/proyectoAPI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/proyectoAPI.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/proyectoAPI.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proyectoAPI.dir/flags.make

CMakeFiles/proyectoAPI.dir/src/main.cpp.o: CMakeFiles/proyectoAPI.dir/flags.make
CMakeFiles/proyectoAPI.dir/src/main.cpp.o: /home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD\ 2/src/main.cpp
CMakeFiles/proyectoAPI.dir/src/main.cpp.o: CMakeFiles/proyectoAPI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proyectoAPI.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/proyectoAPI.dir/src/main.cpp.o -MF CMakeFiles/proyectoAPI.dir/src/main.cpp.o.d -o CMakeFiles/proyectoAPI.dir/src/main.cpp.o -c "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2/src/main.cpp"

CMakeFiles/proyectoAPI.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proyectoAPI.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2/src/main.cpp" > CMakeFiles/proyectoAPI.dir/src/main.cpp.i

CMakeFiles/proyectoAPI.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proyectoAPI.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2/src/main.cpp" -o CMakeFiles/proyectoAPI.dir/src/main.cpp.s

# Object files for target proyectoAPI
proyectoAPI_OBJECTS = \
"CMakeFiles/proyectoAPI.dir/src/main.cpp.o"

# External object files for target proyectoAPI
proyectoAPI_EXTERNAL_OBJECTS =

proyectoAPI: CMakeFiles/proyectoAPI.dir/src/main.cpp.o
proyectoAPI: CMakeFiles/proyectoAPI.dir/build.make
proyectoAPI: CMakeFiles/proyectoAPI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proyectoAPI"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proyectoAPI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proyectoAPI.dir/build: proyectoAPI
.PHONY : CMakeFiles/proyectoAPI.dir/build

CMakeFiles/proyectoAPI.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proyectoAPI.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proyectoAPI.dir/clean

CMakeFiles/proyectoAPI.dir/depend:
	cd "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2" "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2" "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2/build" "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2/build" "/home/jguivar/Documentos/LAFP2022/Repo_Cplusplus_Linux/ZPROBLEMAS/PROBL1CONTAD 2/build/CMakeFiles/proyectoAPI.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/proyectoAPI.dir/depend
