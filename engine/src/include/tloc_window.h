#pragma once

#include "tloc_core.h"
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

			TLOC_DECL_PARAM_VAR(int, xPos, m_xPos);
			TLOC_DECL_PARAM_VAR(int, yPos, m_yPos);

			TLOC_DECL_PARAM_VAR_REF(std::string, name, m_name);
  };

	//-------------------------------------------------------------------------

  class window
  {
		public:
      using id = tl_uint;

    public:
      window(const window_params& a_params);
      ~window();

      void make_context_current();
			void swap_buffers();
      id   get_id() const;

    private:
      TLOC_POINTER_IMPL(window_impl) m_impl;
  };

	TLOC_TYPEDEF_SHARED_PTR(window);

};

#include "tloc_exception.h"
namespace tloc { namespace exceptions {

  TLOC_EXCEPTION_DEFINE(window_initialization);

};};
