#include "tloc_engine.h"

#include <SDL2/SDL.h>

namespace tloc {

  engine::engine()
  {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    { throw exceptions::engine_init("Could not initialize SDL Video"); }
  }

  engine::~engine()
  {
    SDL_Quit();
  }

};
