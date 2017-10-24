set(TLOC_AUTO_ENGINE_H "tloc_auto_engine.h")
file(REMOVE "include/${TLOC_AUTO_ENGINE_H}")
file(GLOB_RECURSE TLOC_HEADERS RELATIVE ${CMAKE_SOURCE_DIR} *.h)

file (WRITE "include/${TLOC_AUTO_ENGINE_H}"
"#pragma once

// Auto generated file, DO NOT overwrite
"
)

MESSAGE(STATUS "All headers: ${TLOC_HEADERS}")

foreach(HEADER ${TLOC_HEADERS})
  file(APPEND "include/${TLOC_AUTO_ENGINE_H}"
    "#include \"${HEADER}\"\n")
endforeach(HEADER)
