#include "tloc_window.h"
#include "tloc_engine.h"

int main()
{
  using namespace tloc;

  auto e = std::make_shared<engine>();
  auto w = std::make_shared<window>(e, window_params());

  while(true)
  {
    w->swap_buffers();
  }

  return 0;
}
