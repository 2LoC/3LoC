#-----------------------------------------------
# Autogenerate tloc_autogen_engine.h

include(tloc_autogen.cmake)
set(INCLUDE_DIR "include")

#-----------------------------------------------
# Source files

set(TLOC_CORE
  ${INCLUDE_DIR}/tloc_common.h
  ${INCLUDE_DIR}/tloc_common.cpp

  ${INCLUDE_DIR}/tloc_core.h
  ${INCLUDE_DIR}/tloc_core.cpp

  ${INCLUDE_DIR}/tloc_defines.h

  ${INCLUDE_DIR}/tloc_exception.h
  ${INCLUDE_DIR}/tloc_exception.cpp

  ${INCLUDE_DIR}/tloc_engine.h
  ${INCLUDE_DIR}/tloc_engine.cpp

  ${INCLUDE_DIR}/tloc_event.h
  ${INCLUDE_DIR}/tloc_event.cpp

  ${INCLUDE_DIR}/tloc_forward_decls.h
  ${INCLUDE_DIR}/tloc_forward_decls.cpp

  ${INCLUDE_DIR}/tloc_no_optimize.h

  ${INCLUDE_DIR}/tloc_platform.h
  ${INCLUDE_DIR}/tloc_platform.cpp

  ${INCLUDE_DIR}/tloc_types.h

  ${INCLUDE_DIR}/tloc_utils.h
  ${INCLUDE_DIR}/tloc_utils.cpp
  )
set(TLOC_GFX
  ${INCLUDE_DIR}/tloc_window.h
  ${INCLUDE_DIR}/tloc_window.cpp

  ${INCLUDE_DIR}/tloc_window_events.h
  ${INCLUDE_DIR}/tloc_window_events.cpp
  )

#-----------------------------------------------
# Engine library

add_library(tloc_engine
  ${TLOC_CORE}
  ${TLOC_GFX}
  )

find_package(SDL2   CONFIG HINTS ${SDL_INSTALL_DIR} REQUIRED)
find_package(Eigen3 CONFIG HINTS ${EIGEN_INSTALL_DIR} REQUIRED)
find_package(fmt    CONFIG HINTS ${FMT_INSTALL_DIR} REQUIRED)

target_include_directories(tloc_engine
  PRIVATE
    ${SDL_INCLUDE_DIR}
    ${EIGEN_INCLUDE_DIR}
    ${FMT_INCLUDE_DIR}
    ${NANO_INCLUDE_DIR}
  )

message(STATUS ${NANO_INCLUDE_DIR})

target_link_libraries(tloc_engine
  PRIVATE
  ${SDL_LIBRARY_DIR}/libSDL2.so
  ${FMT_LIBRARY_DIR}/libfmt.a
  )

#-----------------------------------------------
# Testing

add_executable(window
  ${INCLUDE_DIR}/main.cpp
  )

target_link_libraries(window
  PRIVATE
    tloc_engine
  )

#-----------------------------------------------
# Organization

SOURCE_GROUP(core FILES ${TLOC_CORE})
SOURCE_GROUP(gfx  FILES ${TLOC_GFX})
