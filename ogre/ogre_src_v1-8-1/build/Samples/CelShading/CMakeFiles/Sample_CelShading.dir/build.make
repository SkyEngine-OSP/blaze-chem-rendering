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
include Samples/CelShading/CMakeFiles/Sample_CelShading.dir/depend.make

# Include the progress variables for this target.
include Samples/CelShading/CMakeFiles/Sample_CelShading.dir/progress.make

# Include the compile flags for this target's objects.
include Samples/CelShading/CMakeFiles/Sample_CelShading.dir/flags.make

Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o: Samples/CelShading/CMakeFiles/Sample_CelShading.dir/flags.make
Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o: ../Samples/CelShading/src/CelShading.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/CelShading && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o -c /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/CelShading/src/CelShading.cpp

Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.i"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/CelShading && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/CelShading/src/CelShading.cpp > CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.i

Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.s"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/CelShading && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/CelShading/src/CelShading.cpp -o CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.s

Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o.requires:
.PHONY : Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o.requires

Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o.provides: Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o.requires
	$(MAKE) -f Samples/CelShading/CMakeFiles/Sample_CelShading.dir/build.make Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o.provides.build
.PHONY : Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o.provides

Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o.provides.build: Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o

# Object files for target Sample_CelShading
Sample_CelShading_OBJECTS = \
"CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o"

# External object files for target Sample_CelShading
Sample_CelShading_EXTERNAL_OBJECTS =

lib/Sample_CelShading.so: Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o
lib/Sample_CelShading.so: Samples/CelShading/CMakeFiles/Sample_CelShading.dir/build.make
lib/Sample_CelShading.so: lib/libOgreMain.so.1.8.1
lib/Sample_CelShading.so: lib/libOgreRTShaderSystem.so.1.8.1
lib/Sample_CelShading.so: /usr/lib/libOIS.so
lib/Sample_CelShading.so: lib/libOgreMain.so.1.8.1
lib/Sample_CelShading.so: /usr/lib/i386-linux-gnu/libfreetype.so
lib/Sample_CelShading.so: /usr/lib/i386-linux-gnu/libSM.so
lib/Sample_CelShading.so: /usr/lib/i386-linux-gnu/libICE.so
lib/Sample_CelShading.so: /usr/lib/i386-linux-gnu/libX11.so
lib/Sample_CelShading.so: /usr/lib/i386-linux-gnu/libXext.so
lib/Sample_CelShading.so: /usr/lib/i386-linux-gnu/libXt.so
lib/Sample_CelShading.so: /usr/lib/i386-linux-gnu/libXaw.so
lib/Sample_CelShading.so: /usr/lib/libboost_thread-mt.so
lib/Sample_CelShading.so: /usr/lib/libboost_date_time-mt.so
lib/Sample_CelShading.so: /usr/lib/libfreeimage.so
lib/Sample_CelShading.so: /usr/lib/libzzip.so
lib/Sample_CelShading.so: /usr/lib/i386-linux-gnu/libz.so
lib/Sample_CelShading.so: Samples/CelShading/CMakeFiles/Sample_CelShading.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../lib/Sample_CelShading.so"
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/CelShading && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sample_CelShading.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Samples/CelShading/CMakeFiles/Sample_CelShading.dir/build: lib/Sample_CelShading.so
.PHONY : Samples/CelShading/CMakeFiles/Sample_CelShading.dir/build

Samples/CelShading/CMakeFiles/Sample_CelShading.dir/requires: Samples/CelShading/CMakeFiles/Sample_CelShading.dir/src/CelShading.cpp.o.requires
.PHONY : Samples/CelShading/CMakeFiles/Sample_CelShading.dir/requires

Samples/CelShading/CMakeFiles/Sample_CelShading.dir/clean:
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/CelShading && $(CMAKE_COMMAND) -P CMakeFiles/Sample_CelShading.dir/cmake_clean.cmake
.PHONY : Samples/CelShading/CMakeFiles/Sample_CelShading.dir/clean

Samples/CelShading/CMakeFiles/Sample_CelShading.dir/depend:
	cd /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1 /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/CelShading /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/CelShading /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/CelShading/CMakeFiles/Sample_CelShading.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Samples/CelShading/CMakeFiles/Sample_CelShading.dir/depend

