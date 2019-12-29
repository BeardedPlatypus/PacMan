#include "stdafx.h"
#include "sdl_util/IDispatcher.h"
#include "sdl_util/Dispatcher.h"


namespace pacman {
namespace view {
namespace sdl {

std::unique_ptr<IDispatcher> Construct() {
  return std::make_unique<Dispatcher>();
}

}
}
}