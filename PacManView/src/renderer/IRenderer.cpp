#include "stdafx.h"
#include "renderer/IRenderer.h"

#include "renderer/Renderer.h"

namespace pacman {
namespace view {

std::unique_ptr<IRenderer> IRenderer::construct() {
	return std::make_unique<Renderer>();
}

}
}