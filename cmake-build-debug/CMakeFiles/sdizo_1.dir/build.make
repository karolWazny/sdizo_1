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
CMAKE_BINARY_DIR = D:\projects\clion\sdizo_1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\sdizo_1.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\sdizo_1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\sdizo_1.dir\flags.make

CMakeFiles\sdizo_1.dir\program\Main.cpp.obj: CMakeFiles\sdizo_1.dir\flags.make
CMakeFiles\sdizo_1.dir\program\Main.cpp.obj: ..\program\Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\projects\clion\sdizo_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sdizo_1.dir/program/Main.cpp.obj"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\sdizo_1.dir\program\Main.cpp.obj /FdCMakeFiles\sdizo_1.dir\ /FS -c D:\projects\clion\sdizo_1\program\Main.cpp
<<

CMakeFiles\sdizo_1.dir\program\Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdizo_1.dir/program/Main.cpp.i"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\sdizo_1.dir\program\Main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\projects\clion\sdizo_1\program\Main.cpp
<<

CMakeFiles\sdizo_1.dir\program\Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdizo_1.dir/program/Main.cpp.s"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\sdizo_1.dir\program\Main.cpp.s /c D:\projects\clion\sdizo_1\program\Main.cpp
<<

CMakeFiles\sdizo_1.dir\program\ArrayOperations.cpp.obj: CMakeFiles\sdizo_1.dir\flags.make
CMakeFiles\sdizo_1.dir\program\ArrayOperations.cpp.obj: ..\program\ArrayOperations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\projects\clion\sdizo_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sdizo_1.dir/program/ArrayOperations.cpp.obj"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\sdizo_1.dir\program\ArrayOperations.cpp.obj /FdCMakeFiles\sdizo_1.dir\ /FS -c D:\projects\clion\sdizo_1\program\ArrayOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\ArrayOperations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdizo_1.dir/program/ArrayOperations.cpp.i"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\sdizo_1.dir\program\ArrayOperations.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\projects\clion\sdizo_1\program\ArrayOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\ArrayOperations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdizo_1.dir/program/ArrayOperations.cpp.s"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\sdizo_1.dir\program\ArrayOperations.cpp.s /c D:\projects\clion\sdizo_1\program\ArrayOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\ListOperations.cpp.obj: CMakeFiles\sdizo_1.dir\flags.make
CMakeFiles\sdizo_1.dir\program\ListOperations.cpp.obj: ..\program\ListOperations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\projects\clion\sdizo_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sdizo_1.dir/program/ListOperations.cpp.obj"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\sdizo_1.dir\program\ListOperations.cpp.obj /FdCMakeFiles\sdizo_1.dir\ /FS -c D:\projects\clion\sdizo_1\program\ListOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\ListOperations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdizo_1.dir/program/ListOperations.cpp.i"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\sdizo_1.dir\program\ListOperations.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\projects\clion\sdizo_1\program\ListOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\ListOperations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdizo_1.dir/program/ListOperations.cpp.s"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\sdizo_1.dir\program\ListOperations.cpp.s /c D:\projects\clion\sdizo_1\program\ListOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\HeapOperations.cpp.obj: CMakeFiles\sdizo_1.dir\flags.make
CMakeFiles\sdizo_1.dir\program\HeapOperations.cpp.obj: ..\program\HeapOperations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\projects\clion\sdizo_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sdizo_1.dir/program/HeapOperations.cpp.obj"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\sdizo_1.dir\program\HeapOperations.cpp.obj /FdCMakeFiles\sdizo_1.dir\ /FS -c D:\projects\clion\sdizo_1\program\HeapOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\HeapOperations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdizo_1.dir/program/HeapOperations.cpp.i"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\sdizo_1.dir\program\HeapOperations.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\projects\clion\sdizo_1\program\HeapOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\HeapOperations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdizo_1.dir/program/HeapOperations.cpp.s"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\sdizo_1.dir\program\HeapOperations.cpp.s /c D:\projects\clion\sdizo_1\program\HeapOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\RBTreeOperations.cpp.obj: CMakeFiles\sdizo_1.dir\flags.make
CMakeFiles\sdizo_1.dir\program\RBTreeOperations.cpp.obj: ..\program\RBTreeOperations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\projects\clion\sdizo_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sdizo_1.dir/program/RBTreeOperations.cpp.obj"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\sdizo_1.dir\program\RBTreeOperations.cpp.obj /FdCMakeFiles\sdizo_1.dir\ /FS -c D:\projects\clion\sdizo_1\program\RBTreeOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\RBTreeOperations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdizo_1.dir/program/RBTreeOperations.cpp.i"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\sdizo_1.dir\program\RBTreeOperations.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\projects\clion\sdizo_1\program\RBTreeOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\RBTreeOperations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdizo_1.dir/program/RBTreeOperations.cpp.s"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\sdizo_1.dir\program\RBTreeOperations.cpp.s /c D:\projects\clion\sdizo_1\program\RBTreeOperations.cpp
<<

CMakeFiles\sdizo_1.dir\program\TextFileReader.cpp.obj: CMakeFiles\sdizo_1.dir\flags.make
CMakeFiles\sdizo_1.dir\program\TextFileReader.cpp.obj: ..\program\TextFileReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\projects\clion\sdizo_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sdizo_1.dir/program/TextFileReader.cpp.obj"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\sdizo_1.dir\program\TextFileReader.cpp.obj /FdCMakeFiles\sdizo_1.dir\ /FS -c D:\projects\clion\sdizo_1\program\TextFileReader.cpp
<<

CMakeFiles\sdizo_1.dir\program\TextFileReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sdizo_1.dir/program/TextFileReader.cpp.i"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe > CMakeFiles\sdizo_1.dir\program\TextFileReader.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\projects\clion\sdizo_1\program\TextFileReader.cpp
<<

CMakeFiles\sdizo_1.dir\program\TextFileReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sdizo_1.dir/program/TextFileReader.cpp.s"
	C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\sdizo_1.dir\program\TextFileReader.cpp.s /c D:\projects\clion\sdizo_1\program\TextFileReader.cpp
<<

# Object files for target sdizo_1
sdizo_1_OBJECTS = \
"CMakeFiles\sdizo_1.dir\program\Main.cpp.obj" \
"CMakeFiles\sdizo_1.dir\program\ArrayOperations.cpp.obj" \
"CMakeFiles\sdizo_1.dir\program\ListOperations.cpp.obj" \
"CMakeFiles\sdizo_1.dir\program\HeapOperations.cpp.obj" \
"CMakeFiles\sdizo_1.dir\program\RBTreeOperations.cpp.obj" \
"CMakeFiles\sdizo_1.dir\program\TextFileReader.cpp.obj"

# External object files for target sdizo_1
sdizo_1_EXTERNAL_OBJECTS =

sdizo_1.exe: CMakeFiles\sdizo_1.dir\program\Main.cpp.obj
sdizo_1.exe: CMakeFiles\sdizo_1.dir\program\ArrayOperations.cpp.obj
sdizo_1.exe: CMakeFiles\sdizo_1.dir\program\ListOperations.cpp.obj
sdizo_1.exe: CMakeFiles\sdizo_1.dir\program\HeapOperations.cpp.obj
sdizo_1.exe: CMakeFiles\sdizo_1.dir\program\RBTreeOperations.cpp.obj
sdizo_1.exe: CMakeFiles\sdizo_1.dir\program\TextFileReader.cpp.obj
sdizo_1.exe: CMakeFiles\sdizo_1.dir\build.make
sdizo_1.exe: program\structure_templates_lib.lib
sdizo_1.exe: program\array_lib\array_lib.lib
sdizo_1.exe: program\binary_heap_lib\binary_heap_lib.lib
sdizo_1.exe: program\linked_list_lib\linked_list_lib.lib
sdizo_1.exe: program\trees_lib\trees_lib.lib
sdizo_1.exe: CMakeFiles\sdizo_1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\projects\clion\sdizo_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable sdizo_1.exe"
	"D:\Program_Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\sdizo_1.dir --rc=D:\WINDOW~1\10\bin\100190~1.0\x86\rc.exe --mt=D:\WINDOW~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\Program_Files_86\Microsoft_Visual_Studio\2019\Community\VC\Tools\MSVC\14.28.29333\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\sdizo_1.dir\objects1.rsp @<<
 /out:sdizo_1.exe /implib:sdizo_1.lib /pdb:D:\projects\clion\sdizo_1\cmake-build-debug\sdizo_1.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  program\structure_templates_lib.lib program\array_lib\array_lib.lib program\binary_heap_lib\binary_heap_lib.lib program\linked_list_lib\linked_list_lib.lib program\trees_lib\trees_lib.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\sdizo_1.dir\build: sdizo_1.exe

.PHONY : CMakeFiles\sdizo_1.dir\build

CMakeFiles\sdizo_1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sdizo_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\sdizo_1.dir\clean

CMakeFiles\sdizo_1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\projects\clion\sdizo_1 D:\projects\clion\sdizo_1 D:\projects\clion\sdizo_1\cmake-build-debug D:\projects\clion\sdizo_1\cmake-build-debug D:\projects\clion\sdizo_1\cmake-build-debug\CMakeFiles\sdizo_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\sdizo_1.dir\depend

