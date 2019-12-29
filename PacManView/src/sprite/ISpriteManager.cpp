#include "stdafx.h"
#include "sprite/ISpriteManager.h"
#include "sprite/SpriteManager.h"


namespace pacman {
namespace view {

std::unique_ptr<ISpriteManager> ISpriteManager::Construct(ITextureManager& texture_manager) {
  return std::make_unique<SpriteManager>(texture_manager);
}

}
}