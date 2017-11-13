#pragma once

#include "tloc_utils.h"
#include "tloc_core.h"

namespace tloc
{
	//-------------------------------------------------------------------------

  enum class window_events
  {
    shown = 0,
    hidden,
    exposed,
    moved,
    resized,
    size_changed,
    minimized,
    maximized,
    restored,
    mouse_enter,
    mouse_leave,
    keyboard_focus_gained,
    keyboard_focus_lost,
    close,
    take_focus,
    hit_test,

    count
  };

	//-------------------------------------------------------------------------

  class window_id
  {
    public:
      using this_type = window_id;

    public:
      TLOC_DECL_PARAM_VAR(tl_uint, id, m_id);
  };

	//-------------------------------------------------------------------------

  class window_event
  {
    public:
      using this_type = window_event;

    public:
      TLOC_DECL_PARAM_VAR(window_id, id, m_id);
  };

};
