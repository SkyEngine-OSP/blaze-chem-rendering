# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build

# Include any dependencies generated for this target.
include Samples/Character/CMakeFiles/Sample_Character.dir/depend.make

# Include the progress variables for this target.
include Samples/Character/CMakeFiles/Sample_Character.dir/progress.make

# Include the compile flags for this target's objects.
include Samples/Character/CMakeFiles/Sample_Character.dir/flags.make

Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o: Samples/Character/CMakeFiles/Sample_Character.dir/flags.make
Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o: ../Samples/Character/src/CharacterSample.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Character && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o -c /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Character/src/CharacterSample.cpp

Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.i"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Character && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Character/src/CharacterSample.cpp > CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.i

Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.s"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Character && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Character/src/CharacterSample.cpp -o CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.s

Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o.requires:
.PHONY : Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o.requires

Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o.provides: Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o.requires
	$(MAKE) -f Samples/Character/CMakeFiles/Sample_Character.dir/build.make Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o.provides.build
.PHONY : Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o.provides

Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o.provides.build: Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o

# Object files for target Sample_Character
Sample_Character_OBJECTS = \
"CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o"

# External object files for target Sample_Character
Sample_Character_EXTERNAL_OBJECTS =

lib/Sample_Character.so: Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o
lib/Sample_Character.so: Samples/Character/CMakeFiles/Sample_Character.dir/build.make
lib/Sample_Character.so: lib/libOgreMain.so.1.8.1
lib/Sample_Character.so: lib/libOgreRTShaderSystem.so.1.8.1
lib/Sample_Character.so: /usr/lib/libOIS.so
lib/Sample_Character.so: lib/libOgreMain.so.1.8.1
lib/Sample_Character.so: /usr/lib/i386-linux-gnu/libfreetype.so
lib/Sample_Character.so: /usr/lib/i386-linux-gnu/libSM.so
lib/Sample_Character.so: /usr/lib/i386-linux-gnu/libICE.so
lib/Sample_Character.so: /usr/lib/i386-linux-gnu/libX11.so
lib/Sample_Character.so: /usr/lib/i386-linux-gnu/libXext.so
lib/Sample_Character.so: /usr/lib/i386-linux-gnu/libXt.so
lib/Sample_Character.so: /usr/lib/i386-linux-gnu/libXaw.so
lib/Sample_Character.so: /usr/lib/libboost_thread-mt.so
lib/Sample_Character.so: /usr/lib/libboost_date_time-mt.so
lib/Sample_Character.so: /usr/lib/libfreeimage.so
lib/Sample_Character.so: /usr/lib/libzzip.so
lib/Sample_Character.so: /usr/lib/i386-linux-gnu/libz.so
lib/Sample_Character.so: Samples/Character/CMakeFiles/Sample_Character.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../lib/Sample_Character.so"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Character && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sample_Character.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Samples/Character/CMakeFiles/Sample_Character.dir/build: lib/Sample_Character.so
.PHONY : Samples/Character/CMakeFiles/Sample_Character.dir/build

Samples/Character/CMakeFiles/Sample_Character.dir/requires: Samples/Character/CMakeFiles/Sample_Character.dir/src/CharacterSample.cpp.o.requires
.PHONY : Samples/Character/CMakeFiles/Sample_Character.dir/requires

Samples/Character/CMakeFiles/Sample_Character.dir/clean:
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Character && $(CMAKE_COMMAND) -P CMakeFiles/Sample_Character.dir/cmake_clean.cmake
.PHONY : Samples/Character/CMakeFiles/Sample_Character.dir/clean

Samples/Character/CMakeFiles/Sample_Character.dir/depend:
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1 /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Character /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Character /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Character/CMakeFiles/Sample_Character.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Samples/Character/CMakeFiles/Sample_Character.dir/depend

