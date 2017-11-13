#include "tloc_window.h"

#include <string>
#include <functional>

#include <SDL2/SDL.h>
#include <fmt/format.h>

namespace tloc
{
	//-------------------------------------------------------------------------

  window_params::
    window_params()
    : m_width(640)
    , m_height(480)
    , m_xPos(0)
    , m_yPos(0)
    , m_name("2LoC Engine")
    { }

	//-------------------------------------------------------------------------

  template <typename F>
  struct custom_deleter
  {
    template <typename T>
    void operator()(T* a_ptr)
    { std::function<F>()(a_ptr); }
  };

	//-------------------------------------------------------------------------

  struct sdl_video_subsystem
  {
    public:
      sdl_video_subsystem()
      {
        if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
        {
          throw exceptions::window_initialization
            (fmt::format("SDL Error: {0}", SDL_GetError()).c_str());
        }
      }

      ~sdl_video_subsystem()
      { SDL_QuitSubSystem(SDL_INIT_VIDEO); }
  };

	//-------------------------------------------------------------------------

  class window::window_impl
  {
    public:
      using window_ptr  = std::unique_ptr
        <SDL_Window, custom_deleter<decltype(SDL_DestroyWindow)>>;
      using context_ptr = std::unique_ptr
        <void, custom_deleter<decltype(SDL_GL_DeleteContext)>>;

    public:
      window_impl()
      { }

      bool is_window_initialized() const
      { return m_window != nullptr; }

      SDL_Window* get_window_rptr() { return m_window.get(); }
      SDL_GLContext get_context_rptr() { return m_context.get(); }

    public:
      window_ptr    m_window;
      context_ptr   m_context;
  };

	//-------------------------------------------------------------------------

  window::
    window(const window_params& a_params)
    : m_impl(std::make_unique<window_impl>())
    {
      auto window = SDL_CreateWindow(a_params.name().c_str(),
                                     a_params.xPos(), a_params.yPos(),
                                     a_params.width(), a_params.height(),
                                     SDL_WINDOW_OPENGL);
      if (!window)
      {
        throw exceptions::window_initialization
          (fmt::format("SDL Error: {0}", SDL_GetError()).c_str());
      }

      auto context = SDL_GL_CreateContext(window);

      if (!context)
      {
        throw exceptions::window_initialization
          (fmt::format("SDL Error: {0}", SDL_GetError()).c_str());
      }

      m_impl->m_window = window_impl::window_ptr(window);
      m_impl->m_context = window_impl::context_ptr(context);
      make_context_current();
    }

  window::
    ~window()
    { }

  void
    window::
    make_context_current()
    {
      SDL_GL_MakeCurrent(m_impl->get_window_rptr(), m_impl->get_context_rptr());
    }

  void
    window::
    swap_buffers()
    {
      SDL_GL_SwapWindow(m_impl->get_window_rptr());
    }

  window::id
    window::
    get_id() const
    {
      return SDL_GetWindowID(m_impl->get_window_rptr());
    }
};
