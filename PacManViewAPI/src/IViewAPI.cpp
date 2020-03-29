#include "pch.h"
#include "IViewAPI.h"

#include "ViewAPI.h"
#include "sdl_util/IDispatcher.h"
#include "renderer/RendererFactory.h"

namespace pacman {
namespace view {

std::unique_ptr<IViewAPI> IViewAPI::Construct() {
  auto renderer_factory = RendererFactory();

	std::unique_ptr<IViewCore> p_view_core = 
    IViewCore::Construct(sdl::IDispatcher::Construct(), renderer_factory);
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
