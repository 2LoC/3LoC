#include "tloc_window.h"
#include "tloc_engine.h"

int main()
{
  using namespace tloc;

  auto w = std::make_shared<window>(window_params());

  while(true)
  {
    w->swap_buffers();
  }

  return 0;
}
