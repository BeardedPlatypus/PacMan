#include "stdafx.h"
#include "texture/Texture.h"


namespace pacman {
namespace view {

Texture::Texture(std::unique_ptr<sdl::IResourceWrapper<SDL_Texture>> p_tex,
	               sdl::IDispatcher* p_dispatcher) : 
	  _p_tex_resource(std::move(p_tex)),
    _p_dispatcher(p_dispatcher) { 
}


SDL_Rect Texture::GetDimensions() const {
	SDL_Rect result;
	result.x = 0;
	result.y = 0;

	this->_p_dispatcher->QueryTexture(this->_p_tex_resource->GetResource(),
					                          NULL,
					                          NULL,
					                          &result.w,
					                          &result.h);
	return result;
}



void Texture::Render(IRenderer& renderer,
					           SDL_Rect& clip,
					           SDL_Rect& dst, 
                     float angle,
                     bool flip_horizontally, 
                     bool flip_vertically) const {
	   renderer.RenderCopy(this->_p_tex_resource->GetResource(),
                         &clip,
						             &dst, 
                         angle, 
                         flip_horizontally, 
                         flip_vertically);
}


}
}