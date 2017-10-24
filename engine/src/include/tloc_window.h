#pragma once

#include "tloc_core.h"
#include "tloc_forward_decls.h"

namespace tloc {

  class window
  {
    public:

    public:
      window(engine_ptr a_engine);
      ~window();

      void create(int a_width, int a_height, const std::string& a_name);

    private:
      TLOC_POINTER_IMPL(window_impl) m_impl;
  };

};

#include "tloc_exception.h"
namespace tloc { namespace exceptions {

  TLOC_EXCEPTION_DEFINE(window_init);

};};
