#include "stdafx.h"
#include "texture/ITextureManager.h"
#include "texture/TextureManager.h"


namespace pacman {
namespace view {

std::unique_ptr<ITextureManager> ITextureManager::Construct(const IRenderer& renderer) {
	return std::make_unique<TextureManager>(renderer);
}

}
}