cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(tlocEngine VERSION 0.1 LANGUAGES CXX)

enable_testing()
#add_subdirectory(src)

include(ExternalProject)
ExternalProject_Add(glfw
  GIT_REPOSITORY "https://github.com/glfw/glfw.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/glfw"
  CMAKE_ARGS -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/glfw/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/glfw/include/")
set(GLFW_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/install/glfw/lib/")

include(ExternalProject)
ExternalProject_Add(eigen
  GIT_REPOSITORY "https://github.com/RLovelett/eigen.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/eigen"
  CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/eigen/ -DCMAKE_DEBUG_POSTFIX=_d

  TEST_COMMAND ""
  )

set(EIGEN_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/install/eigen/include/eigen3")

find_library(GLFW_LIB_D  glfw3_d ${GLFW_LIBRARY_DIR})
find_library(GLFW_LIB    glfw3   ${GLFW_LIBRARY_DIR})
find_package(VULKAN)

include_directories(${GLFW_INCLUDE_DIR})
include_directories(${EIGEN_INCLUDE_DIR})
include_directories(${Vulkan_INCLUDE_DIR})

add_executable(vk_test
  src/vulkan_test.cpp
  )
target_link_libraries(vk_test debug ${GLFW_LIB_D} optimized ${GLFW_LIB})
target_link_libraries(vk_test ${Vulkan_LIBRARY})

# CMake has a bug where 32 bit Vulkan library is simply not picked up.
# Not sure why this is - I have tried completely removing the lines for
# the Bin folder so that only Bin32 is detected and STILL it selects Bin.
# I debugged it with messages and somehow it is being set to Bin even though
# the correct ELIF is being hit.
# Quite frustrating.
#
# message(STATUS ${Vulkan_LIBRARY})


add_dependencies(vk_test glfw)
add_dependencies(vk_test eigen)
