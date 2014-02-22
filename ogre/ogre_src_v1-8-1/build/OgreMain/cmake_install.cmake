# Install script for directory: /home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain

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
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_CHECK
             FILE "${file}"
             RPATH "")
      ENDIF()
    ENDFOREACH()
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/libOgreMain.so.1.8.1"
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/libOgreMain.so"
      )
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
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
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_CHECK
             FILE "${file}"
             RPATH "")
      ENDIF()
    ENDFOREACH()
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/libOgreMain.so.1.8.1"
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/libOgreMain.so"
      )
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
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
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_CHECK
             FILE "${file}"
             RPATH "")
      ENDIF()
    ENDFOREACH()
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/libOgreMain.so.1.8.1"
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/libOgreMain.so"
      )
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
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
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        FILE(RPATH_CHECK
             FILE "${file}"
             RPATH "")
      ENDIF()
    ENDFOREACH()
    FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/libOgreMain.so.1.8.1"
      "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/lib/libOgreMain.so"
      )
    FOREACH(file
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so.1.8.1"
        "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOgreMain.so"
        )
      IF(EXISTS "${file}" AND
         NOT IS_SYMLINK "${file}")
        IF(CMAKE_INSTALL_DO_STRIP)
          EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
        ENDIF(CMAKE_INSTALL_DO_STRIP)
      ENDIF()
    ENDFOREACH()
  ENDIF("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE" TYPE FILE FILES
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/asm_math.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/Ogre.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreAlignedAllocator.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreAnimable.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreAnimation.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreAnimationState.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreAnimationTrack.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreAny.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreArchive.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreArchiveFactory.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreArchiveManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreAtomicWrappers.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreAutoParamDataSource.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreAxisAlignedBox.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreBillboard.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreBillboardChain.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreBillboardParticleRenderer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreBillboardSet.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreBitwise.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreBlendMode.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreBone.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreBorderPanelOverlayElement.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/build/include/OgreBuildSettings.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCamera.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCodec.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreColourValue.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCommon.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCompositionPass.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCompositionTargetPass.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCompositionTechnique.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCompositor.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCompositorChain.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCompositorLogic.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCompositorInstance.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCompositorManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreConfig.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreConfigDialog.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreConfigFile.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreConfigOptionMap.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreController.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreControllerManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreConvexBody.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreCustomCompositionPass.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreDataStream.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreDefaultHardwareBufferManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreDeflate.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreDepthBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreDistanceLodStrategy.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreDualQuaternion.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreDynLib.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreDynLibManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreEdgeListBuilder.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreEntity.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreErrorDialog.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreException.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreExternalTextureSource.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreExternalTextureSourceManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreFactoryObj.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreFileSystem.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreFont.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreFontManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreFrameListener.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreFrustum.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreGpuProgram.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreGpuProgramManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreGpuProgramParams.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreGpuProgramUsage.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreHardwareBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreHardwareBufferManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreHardwareIndexBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreHardwareOcclusionQuery.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreHardwarePixelBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreHardwareVertexBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreHeaderPrefix.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreHeaderSuffix.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreHighLevelGpuProgram.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreHighLevelGpuProgramManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreImage.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreImageCodec.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreInstanceBatch.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreInstanceBatchHW.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreInstanceBatchHW_VTF.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreInstanceBatchShader.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreInstanceBatchVTF.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreInstancedGeometry.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreInstancedEntity.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreInstanceManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreIteratorRange.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreIteratorWrapper.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreIteratorWrappers.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreKeyFrame.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreLight.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreLodListener.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreLodStrategy.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreLodStrategyManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreLog.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreLogManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreManualObject.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMaterial.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMaterialManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMaterialSerializer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMath.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMatrix3.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMatrix4.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMemoryAllocatedObject.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMemoryAllocatorConfig.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMemoryNedAlloc.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMemoryNedPooling.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMemoryStdAlloc.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMemorySTLAllocator.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMemoryTracker.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMesh.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMeshFileFormat.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMeshManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMeshSerializer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMeshSerializerImpl.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMovableObject.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreMovablePlane.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreNode.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreNumerics.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreOptimisedUtil.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreOverlay.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreOverlayContainer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreOverlayElement.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreOverlayElementCommands.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreOverlayElementFactory.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreOverlayManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePanelOverlayElement.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticle.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticleAffector.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticleAffectorFactory.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticleEmitter.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticleEmitterCommands.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticleEmitterFactory.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticleIterator.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticleScriptCompiler.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticleSystem.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticleSystemManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreParticleSystemRenderer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePass.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePatchMesh.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePatchSurface.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePixelCountLodStrategy.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePixelFormat.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePlane.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePlaneBoundedVolume.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePlatform.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePlatformInformation.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePlugin.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePolygon.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePose.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePredefinedControllers.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePrefabFactory.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgrePrerequisites.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreProfiler.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreProgressiveMesh.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreQuaternion.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRadixSort.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRay.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRectangle.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRectangle2D.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderable.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderObjectListener.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderOperation.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderQueue.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderQueueInvocation.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderQueueListener.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderQueueSortingGrouping.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderSystem.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderSystemCapabilities.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderSystemCapabilitiesManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderSystemCapabilitiesSerializer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderTarget.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderTargetListener.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderTexture.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderToVertexBuffer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRenderWindow.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreResource.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreResourceBackgroundQueue.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreResourceGroupManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreResourceManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRibbonTrail.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRoot.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreRotationalSpline.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSceneManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSceneManagerEnumerator.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSceneNode.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSceneQuery.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreScriptCompiler.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreScriptLexer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreScriptLoader.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreScriptParser.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreScriptTranslator.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSearchOps.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSerializer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreShadowCameraSetup.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreShadowCameraSetupFocused.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreShadowCameraSetupLiSPSM.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreShadowCameraSetupPlaneOptimal.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreShadowCameraSetupPSSM.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreShadowCaster.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreShadowTextureManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreShadowVolumeExtrudeProgram.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSharedPtr.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSimpleRenderable.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSimpleSpline.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSingleton.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSkeleton.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSkeletonFileFormat.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSkeletonInstance.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSkeletonManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSkeletonSerializer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSmallVector.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSphere.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSpotShadowFadePng.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreStableHeaders.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreStaticFaceGroup.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreStaticGeometry.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreStdHeaders.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreStreamSerialiser.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreString.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreStringConverter.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreStringInterface.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreStringVector.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSubEntity.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreSubMesh.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreTagPoint.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreTangentSpaceCalc.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreTechnique.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreTextAreaOverlayElement.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreTexture.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreTextureManager.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreTextureUnitState.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreTimer.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreUnifiedHighLevelGpuProgram.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreUserObjectBindings.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreUTFString.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreVector2.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreVector3.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreVector4.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreVertexBoneAssignment.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreVertexIndexData.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreViewport.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreWindowEventUtilities.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreWireBoundingBox.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreWorkQueue.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreFreeImageCodec.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreDDSCodec.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/OgreZip.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/GLX" TYPE FILE FILES
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/GLX/OgreConfigDialogImp.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/GLX/OgreErrorDialogImp.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/GLX/OgreTimerImp.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OGRE/Threading" TYPE FILE FILES
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/Threading/OgreThreadDefines.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/Threading/OgreThreadHeaders.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/Threading/OgreDefaultWorkQueue.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/Threading/OgreThreadDefinesBoost.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/Threading/OgreThreadHeadersBoost.h"
    "/home/jeff/dev/dev_apps/sand/ogre/ogre_src_v1-8-1/OgreMain/include/Threading/OgreDefaultWorkQueueStandard.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

