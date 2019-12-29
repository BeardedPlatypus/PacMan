#pragma once

#include <memory>
#include "renderer/IRenderer.h"
#include "sdl_util/IDispatcher.h"

namespace pacman {
namespace view {

class IRendererFactory {
public:
  virtual std::unique_ptr<IRenderer> CreateRenderer(sdl::IDispatcher* p_dispatcher) const = 0;
};

}
}
