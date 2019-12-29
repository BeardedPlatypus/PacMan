#include "pch.h"
#include "IViewAPI.h"

#include "ViewAPI.h"


namespace pacman {
namespace view {

std::unique_ptr<IViewAPI> IViewAPI::Construct() {
	std::unique_ptr<IViewCore> p_view_core = 
    IViewCore::Construct();
	std::unique_ptr<ITextureManager> p_texture_manager = 
    ITextureManager::Construct(p_view_core->GetRenderer());
	std::unique_ptr<ISpriteManager> p_sprite_manager = 
    ISpriteManager::Construct(*p_texture_manager);

  return std::make_unique<ViewAPI>(std::move(p_view_core),
                                   std::move(p_texture_manager),
                                   std::move(p_sprite_manager));
}

}
}
