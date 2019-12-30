#pragma once

#include "texture/ITexture.h"
#include "sdl_util/IResourceWrapper.h"
#include "sdl_util/IDispatcher.h"


namespace pacman {
namespace view {

class Texture final : public ITexture {
public:	
	Texture(std::unique_ptr<sdl::IResourceWrapper<SDL_Texture>> p_tex, 
		      sdl::IDispatcher* p_dispatcher);
	
	SDL_Rect GetDimensions() const final;
	
  void Render(IRenderer& renderer,
				      SDL_Rect& clip,
				      SDL_Rect& dst,
              float angle, 
              bool flip_horizontally,
              bool flip_vertically) const final;

private:		
	std::unique_ptr<sdl::IResourceWrapper<SDL_Texture>> _p_tex_resource;
	sdl::IDispatcher* _p_dispatcher;
};

}
}
