#pragma once

#include "tloc_core.h"
#include "tloc_forward_decls.h"
#include "tloc_utils.h"

namespace tloc {

	//-------------------------------------------------------------------------

  class window_params
  {
    public:
      using this_type = window_params;

    public:
      window_params();

			TLOC_DECL_PARAM_VAR(int, width, m_width);
			TLOC_DECL_PARAM_VAR(int, height, m_height);
			TLOC_DECL_PARAM_VAR_REF(std::string, name, m_name);
  };

	//-------------------------------------------------------------------------

  class window
  {
    public:

    public:
      window(engine_ptr a_engine, const window_params& a_params);
      ~window();

      void make_context_current();
			void swap_buffers();
			void poll_events();

    private:
      TLOC_POINTER_IMPL(window_impl) m_impl;
  };

	TLOC_TYPEDEF_SHARED_PTR(window);
	TLOC_TYPEDEF_UNIQUE_PTR(window);

};

#include "tloc_exception.h"
namespace tloc { namespace exceptions {

  TLOC_EXCEPTION_DEFINE(window_initialization);
  TLOC_EXCEPTION_DEFINE(window_not_initialized);

};};
