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
include Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/depend.make

# Include the progress variables for this target.
include Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/progress.make

# Include the compile flags for this target's objects.
include Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/flags.make

Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o: Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/flags.make
Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o: ../Samples/TestPlugin/src/TestPlugin.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/TestPlugin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o -c /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/TestPlugin/src/TestPlugin.cpp

Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.i"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/TestPlugin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/TestPlugin/src/TestPlugin.cpp > CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.i

Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.s"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/TestPlugin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/TestPlugin/src/TestPlugin.cpp -o CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.s

Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o.requires:
.PHONY : Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o.requires

Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o.provides: Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o.requires
	$(MAKE) -f Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/build.make Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o.provides.build
.PHONY : Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o.provides

Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o.provides.build: Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o

# Object files for target Sample_TestPlugin
Sample_TestPlugin_OBJECTS = \
"CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o"

# External object files for target Sample_TestPlugin
Sample_TestPlugin_EXTERNAL_OBJECTS =

lib/Sample_TestPlugin.so: Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o
lib/Sample_TestPlugin.so: Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/build.make
lib/Sample_TestPlugin.so: lib/libOgreMain.so.1.8.1
lib/Sample_TestPlugin.so: lib/libOgreRTShaderSystem.so.1.8.1
lib/Sample_TestPlugin.so: /usr/lib/libOIS.so
lib/Sample_TestPlugin.so: lib/libOgreMain.so.1.8.1
lib/Sample_TestPlugin.so: /usr/lib/i386-linux-gnu/libfreetype.so
lib/Sample_TestPlugin.so: /usr/lib/i386-linux-gnu/libSM.so
lib/Sample_TestPlugin.so: /usr/lib/i386-linux-gnu/libICE.so
lib/Sample_TestPlugin.so: /usr/lib/i386-linux-gnu/libX11.so
lib/Sample_TestPlugin.so: /usr/lib/i386-linux-gnu/libXext.so
lib/Sample_TestPlugin.so: /usr/lib/i386-linux-gnu/libXt.so
lib/Sample_TestPlugin.so: /usr/lib/i386-linux-gnu/libXaw.so
lib/Sample_TestPlugin.so: /usr/lib/libboost_thread-mt.so
lib/Sample_TestPlugin.so: /usr/lib/libboost_date_time-mt.so
lib/Sample_TestPlugin.so: /usr/lib/libfreeimage.so
lib/Sample_TestPlugin.so: /usr/lib/libzzip.so
lib/Sample_TestPlugin.so: /usr/lib/i386-linux-gnu/libz.so
lib/Sample_TestPlugin.so: Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../lib/Sample_TestPlugin.so"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/TestPlugin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sample_TestPlugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/build: lib/Sample_TestPlugin.so
.PHONY : Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/build

Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/requires: Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/src/TestPlugin.cpp.o.requires
.PHONY : Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/requires

Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/clean:
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/TestPlugin && $(CMAKE_COMMAND) -P CMakeFiles/Sample_TestPlugin.dir/cmake_clean.cmake
.PHONY : Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/clean

Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/depend:
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1 /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/TestPlugin /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/TestPlugin /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Samples/TestPlugin/CMakeFiles/Sample_TestPlugin.dir/depend

