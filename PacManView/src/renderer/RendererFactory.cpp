#include "stdafx.h"
#include "renderer/RendererFactory.h"
#include "renderer/Renderer.h"


namespace pacman {
namespace view {

RendererFactory::RendererFactory() { }


std::unique_ptr<IRenderer> RendererFactory::CreateRenderer(sdl::IDispatcher* p_dispatcher) const {
  return std::make_unique<Renderer>(p_dispatcher);
}

}
}