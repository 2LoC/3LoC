#-----------------------------------------------
# Autogenerate tloc_engine.h

include(tloc_autogen.cmake)
set(INCLUDE_DIR "include")

#-----------------------------------------------
# Include directories

include_directories(${GLFW_INCLUDE_DIR})
include_directories(${EIGEN_INCLUDE_DIR})
include_directories(${BGFX_INCLUDE_DIR})
include_directories(${SPDLOG_INCLUDE_DIR})

#-----------------------------------------------
# Source files

set(TLOC_CORE
  ${INCLUDE_DIR}/tloc_defines.h
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

#-----------------------------------------------
# Organization

SOURCE_GROUP(core FILES ${TLOC_CORE})
SOURCE_GROUP(gfx  FILES ${TLOC_GFX})
