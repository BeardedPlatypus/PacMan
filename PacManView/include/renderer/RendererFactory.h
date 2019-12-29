#pragma once

#include "renderer/IRendererFactory.h"

namespace pacman {
namespace view {

class RendererFactory final : public IRendererFactory {
public:
  RendererFactory();

  std::unique_ptr<IRenderer> CreateRenderer(sdl::IDispatcher* p_dispatcher) const final;
};

}
}
