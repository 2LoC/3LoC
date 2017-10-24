#pragma once

#include "tloc_core.h"

namespace tloc {

  class engine
  {
    public:
      engine();
      ~engine();
  };
};

#include "tloc_exception.h"
namespace tloc {  namespace exceptions {

  TLOC_EXCEPTION_DEFINE(engine_init);

};};
