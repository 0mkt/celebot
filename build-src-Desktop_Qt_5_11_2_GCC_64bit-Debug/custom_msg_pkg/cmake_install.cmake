# Install script for directory: /home/michal/catkin_ws/src/custom_msg_pkg

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/custom_msg_pkg/msg" TYPE FILE FILES
    "/home/michal/catkin_ws/src/custom_msg_pkg/msg/EziServoActualMotion.msg"
    "/home/michal/catkin_ws/src/custom_msg_pkg/msg/EziServoStatus.msg"
    "/home/michal/catkin_ws/src/custom_msg_pkg/msg/EziServoData.msg"
    "/home/michal/catkin_ws/src/custom_msg_pkg/msg/EziServosData.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/custom_msg_pkg/srv" TYPE FILE FILES "/home/michal/catkin_ws/src/custom_msg_pkg/srv/ChangeNodeStateSrv.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/custom_msg_pkg/cmake" TYPE FILE FILES "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/custom_msg_pkg/catkin_generated/installspace/custom_msg_pkg-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/devel/include/custom_msg_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/devel/share/roseus/ros/custom_msg_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/devel/share/common-lisp/ros/custom_msg_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/devel/share/gennodejs/ros/custom_msg_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/devel/lib/python2.7/dist-packages/custom_msg_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/devel/lib/python2.7/dist-packages/custom_msg_pkg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/custom_msg_pkg/catkin_generated/installspace/custom_msg_pkg.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/custom_msg_pkg/cmake" TYPE FILE FILES "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/custom_msg_pkg/catkin_generated/installspace/custom_msg_pkg-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/custom_msg_pkg/cmake" TYPE FILE FILES
    "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/custom_msg_pkg/catkin_generated/installspace/custom_msg_pkgConfig.cmake"
    "/home/michal/catkin_ws/build-src-Desktop_Qt_5_11_2_GCC_64bit-Debug/custom_msg_pkg/catkin_generated/installspace/custom_msg_pkgConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/custom_msg_pkg" TYPE FILE FILES "/home/michal/catkin_ws/src/custom_msg_pkg/package.xml")
endif()

