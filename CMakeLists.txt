cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(tlocEngineSuper)

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

find_library(GLFW_LIB_D  glfw3_d ${GLFW_LIBRARY_DIR})
find_library(GLFW_LIB    glfw3   ${GLFW_LIBRARY_DIR})

###-------------------------------------------------###

ExternalProject_Add(eigen
  GIT_REPOSITORY "https://github.com/RLovelett/eigen.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/eigen"
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/eigen/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )
set(EIGEN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/eigen/include/eigen3")

###-------------------------------------------------###

ExternalProject_Add(bgfx
  GIT_REPOSITORY "https://github.com/JoshuaBrookover/bgfx.cmake.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/bgfx"
  CMAKE_ARGS -DBGFX_BUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/bgfx/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(BGFX_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/bgfx/include/")
set(BGFX_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/install/bgfx/lib/")

find_library(BGFX_LIB_D  bgfx_d ${BGFX_LIBRARY_DIR})
find_library(BGFX_LIB    bgfx   ${BGFX_LIBRARY_DIR})

###-------------------------------------------------###

include(ExternalProject)
ExternalProject_Add(spdlog
  GIT_REPOSITORY "https://github.com/gabime/spdlog.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/spdlog"
  CMAKE_ARGS -DBUILD_TESTING=OFF -DSPDLOG_BUILD_TESTING=OFF -DSPDLOG_BUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/spdlog/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(SPDLOG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/spdlog/include/")

###-------------------------------------------------###

ExternalProject_Add(catch
  GIT_REPOSITORY "https://github.com/samaursa/catch.git" 
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/catch"
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/catch/

  TEST_COMMAND ""
  )

set(CATCH_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/catch/include/")

###-------------------------------------------------###

ExternalProject_Add(tloc
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/engine/"

  CMAKE_ARGS -DTLOC_SUPERBUILD_DIR=${CMAKE_SOURCE_DIR} -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/tloc/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(TLOC_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/tloc/include/")
set(TLOC_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/install/tloc/lib/")

###-------------------------------------------------###

include_directories(${GLFW_INCLUDE_DIR})
include_directories(${EIGEN_INCLUDE_DIR})
include_directories(${BGFX_INCLUDE_DIR})
include_directories(${SPDLOG_INCLUDE_DIR})
include_directories(${CATCH_INCLUDE_DIR})
