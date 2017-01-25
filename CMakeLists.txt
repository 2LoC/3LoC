cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(tloc_engine_superbuild)

enable_testing()
include(ExternalProject)

###-------------------------------------------------###

ExternalProject_Add(glfw
  GIT_REPOSITORY "https://github.com/glfw/glfw.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/glfw"
  CMAKE_ARGS -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/glfw/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/glfw/include/")
set(GLFW_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/install/glfw/lib/")

###-------------------------------------------------###

ExternalProject_Add(eigen
  GIT_REPOSITORY "https://github.com/RLovelett/eigen.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/eigen"
  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/eigen/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )
set(EIGEN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/eigen/include/eigen3")

###-------------------------------------------------###

ExternalProject_Add(bgfx
  GIT_REPOSITORY "https://github.com/samaursa/bgfx.cmake.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/bgfx"
  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DBGFX_BUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/bgfx/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(BGFX_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/bgfx/include/")
set(BGFX_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/install/bgfx/lib/")

###-------------------------------------------------###

include(ExternalProject)
ExternalProject_Add(spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/spdlog"
  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DBUILD_TESTING=OFF -DSPDLOG_BUILD_TESTING=OFF -DSPDLOG_BUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/spdlog/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(SPDLOG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/spdlog/include/")

###-------------------------------------------------###

ExternalProject_Add(catch
  GIT_REPOSITORY "https://github.com/samaursa/catch.git" 
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/catch"
  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/catch/ -H. -BBuild -Wdev

  TEST_COMMAND ""
  )

set(CATCH_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/catch/include/")

###-------------------------------------------------###

ExternalProject_Add(tloc
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/engine/"

  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DTLOC_SUPERBUILD_DIR=${CMAKE_SOURCE_DIR} -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/tloc/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(TLOC_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/tloc/include/")
set(TLOC_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/install/tloc/lib/")

###-------------------------------------------------###
### Dependencies

add_dependencies(tloc glfw)
add_dependencies(tloc eigen)
add_dependencies(tloc bgfx)
add_dependencies(tloc spdlog)
add_dependencies(tloc catch)

###-------------------------------------------------###
### Auto generate a helper file for use with 

FILE(WRITE "install/tl_superbuild_paths.cmake"
"\#\#\# ---------------------------------------------
\#\#\# This is auto-generated to facilitate defining project variables

\#\#\# ---------------------------------------------
\#\#\# Include directories

set(GLFW_INCLUDE_DIR    \"${GLFW_INCLUDE_DIR}\")
set(EIGEN_INCLUDE_DIR   \"${EIGEN_INCLUDE_DIR}\")
set(BGFX_INCLUDE_DIR    \"${BGFX_INCLUDE_DIR}\")
set(SPDLOG_INCLUDE_DIR  \"${SPDLOG_INCLUDE_DIR}\")
set(CATCH_INCLUDE_DIR   \"${CATCH_INCLUDE_DIR}\")
set(TLOC_INCLUDE_DIR    \"${TLOC_INCLUDE_DIR}\")

\#\#\# ---------------------------------------------
\#\#\# Library directories

set(GLFW_LIBRARY_DIR    \"${GLFW_LIBRARY_DIR}\")
set(BGFX_LIBRARY_DIR    \"${BGFX_LIBRARY_DIR}\")
set(TLOC_LIBRARY_DIR    \"${TLOC_LIBRARY_DIR}\")

\#\#\# ---------------------------------------------
\#\#\# Libraries

find_library(GLFW_LIB_D  glfw3_d \"${GLFW_LIBRARY_DIR}\")
find_library(GLFW_LIB    glfw3   \"${GLFW_LIBRARY_DIR}\")

find_library(BGFX_LIB_D  bgfx_d \"${BGFX_LIBRARY_DIR}\")
find_library(BGFX_LIB    bgfx   \"${BGFX_LIBRARY_DIR}\")

set(TLOC_LIBS           \"tloc_engine\")
set(TLOC_LIBS_D         \"tloc_engine_d\")

")
