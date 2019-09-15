#include "stdafx.h"
#include "sprite/Sprite.h"


namespace pacman {
namespace view {

Sprite::Sprite(const ITexture& tex,
			   int x, int y, int w, int h) : texture(tex)
{
	this->clip.x = x;
	this->clip.y = y;
	this->clip.w = w;
	this->clip.h = h;
}


Sprite::Sprite(const ITexture& tex) : 
	texture(tex)
{
	this->clip = this->texture.GetDimensions();
}



void Sprite::Render(IRenderer& renderer,
                    float x, 
                    float y, 
                    float scale, 
                    float angle,
                    bool flip_horizontally,
                    bool flip_vertically) const {
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	dst.w = clip.w * scale;
	dst.h = clip.h * scale;

	SDL_Rect clip_cp = this->GetClip();

	this->GetTexture().Render(renderer, 
                            clip_cp, 
                            dst, 
                            angle, 
                            flip_horizontally, 
                            flip_vertically);
}

}
}