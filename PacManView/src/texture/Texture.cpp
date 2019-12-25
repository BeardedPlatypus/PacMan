#include "stdafx.h"
#include "texture/Texture.h"


namespace pacman {
namespace view {

Texture::Texture(SDL_Texture* p_tex) : 
	  p_tex(std::unique_ptr<SDL_Texture, SDL_Destructor<SDL_Texture>>(p_tex)) { }


SDL_Rect Texture::GetDimensions() const {
	SDL_Rect result;
	result.x = 0;
	result.y = 0;

	SDL_QueryTexture(this->p_tex.get(),
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
	   renderer.RenderCopy(this->p_tex.get(), 
                         &clip,
						             &dst, 
                         angle, 
                         flip_horizontally, 
                         flip_vertically);
}


}
}