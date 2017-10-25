#pragma once

// Include this to disabled optimizations for a particular source files in
// release mode. It should be added to *.cpp files for minimal impact on
// overall program optimizations.

# ifdef _MSC_VER
#   pragma warning(disable:4748)
#   pragma optimize("", off)
#   define _SECURE_SCL 0
#   pragma inline_depth( 0 )
#   pragma inline_recursion( off )
#   pragma auto_inline( off )
# endif
