#pragma once

#include <stdexcept>

namespace tloc { namespace exceptions {

  // Macro for easily defining exception ctors
#define TLOC_EXCEPTION_CTORS(_class_name_)\
  explicit _class_name_(const std::string& what_arg)\
  : base_type(what_arg) { }\
  explicit _class_name_(const char* what_arg)\
  : base_type(what_arg) { }

  // Macro for easily defining exceptions
#define TLOC_EXCEPTION_DEFINE(_name_)\
  class _name_ : public exception \
  {\
    public:\
      using base_type = exception;\
      TLOC_EXCEPTION_CTORS(_name_)\
  }

  class exception : public std::runtime_error
  {
    public:
      using base_type = std::runtime_error;

      TLOC_EXCEPTION_CTORS(exception);
  };

};};
