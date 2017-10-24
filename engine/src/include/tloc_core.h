#pragma once

#include <memory>

namespace tloc
{
#define TLOC_POINTER_IMPL(_name_)\
  class _name_;\
  std::unique_ptr<_name_>
};
