# Install script for directory: /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Nn][Oo][Nn][Ee]|)$")
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_CHECK
             FILE "${file}"
             RPATH "")
      ENDIF()
    ENDFOREACH()
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE SHARED_LIBRARY FILES
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/RenderSystem_GL.so.1.8.1"
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/RenderSystem_GL.so"
      )
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_REMOVE
             FILE "${file}")
        IF(CMAKE_INSTALL_DO_STRIP)
          EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
        ENDIF(CMAKE_INSTALL_DO_STRIP)
      ENDIF()
    ENDFOREACH()
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Nn][Oo][Nn][Ee]|)$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_CHECK
             FILE "${file}"
             RPATH "")
      ENDIF()
    ENDFOREACH()
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE SHARED_LIBRARY FILES
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/RenderSystem_GL.so.1.8.1"
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/RenderSystem_GL.so"
      )
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_REMOVE
             FILE "${file}")
        IF(CMAKE_INSTALL_DO_STRIP)
          EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
        ENDIF(CMAKE_INSTALL_DO_STRIP)
      ENDIF()
    ENDFOREACH()
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_CHECK
             FILE "${file}"
             RPATH "")
      ENDIF()
    ENDFOREACH()
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE SHARED_LIBRARY FILES
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/RenderSystem_GL.so.1.8.1"
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/RenderSystem_GL.so"
      )
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_REMOVE
             FILE "${file}")
        IF(CMAKE_INSTALL_DO_STRIP)
          EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
        ENDIF(CMAKE_INSTALL_DO_STRIP)
      ENDIF()
    ENDFOREACH()
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_CHECK
             FILE "${file}"
             RPATH "")
      ENDIF()
    ENDFOREACH()
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/OGRE" TYPE SHARED_LIBRARY FILES
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/RenderSystem_GL.so.1.8.1"
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/RenderSystem_GL.so"
      )
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/OGRE/RenderSystem_GL.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_REMOVE
             FILE "${file}")
        IF(CMAKE_INSTALL_DO_STRIP)
          EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
        ENDIF(CMAKE_INSTALL_DO_STRIP)
      ENDIF()
    ENDFOREACH()
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/RenderSystems/GL" TYPE FILE FILES
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLATIFSInit.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLContext.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLDefaultHardwareBufferManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLDepthBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLFBOMultiRenderTarget.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLFBORenderTexture.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLFrameBufferObject.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLGpuNvparseProgram.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLGpuProgram.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLGpuProgramManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLHardwareBufferManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLHardwareIndexBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLHardwareOcclusionQuery.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLHardwarePixelBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLHardwareVertexBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLPBRenderTexture.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLPBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLPixelFormat.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLPlugin.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLPrerequisites.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLRenderSystem.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLRenderTexture.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLRenderToVertexBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLSupport.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLTexture.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/OgreGLTextureManager.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/RenderSystems/GL/GLX" TYPE FILE FILES
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/GLX/OgreGLXContext.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/GLX/OgreGLXGLSupport.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/GLX/OgreGLXRenderTexture.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/GLX/OgreGLXUtils.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/GLX/OgreGLXWindow.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/src/GLX/OgreGLUtil.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/RenderSystems/GL" TYPE DIRECTORY FILES "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/include/GL")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/RenderSystems/GL" TYPE DIRECTORY FILES "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/RenderSystems/GL/src/GLSL/include/")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

