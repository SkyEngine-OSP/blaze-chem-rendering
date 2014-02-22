# Install script for directory: /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE" TYPE FILE FILES
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/SdkTrays.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/SdkCameraMan.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/ExampleFrameListener.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/SdkSample.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/FileSystemLayer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/ExampleLoadingBar.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/OgreStaticPluginLoader.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/SampleContext.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/ExampleApplication.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/Sample.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/Samples/Common/include/SamplePlugin.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/BezierPatch/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/TestPlugin/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/CameraTrack/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Character/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Compositor/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/DualQuaternion/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/DynTex/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/FacialAnimation/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Grass/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Instancing/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Lighting/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/NewInstancing/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/OceanDemo/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/ParticleFX/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/ShaderSystem/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Shadows/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/SkeletalAnimation/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/SkyBox/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/SkyDome/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/SkyPlane/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Smoke/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/SphereMapping/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Terrain/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/TextureFX/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/TextureArray/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Transparency/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/VolumeTex/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Water/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/BSP/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/CelShading/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/DeferredShading/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/CubeMapping/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Dot3Bump/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Fresnel/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Isosurf/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/ParticleGS/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/SSAO/cmake_install.cmake")
  INCLUDE("/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/Samples/Browser/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

