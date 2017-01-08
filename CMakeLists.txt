cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(tlocEngine VERSION 0.1 LANGUAGES CXX)

enable_testing()
#add_subdirectory(src)

include(ExternalProject)
ExternalProject_Add(glfw
  GIT_REPOSITORY "https://github.com/glfw/glfw.git"
  GIT_TAG "master"

  SOURCE_DIR "${CMAKE_SOURCE_DIR}/dep/glfw"
  CMAKE_ARGS -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_BUILD_EXAMPLES=OFF -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/install/glfw/ -DCMAKE_DEBUG_POSTFIX=_debug

  TEST_COMMAND ""
  )

set(gflw_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/install/glfw/include/")
set(glfw_LIBRARIES "${CMAKE_SOURCE_DIR}/install/glfw/lib/")

include_directories(${glfw_INCLUDE_DIRS})
link_directories(${gflw_LIBRARIES})

add_executable(vk_test
  src/vulkan_test.cpp
  )
