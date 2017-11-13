cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(tloc_engine_superbuild)

enable_testing()
include(ExternalProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

###-------------------------------------------------###

ExternalProject_Add(sdl
  GIT_REPOSITORY "https://github.com/spurious/SDL-mirror"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/sdl"
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/sdl/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(SDL_INSTALL_DIR "${CMAKE_SOURCE_DIR}/install/sdl/")
set(SDL_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/sdl/include/")
set(SDL_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/install/sdl/lib/")

###-------------------------------------------------###

ExternalProject_Add(eigen
  GIT_REPOSITORY "https://github.com/RLovelett/eigen.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/eigen"
  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/eigen/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(EIGEN_INSTALL_DIR "${CMAKE_SOURCE_DIR}/install/eigen/")
set(EIGEN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/eigen/include/eigen3")

###-------------------------------------------------###

ExternalProject_Add(bgfx
  GIT_REPOSITORY "https://github.com/2LoC/dep_bgfx.cmake.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/bgfx"
  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DBGFX_BUILD_EXAMPLES=OFF -DBGFX_BUILD_TOOLS=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/bgfx/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(BGFX_INSTALL_DIR "${CMAKE_SOURCE_DIR}/install/bgfx/")
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

set(SPDLOG_INSTALL_DIR "${CMAKE_SOURCE_DIR}/install/spdlog/")
#set(SPDLOG_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/spdlog/include/")

###-------------------------------------------------###

ExternalProject_Add(catch
  GIT_REPOSITORY "https://github.com/2LoC/dep_catch.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/catch"
  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/catch/ -H. -BBuild -Wdev

  TEST_COMMAND ""
  )

set(CATCH_INSTALL_DIR "${CMAKE_SOURCE_DIR}/install/catch/")
set(CATCH_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/catch/include/")

###-------------------------------------------------###

ExternalProject_Add(fmt
  GIT_REPOSITORY "https://github.com/fmtlib/fmt"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/fmt"
  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/fmt/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(FMT_INSTALL_DIR "${CMAKE_SOURCE_DIR}/install/fmt/")
set(FMT_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/fmt/include/")
set(FMT_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/install/fmt/lib/")

###-------------------------------------------------###

ExternalProject_Add(nano
  GIT_REPOSITORY "https://github.com/2LoC/dep_nano-signal-slot"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/nano"
  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/nano/

  TEST_COMMAND ""
  )

set(NANO_INSTALL_DIR "${CMAKE_SOURCE_DIR}/install/nano/")
set(NANO_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/nano/include/")

###-------------------------------------------------###

ExternalProject_Add(tloc
  SOURCE_DIR "${CMAKE_SOURCE_DIR}/engine/"

  CMAKE_ARGS -DCMAKE_CXX_COMPILER:FILEPATH=${CMAKE_CXX_COMPILER} -DTLOC_SUPERBUILD_DIR=${CMAKE_SOURCE_DIR} -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/tloc/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(TLOC_INSTALL_DIR "${CMAKE_SOURCE_DIR}/install/tloc/")
set(TLOC_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/tloc/include/")
set(TLOC_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/install/tloc/lib/")

###-------------------------------------------------###
### Dependencies

add_dependencies(tloc sdl)
add_dependencies(tloc eigen)
add_dependencies(tloc bgfx)
add_dependencies(tloc spdlog)
add_dependencies(tloc catch)
add_dependencies(tloc nano)
add_dependencies(tloc fmt)

###-------------------------------------------------###
### Auto generate a helper file for use with

FILE(WRITE "install/tl_superbuild_paths.cmake"
"\#\#\# ---------------------------------------------
\#\#\# This is auto-generated to facilitate defining project variables

\#\#\# ---------------------------------------------
\#\#\# Install directories

set(SDL_INSTALL_DIR           \"${SDL_INSTALL_DIR}\")
set(EIGEN_INSTALL_DIR         \"${EIGEN_INSTALL_DIR}\")
set(BGFX_INSTALL_DIR          \"${BGFX_INSTALL_DIR}\")
set(SPDLOG_INSTALL_DIR        \"${SPDLOG_INSTALL_DIR}\")
set(CATCH_INSTALL_DIR         \"${CATCH_INSTALL_DIR}\")
set(FMT_INSTALL_DIR           \"${FMT_INSTALL_DIR}\")
set(NANO_INSTALL_DIR          \"${NANO_INSTALL_DIR}\")
set(TLOC_INSTALL_DIR          \"${TLOC_INSTALL_DIR}\")

\#\#\# ---------------------------------------------
\#\#\# Include directories

set(SDL_INCLUDE_DIR           \"${SDL_INCLUDE_DIR}\")
set(EIGEN_INCLUDE_DIR         \"${EIGEN_INCLUDE_DIR}\")
set(BGFX_INCLUDE_DIR          \"${BGFX_INCLUDE_DIR}\")
set(SPDLOG_INCLUDE_DIR        \"${SPDLOG_INCLUDE_DIR}\")
set(CATCH_INCLUDE_DIR         \"${CATCH_INCLUDE_DIR}\")
set(FMT_INCLUDE_DIR           \"${FMT_INCLUDE_DIR}\")
set(NANO_INCLUDE_DIR          \"${NANO_INCLUDE_DIR}\")
set(TLOC_INCLUDE_DIR          \"${TLOC_INCLUDE_DIR}\")

\#\#\# ---------------------------------------------
\#\#\# Library directories

set(SDL_LIBRARY_DIR     \"${SDL_LIBRARY_DIR}\")
set(BGFX_LIBRARY_DIR    \"${BGFX_LIBRARY_DIR}\")
set(FMT_LIBRARY_DIR     \"${FMT_LIBRARY_DIR}\")
set(TLOC_LIBRARY_DIR    \"${TLOC_LIBRARY_DIR}\")

\#\#\# ---------------------------------------------
\#\#\# Libraries

set(TLOC_LIBS           \"tloc_engine\")
set(TLOC_LIBS_D         \"tloc_engine_d\")

")
