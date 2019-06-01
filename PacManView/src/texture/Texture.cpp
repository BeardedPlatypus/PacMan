#include "stdafx.h"
#include "texture/Texture.h"


namespace pacman {
namespace view {

Texture::Texture(SDL_Texture* p_tex) {
	this->p_tex = 
		std::unique_ptr<SDL_Texture, SDL_Destructor<SDL_Texture>>(p_tex);
}


SDL_Rect Texture::GetDimensions() const {
	// TODO: change this to something more convenient.
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
					 SDL_Rect& dst) const {
	   renderer.RenderCopy(this->p_tex.get(), 
						   &clip,
						   &dst);
}


}
}