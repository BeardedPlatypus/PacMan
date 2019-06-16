#include "stdafx.h"
#include "manager/IViewManager.h"

#include "manager/ViewManager.h"


namespace pacman {
namespace view {

std::unique_ptr<IViewManager> IViewManager::construct() {
	std::unique_ptr<IViewCore> p_view_core = IViewCore::construct();
	std::unique_ptr<ITextureManager> p_texture_manager = ITextureManager::construct(p_view_core->getRenderer());
	std::unique_ptr<ISpriteManager> p_sprite_manager = ISpriteManager::construct(*p_texture_manager);

	return IViewManager::construct(std::move(p_view_core),
								   std::move(p_texture_manager),
								   std::move(p_sprite_manager));
}


std::unique_ptr<IViewManager> IViewManager::construct(std::unique_ptr<IViewCore> p_view_core,
													  std::unique_ptr<ITextureManager> p_texture_manager,
													  std::unique_ptr<ISpriteManager> p_sprite_manager) {
  return std::make_unique<ViewManager>(std::move(p_view_core),
                                       std::move(p_texture_manager),
                                       std::move(p_sprite_manager));
}

}
}