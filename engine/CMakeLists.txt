cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(tloc_engine VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

# These variables are usually set by the super build
if(NOT TLOC_SUPERBUILD_DIR)
  get_filename_component(TLOC_SUPERBUILD_DIR "${CMAKE_SOURCE_DIR}/../" REALPATH)
  set(CMAKE_INSTALL_PREFIX "${TLOC_SUPERBUILD_DIR}/install/tloc")
endif()

# Check to see super build was actually built
set(TLOC_SUPERBUILD_FILE "tl_superbuild_paths.cmake")
unset(TLOC_SUPERBUILD_PATHS CACHE) # without this, the variable is cached and could be wrong
find_path(TLOC_SUPERBUILD_PATHS ${TLOC_SUPERBUILD_FILE} HINTS "${TLOC_SUPERBUILD_DIR}/install/")

# Debug information
message(STATUS "###----------------------------------------------###")
message(STATUS "Super build dir: ${TLOC_SUPERBUILD_DIR}")

if(NOT TLOC_SUPERBUILD_PATHS)
  message(SEND_ERROR "Please first build the root level project: ${TLOC_SUPERBUILD_DIR}")
else()
  message(STATUS "Super build paths: ${TLOC_SUPERBUILD_PATHS}/${TLOC_SUPERBUILD_FILE}")
  include("${TLOC_SUPERBUILD_PATHS}/${TLOC_SUPERBUILD_FILE}")
endif()

message(STATUS "###----------------------------------------------###")

if(UNIX)
    include_directories("/usr/include/c++/${CMAKE_CXX_COMPILER_VERSION}")
endif()

# Add the engine src directory
add_subdirectory(src)

# Install commands
install(DIRECTORY "src/include/" DESTINATION "include/tloc")

include(./build_ycm_config.cmake)
