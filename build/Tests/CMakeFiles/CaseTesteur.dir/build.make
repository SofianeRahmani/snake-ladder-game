# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = "C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/temp/CodeTP1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/temp/CodeTP1/build

# Include any dependencies generated for this target.
include Tests/CMakeFiles/CaseTesteur.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Tests/CMakeFiles/CaseTesteur.dir/compiler_depend.make

# Include the progress variables for this target.
include Tests/CMakeFiles/CaseTesteur.dir/progress.make

# Include the compile flags for this target's objects.
include Tests/CMakeFiles/CaseTesteur.dir/flags.make

Tests/CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.obj: Tests/CMakeFiles/CaseTesteur.dir/flags.make
Tests/CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.obj: Tests/CMakeFiles/CaseTesteur.dir/includes_CXX.rsp
Tests/CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.obj: C:/temp/CodeTP1/Tests/CaseTesteur.cpp
Tests/CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.obj: Tests/CMakeFiles/CaseTesteur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/temp/CodeTP1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Tests/CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.obj"
	cd C:/temp/CodeTP1/build/Tests && C:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Tests/CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.obj -MF CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.obj.d -o CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.obj -c C:/temp/CodeTP1/Tests/CaseTesteur.cpp

Tests/CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.i"
	cd C:/temp/CodeTP1/build/Tests && C:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/temp/CodeTP1/Tests/CaseTesteur.cpp > CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.i

Tests/CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.s"
	cd C:/temp/CodeTP1/build/Tests && C:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/temp/CodeTP1/Tests/CaseTesteur.cpp -o CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.s

Tests/CMakeFiles/CaseTesteur.dir/__/Case.cpp.obj: Tests/CMakeFiles/CaseTesteur.dir/flags.make
Tests/CMakeFiles/CaseTesteur.dir/__/Case.cpp.obj: Tests/CMakeFiles/CaseTesteur.dir/includes_CXX.rsp
Tests/CMakeFiles/CaseTesteur.dir/__/Case.cpp.obj: C:/temp/CodeTP1/Case.cpp
Tests/CMakeFiles/CaseTesteur.dir/__/Case.cpp.obj: Tests/CMakeFiles/CaseTesteur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/temp/CodeTP1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Tests/CMakeFiles/CaseTesteur.dir/__/Case.cpp.obj"
	cd C:/temp/CodeTP1/build/Tests && C:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Tests/CMakeFiles/CaseTesteur.dir/__/Case.cpp.obj -MF CMakeFiles/CaseTesteur.dir/__/Case.cpp.obj.d -o CMakeFiles/CaseTesteur.dir/__/Case.cpp.obj -c C:/temp/CodeTP1/Case.cpp

Tests/CMakeFiles/CaseTesteur.dir/__/Case.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CaseTesteur.dir/__/Case.cpp.i"
	cd C:/temp/CodeTP1/build/Tests && C:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/temp/CodeTP1/Case.cpp > CMakeFiles/CaseTesteur.dir/__/Case.cpp.i

Tests/CMakeFiles/CaseTesteur.dir/__/Case.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CaseTesteur.dir/__/Case.cpp.s"
	cd C:/temp/CodeTP1/build/Tests && C:/msys64/ucrt64/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/temp/CodeTP1/Case.cpp -o CMakeFiles/CaseTesteur.dir/__/Case.cpp.s

# Object files for target CaseTesteur
CaseTesteur_OBJECTS = \
"CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.obj" \
"CMakeFiles/CaseTesteur.dir/__/Case.cpp.obj"

# External object files for target CaseTesteur
CaseTesteur_EXTERNAL_OBJECTS =

Tests/CaseTesteur.exe: Tests/CMakeFiles/CaseTesteur.dir/CaseTesteur.cpp.obj
Tests/CaseTesteur.exe: Tests/CMakeFiles/CaseTesteur.dir/__/Case.cpp.obj
Tests/CaseTesteur.exe: Tests/CMakeFiles/CaseTesteur.dir/build.make
Tests/CaseTesteur.exe: lib/libgtest_main.a
Tests/CaseTesteur.exe: lib/libgtest.a
Tests/CaseTesteur.exe: Tests/CMakeFiles/CaseTesteur.dir/linkLibs.rsp
Tests/CaseTesteur.exe: Tests/CMakeFiles/CaseTesteur.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/temp/CodeTP1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CaseTesteur.exe"
	cd C:/temp/CodeTP1/build/Tests && "C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe" -E rm -f CMakeFiles/CaseTesteur.dir/objects.a
	cd C:/temp/CodeTP1/build/Tests && C:/msys64/ucrt64/bin/ar.exe qc CMakeFiles/CaseTesteur.dir/objects.a @CMakeFiles/CaseTesteur.dir/objects1.rsp
	cd C:/temp/CodeTP1/build/Tests && C:/msys64/ucrt64/bin/c++.exe  -std=c++11 -g -Wl,--whole-archive CMakeFiles/CaseTesteur.dir/objects.a -Wl,--no-whole-archive -o CaseTesteur.exe -Wl,--out-implib,libCaseTesteur.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/CaseTesteur.dir/linkLibs.rsp

# Rule to build all files generated by this target.
Tests/CMakeFiles/CaseTesteur.dir/build: Tests/CaseTesteur.exe
.PHONY : Tests/CMakeFiles/CaseTesteur.dir/build

Tests/CMakeFiles/CaseTesteur.dir/clean:
	cd C:/temp/CodeTP1/build/Tests && $(CMAKE_COMMAND) -P CMakeFiles/CaseTesteur.dir/cmake_clean.cmake
.PHONY : Tests/CMakeFiles/CaseTesteur.dir/clean

Tests/CMakeFiles/CaseTesteur.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/temp/CodeTP1 C:/temp/CodeTP1/Tests C:/temp/CodeTP1/build C:/temp/CodeTP1/build/Tests C:/temp/CodeTP1/build/Tests/CMakeFiles/CaseTesteur.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Tests/CMakeFiles/CaseTesteur.dir/depend

