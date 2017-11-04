#pragma once

#include "tloc_forward_decls.h"
#include <nano/nano_function.hpp>

namespace tloc
{
	//-------------------------------------------------------------------------

  enum class events
  {
    window,
    keyboard,
    mouse_motion,
    mouse_button,
    mouse_wheel,
    joy_axis,
    joy_ball,
    joy_hat,
    joy_button,
    joy_device,
    controller_axis,
    controller_button,
    controller_device,
    quit,
  };

	//-------------------------------------------------------------------------

  class event
  {
    public:
      event(engine_ptr a_engine);
  };
};
