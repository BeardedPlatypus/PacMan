#include "stdafx.h"
#include "renderer/RendererFactory.h"


namespace pacman {
namespace view {

RendererFactory::RendererFactory() { }


std::unique_ptr<IRenderer> RendererFactory::CreateRenderer(sdl::IDispatcher* p_dispatcher) const {
  return IRenderer::Construct();
}

}
}