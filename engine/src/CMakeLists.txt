#-----------------------------------------------
# Autogenerate tloc_autogen_engine.h

include(tloc_autogen.cmake)
set(INCLUDE_DIR "include")

#-----------------------------------------------
# Include directories

include_directories(${GLFW_INCLUDE_DIR})
include_directories(${EIGEN_INCLUDE_DIR})
include_directories(${BGFX_INCLUDE_DIR})
include_directories(${SPDLOG_INCLUDE_DIR})
include_directories(${CATCH_INCLUDE_DIR})

message(STATUS "GLFW LIBRARY: ${GLFW_LIBRARY_DIR}")
link_directories(${GLFW_LIBRARY_DIR})
link_directories(${BGFX_LIBRARY_DIR})
link_directories(${TLOC_LIBRARY_DIR})

#-----------------------------------------------
# Source files

set(TLOC_CORE
  ${INCLUDE_DIR}/tloc_defines.h
  ${INCLUDE_DIR}/tloc_common.h
  ${INCLUDE_DIR}/tloc_common.cpp
  ${INCLUDE_DIR}/tloc_core.h
  ${INCLUDE_DIR}/tloc_core.cpp
  ${INCLUDE_DIR}/tloc_exception.h
  ${INCLUDE_DIR}/tloc_exception.cpp
  ${INCLUDE_DIR}/tloc_engine.h
  ${INCLUDE_DIR}/tloc_engine.cpp
  ${INCLUDE_DIR}/tloc_forward_decls.h
  ${INCLUDE_DIR}/tloc_forward_decls.cpp
  )
set(TLOC_GFX
  ${INCLUDE_DIR}/tloc_window.h
  ${INCLUDE_DIR}/tloc_window.cpp
  )

#-----------------------------------------------
# Engine library

add_library(tloc_engine
  ${TLOC_CORE}
  ${TLOC_GFX}
  )

add_executable(glfw_window
  ${INCLUDE_DIR}/main.cpp
  )
target_link_libraries(glfw_window libglfw3.a pthread dl GLU GL rt Xrandr Xxf86vm Xi Xinerama X11)

#-----------------------------------------------
# Organization

SOURCE_GROUP(core FILES ${TLOC_CORE})
SOURCE_GROUP(gfx  FILES ${TLOC_GFX})
