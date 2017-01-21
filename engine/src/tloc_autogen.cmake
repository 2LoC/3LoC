file(REMOVE "include/tl_engine.h")
file(GLOB_RECURSE TLOC_HEADERS RELATIVE ${CMAKE_SOURCE_DIR} *.h)

file (WRITE "include/tl_engine.h"
"#pragma once

// Auto generated file, DO NOT overwrite
"
)

MESSAGE(STATUS "All headers: ${TLOC_HEADERS}")

foreach(HEADER ${TLOC_HEADERS})
  file(APPEND "include/tl_engine.h"
    "#include \"${HEADER}\"\n")
endforeach(HEADER)
