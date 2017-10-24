#include "tloc_engine.h"

#include <GLFW/glfw3.h>

namespace tloc {

  engine::engine()
  {
    if (!glfwInit())
    {
      throw exceptions::engine_init("Could not initialize GLFW");
    }
  }

  engine::~engine()
  {
    glfwTerminate();
  }

};
