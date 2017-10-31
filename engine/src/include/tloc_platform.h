#pragma once

//-------------------------------------------------------------------------
// platform macros
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
// windows

#if defined(_WIN64)
# define TLOC_WIN64
#elif defined(WIN32) || defined(_WIN32)
# define TLOC_WIN32

#if defined (TLOC_WIN32) || defined (TLOC_WIN64)
# define TLOC_OS_WIN
#endif

//-------------------------------------------------------------------------
// apple

#elif defined(__APPLE__) && defined(__MACH__)
#	include <TargetConditionals.h>
#	if TARGET_IPHONE_SIMULATOR == 1
#		define TLOC_OS_IOS_SIMULATOR
#	elif TARGET_OS_IPHONE == 1
#		define TLOC_OS_IOS
#	elif TARGET_OS_MAC == 1
#		define TLOC_OS_MAC
#	endif

//-------------------------------------------------------------------------
// linux

#elif defined(__linux__)
# define TLOC_OS_LINUX

//-------------------------------------------------------------------------
// unsupported

#else
# warning "Unsupported Platform"
#endif

//-------------------------------------------------------------------------
// compiler macros

#if defined(_MSC_VER)
# define TLOC_COMPILER_VISUAL_CPP
#elif defined (__GNUC__)
# define TLOC_COMPILER_GCC
#elif defined (__clang__)
# define TLOC_COMPILER _CLANG
#endif
