#pragma once

#include "tloc_core.h"

namespace tloc {

  class engine
  {
    public:
      engine();
      ~engine();
  };

  TLOC_TYPEDEF_SHARED_PTR(engine);
  TLOC_TYPEDEF_UNIQUE_PTR(engine);
};

#include "tloc_exception.h"
namespace tloc {  namespace exceptions {

  TLOC_EXCEPTION_DEFINE(engine_init);

};};
