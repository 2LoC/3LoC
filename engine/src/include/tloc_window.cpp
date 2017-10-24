#include "tloc_window.h"

#include <string>
#include <GLFW/glfw3.h>

#include "tloc_engine.h"

namespace tloc
{
  struct glfw_window_deleter
  {
    void operator()(GLFWwindow* a_window)
    {
      glfwDestroyWindow(a_window);
    }
  };

  class window::window_impl
  {
    public:
      using glfw_window_ptr = std::unique_ptr<GLFWwindow, glfw_window_deleter>;

    public:
      window_impl()
      { }

    public:
      glfw_window_ptr m_window;
      engine_ptr      m_engine;
  };

  window::window(engine_ptr a_engine)
    : m_impl(std::make_unique<window_impl>())
  {
    m_impl->m_engine = a_engine;
  }

  window::~window() { }

  void
    window::create(int a_width, int a_height, const std::string& a_name)
  {
  }
};
