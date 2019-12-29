#include "stdafx.h"
#include "renderer/IRenderer.h"

#include "renderer/Renderer.h"

namespace pacman {
namespace view {

std::unique_ptr<IRenderer> IRenderer::Construct() {
	return std::make_unique<Renderer>();
}

}
}