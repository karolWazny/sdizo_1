# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program_Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program_Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\projects\clion\sdizo_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\projects\clion\sdizo_1\cmake-build-release

# Include any dependencies generated for this target.
include program\CMakeFiles\structure_templates_lib.dir\depend.make

# Include the progress variables for this target.
include program\CMakeFiles\structure_templates_lib.dir\progress.make

# Include the compile flags for this target's objects.
include program\CMakeFiles\structure_templates_lib.dir\flags.make

program\CMakeFiles\structure_templates_lib.dir\index.cpp.obj: program\CMakeFiles\structure_templates_lib.dir\flags.make
program\CMakeFiles\structure_templates_lib.dir\index.cpp.obj: ..\structure_templates_lib\index.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\projects\clion\sdizo_1\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object program/CMakeFiles/structure_templates_lib.dir/index.cpp.obj"
	cd D:\projects\clion\sdizo_1\cmake-build-release\program
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\structure_templates_lib.dir\index.cpp.obj /FdCMakeFiles\structure_templates_lib.dir\structure_templates_lib.pdb /FS -c D:\projects\clion\sdizo_1\structure_templates_lib\index.cpp
<<
	cd D:\projects\clion\sdizo_1\cmake-build-release

program\CMakeFiles\structure_templates_lib.dir\index.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/structure_templates_lib.dir/index.cpp.i"
	cd D:\projects\clion\sdizo_1\cmake-build-release\program
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\structure_templates_lib.dir\index.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\projects\clion\sdizo_1\structure_templates_lib\index.cpp
<<
	cd D:\projects\clion\sdizo_1\cmake-build-release

program\CMakeFiles\structure_templates_lib.dir\index.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/structure_templates_lib.dir/index.cpp.s"
	cd D:\projects\clion\sdizo_1\cmake-build-release\program
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\structure_templates_lib.dir\index.cpp.s /c D:\projects\clion\sdizo_1\structure_templates_lib\index.cpp
<<
	cd D:\projects\clion\sdizo_1\cmake-build-release

# Object files for target structure_templates_lib
structure_templates_lib_OBJECTS = \
"CMakeFiles\structure_templates_lib.dir\index.cpp.obj"

# External object files for target structure_templates_lib
structure_templates_lib_EXTERNAL_OBJECTS =

program\structure_templates_lib.lib: program\CMakeFiles\structure_templates_lib.dir\index.cpp.obj
program\structure_templates_lib.lib: program\CMakeFiles\structure_templates_lib.dir\build.make
program\structure_templates_lib.lib: program\CMakeFiles\structure_templates_lib.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\projects\clion\sdizo_1\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library structure_templates_lib.lib"
	cd D:\projects\clion\sdizo_1\cmake-build-release\program
	$(CMAKE_COMMAND) -P CMakeFiles\structure_templates_lib.dir\cmake_clean_target.cmake
	cd D:\projects\clion\sdizo_1\cmake-build-release
	cd D:\projects\clion\sdizo_1\cmake-build-release\program
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\link.exe /lib /nologo /machine:X86 /out:structure_templates_lib.lib @CMakeFiles\structure_templates_lib.dir\objects1.rsp 
	cd D:\projects\clion\sdizo_1\cmake-build-release

# Rule to build all files generated by this target.
program\CMakeFiles\structure_templates_lib.dir\build: program\structure_templates_lib.lib

.PHONY : program\CMakeFiles\structure_templates_lib.dir\build

program\CMakeFiles\structure_templates_lib.dir\clean:
	cd D:\projects\clion\sdizo_1\cmake-build-release\program
	$(CMAKE_COMMAND) -P CMakeFiles\structure_templates_lib.dir\cmake_clean.cmake
	cd D:\projects\clion\sdizo_1\cmake-build-release
.PHONY : program\CMakeFiles\structure_templates_lib.dir\clean

program\CMakeFiles\structure_templates_lib.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\projects\clion\sdizo_1 D:\projects\clion\sdizo_1\structure_templates_lib D:\projects\clion\sdizo_1\cmake-build-release D:\projects\clion\sdizo_1\cmake-build-release\program D:\projects\clion\sdizo_1\cmake-build-release\program\CMakeFiles\structure_templates_lib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : program\CMakeFiles\structure_templates_lib.dir\depend

