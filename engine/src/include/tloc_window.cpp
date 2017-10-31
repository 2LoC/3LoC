#include "tloc_window.h"

#include <string>
#include <GLFW/glfw3.h>

#include "tloc_engine.h"

namespace tloc
{
	//-------------------------------------------------------------------------

  window_params::
    window_params()
    : m_width(640)
    , m_height(480)
    , m_name("2LoC Engine")
    { }

	//-------------------------------------------------------------------------

  struct glfw_window_deleter
  {
    void operator()(GLFWwindow* a_window)
    {
      glfwDestroyWindow(a_window);
    }
  };

	//-------------------------------------------------------------------------

  class window::window_impl
  {
    public:
      using glfw_window_ptr = std::unique_ptr<GLFWwindow, glfw_window_deleter>;

    public:
      window_impl()
      { }

      bool is_window_initialized() const
      {
        return m_window != nullptr;
      }

    public:
      engine_ptr      m_engine;
      glfw_window_ptr m_window;
  };

	//-------------------------------------------------------------------------

  window::
    window(engine_ptr a_engine, const window_params& a_params)
    : m_impl(std::make_unique<window_impl>())
    {
      m_impl->m_engine = a_engine;

      auto window = glfwCreateWindow(a_params.width(), a_params.height(),
                                     a_params.name().c_str(), nullptr, nullptr);
      if (!window)
      {
        throw exceptions::window_initialization
          ("Could not create window using glfwCreateWindow");
      }

      m_impl->m_window = window_impl::glfw_window_ptr(window);
      make_context_current();
    }

  window::
    ~window()
    { }

  void
    window::
    make_context_current()
    {
      glfwMakeContextCurrent(m_impl->m_window.get());
    }

  void
    window::
    swap_buffers()
    {
      glfwSwapBuffers(m_impl->m_window.get());
    }

  void
    window::
    poll_events()
    {
      glfwPollEvents();
    }
};
