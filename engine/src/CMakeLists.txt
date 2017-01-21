include(tloc_autogen.cmake)
set(INCLUDE_DIR "include")

set(TL_CORE
  ${INCLUDE_DIR}/tl_defines.h
  )
set(TL_GFX
  ${INCLUDE_DIR}/tl_window.h
  ${INCLUDE_DIR}/tl_window.cpp
  )

add_library(tl_engine
  ${TL_CORE}
  ${TL_GFX}
  )

SOURCE_GROUP(core FILES ${TL_CORE})
SOURCE_GROUP(gfx  FILES ${TL_GFX})
