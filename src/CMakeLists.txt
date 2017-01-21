cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(tloc_engine VERSION 0.1 LANGUAGES CXX)

include(tloc_autogen.cmake)

set(TL_CORE
  engine/tl_defines.h
  )
set(TL_GFX
  engine/tl_window.h
  engine/tl_window.cpp
  )

add_library(tl_engine
  ${TL_CORE}
  ${TL_GFX}
  )

SOURCE_GROUP(core FILES ${TL_CORE})
SOURCE_GROUP(gfx  FILES ${TL_GFX})
