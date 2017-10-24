#pragma once

#include <memory>

namespace tloc {

  class engine;
  using engine_ptr = std::shared_ptr<engine>;

  class window;
  using window_ptr = std::shared_ptr<window>;

  class myClass;
  using myclass_ptr = std::shared_ptr<myClass>;

};
