#include "stdafx.h"
#include "Sprite.h"


namespace pacman {
namespace view {

Sprite::Sprite(SDL_Texture& tex,
			   int x, int y, int w, int h) : texture(tex)
{
	this->clip.x = x;
	this->clip.y = y;
	this->clip.w = w;
	this->clip.h = h;
}


Sprite::Sprite(SDL_Texture& tex) : texture(tex) {
	this->clip.x = 0;
	this->clip.y = 0;
	SDL_QueryTexture(&tex, NULL, NULL, &clip.w, &clip.h);
}


void Sprite::Render(SDL_Renderer& renderer, float x, float y, float scale) const {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = clip.w * scale;
	dst.h = clip.h * scale;

	SDL_RenderCopy(&renderer, &(this->texture), &(this->clip), &dst);
}

}
}